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
	
	cRegArchModel myModelArmaCp(myModelArma) ;
	cout << "Copie du modele : " ;
	myModelArmaCp.Print() ;

	// Observations
	uint myNData = 10 ;
	cRegArchValue myGivenValue(myNData) ;
	for(uint t=0; t < myGivenValue.mYt.GetSize(); t++)
	{
		myGivenValue.mYt[t] = t;
	}
	cDVector myMeans(myNData);	
        // Moyennes conditionnelles

	for(uint t=0; t < myGivenValue.mYt.GetSize(); t++)
	{
		myMeans[t] = myCondMeanArma.ComputeMean(t, myGivenValue);
		myGivenValue.mUt[t] = myGivenValue.mYt[t] - myMeans[t];
		myGivenValue.mMt[t] = myMeans[t];
	}
	cout << "Moyennes conditionnelles ARMA pur gaussien: " << endl ;
	myMeans.Print();

	return 0 ;


}
