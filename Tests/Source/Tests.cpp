// Test.cpp : definit le point d'entree pour l'application console.
//

#include "StdAfxTestCPlusPlus.h"

using namespace ErrorNameSpace;
using namespace VectorAndMatrixNameSpace;
using namespace RegArchLib ;

#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, char* argv[])
#endif //WIN32
{
	cout.precision(12) ; 

	/*********
	 * ARMA pur
	 *******/
	cConst myConst(0.1);
	
	cAr	myAr(2) ;
	
	myAr.Set(.8, 0) ;
	myAr.Set(-.2, 1) ;
	myAr.Print() ;
	
	cMa myMa(2) ;
	myMa.Set(0.8, 0) ;
	myMa.Set(0.6, 1) ;
	
	cCondMean myCondMeanArma ;
	myCondMeanArma.SetOneMean(0, myConst) ;
	myCondMeanArma.SetOneMean(1, myAr) ;
	myCondMeanArma.SetOneMean(2, myMa) ;

	cConstCondVar myConstVar(1.0) ;

	cCondVar myCondVar ;
	myCondVar.SetOneVar(0, myConstVar) ;
	
	cNormResiduals myNormResid ;

	cRegArchModel myModelArma ;
	myModelArma.SetMean(myCondMeanArma) ;
	myModelArma.SetVar(myCondVar) ;
	myModelArma.SetResid(myNormResid) ;
	cout << "Modele : " ;
	myModelArma.Print() ;
	

	// Simulation
	uint myNSample = 10;
	cRegArchValue mySimulData;
	cDVector mySimulVector(myNSample);
	RegArchLib::RegArchSimul(myNSample, myModelArma, mySimulData) ;
	cout << "Valeurs simulees : " << endl ;
	mySimulVector = mySimulData.mYt;
	mySimulVector.Print();


	/*********
	 * ARMA pur gaussien : gradient
	 *******/
	cout << "Modele : " ;
	myModelArma.Print() ;

	uint myNParam = myModelArma.GetNParam() ;
	cDVector myGrad0(myNParam) ;
	cDVector myGrad1(myNParam) ;

	// approximation par differences finies
	NumericRegArchGradLLH(myModelArma, mySimulData, myGrad0, 1e-6) ;
	cout << "Grad numerique" << endl << myGrad0 ;
	cRegArchGradient myGradData(&myModelArma) ;
	RegArchGradLLH(myModelArma, mySimulData, myGrad1) ;
	cout << "Grad calcule" << endl << myGrad1 ;
	cDVector myDiff = myGrad0 - myGrad1 ;
	for (register uint i = 0 ; i < myNParam ; i++)
        {
		if (myGrad0[i] != 0)
                {
                    myDiff[i] /= myGrad0[i] ;
                }
                else
                {
                    if (myGrad0[i] == 0)
                        myDiff[i] = 0.0;
                    else
                        myDiff[i] = nanf("");
                }
        }
	cout << "erreur relative (%)" << endl << 100*myDiff ;


	return 0 ;


}
