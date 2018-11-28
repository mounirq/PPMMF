// Test.cpp : definit le point d'entree pour l'application console.
//

#include "StdAfxTestCPlusPlus.h"
#include "StdAfxRegArchLib.h"

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
        
        cGarch myGarch(2);
        myGarch.Set(0.8, 0);
        myGarch.Set(0.6, 1);
        
        cArch myArch(2);
        myArch.Set(0.8, 0);
        myArch.Set(-0.2, 1);
	
	cCondMean myCondMeanArma ;
	myCondMeanArma.SetOneMean(0, myConst) ;
	myCondMeanArma.SetOneMean(1, myAr) ;
	myCondMeanArma.SetOneMean(2, myMa) ;

	cConstCondVar myConstVar(1.0) ;

	cCondVar myCondVar ;
	myCondVar.SetOneVar(0, myConstVar) ;
        myCondVar.SetOneVar(1, myGarch);
        myCondVar.SetOneVar(2, myArch);
	
	cNormResiduals myNormResid ;

	cRegArchModel myModelArma ;
	myModelArma.SetMean(myCondMeanArma) ;
	myModelArma.SetVar(myCondVar) ;
	myModelArma.SetResid(myNormResid) ;
	cout << "\n\n---------Modele---------\n" ;
	myModelArma.Print() ;
	
	cRegArchModel myModelArmaCp(myModelArma) ;
	cout << "\n\n---------Copie du modele ---------\n" ;
	myModelArmaCp.Print() ;

	// Observations
	uint myNData = 10 ;
	cRegArchValue myGivenValue(myNData) ;
	for(uint t=0; t < myGivenValue.mYt.GetSize(); t++)
	{
		myGivenValue.mYt[t] = t;
	}
        

	cDVector myMeans(myNData);
        cDVector myVars(myNData);
        // Moyennes conditionnelles

	for(uint t=0; t < myGivenValue.mYt.GetSize(); t++)
	{
		myMeans[t] = myCondMeanArma.ComputeMean(t, myGivenValue);
                myGivenValue.mUt[t] = myGivenValue.mYt[t] - myMeans[t];
		myGivenValue.mMt[t] = myMeans[t];
                
                myVars[t] = myCondVar.ComputeVar(t, myGivenValue);
                myGivenValue.mHt[t] = myVars[t];
	} 
        // TESTS SANS ALEAS pour u(t)
        cout << "\n\n---------TESTS SANS ALEAS pour u(t)---------\n";
	cout << "Moyennes conditionnelles ARMA pur gaussien : " << endl ;
	myMeans.Print();

        cout << "\n"<< "Variances conditionnelles ARMA pur gaussien : " << endl ;
	myVars.Print();
        
        // TESTS de l'aléa 
        cout << "\n\n---------TESTS de l'aléa---------\n";
        cout << "\n Vecteurs résidus:\n";
        cDVector vecteurResidus(10);
        myNormResid.Generate(10, vecteurResidus);
        vecteurResidus.Print();
        
	// Simulation        
	uint myNSample = 5;
	cRegArchValue mySimulData(myNSample);
	cDVector mySimulVector(myNSample);

        cRegArchModel modelVide;
        modelVide.SetMean(myCondMeanArma) ;
	modelVide.SetVar(myCondVar) ;
	RegArchLib::RegArchSimul(4, mySimulData, myModelArma) ;
        cout << "\n\n---------SIMULATION---------\n";
        cout << "\nResidus : \n";
        mySimulData.mEpst.Print();
        cout << "\nValeurs h(t)\n";
        mySimulData.mHt.Print();
        cout << "\nValeurs u(t)\n";
        mySimulData.mUt.Print();
        cout << "\nValeurs Esperance\n";
        mySimulData.mMt.Print();
	cout << "\nValeurs simulees : \n";
	mySimulVector = mySimulData.mYt;
	mySimulVector.Print();
        
        // Calcul de vraisemblance
        double myLoglikelihood = 0.;
        myLoglikelihood = RegArchLLH(myModelArma, myGivenValue);
        cout << "\n\n---------Log-vraisemblance---------\n" << myLoglikelihood << endl;
        
	return 0 ;


}
