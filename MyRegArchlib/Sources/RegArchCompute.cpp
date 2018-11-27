#include "StdAfxRegArchLib.h"
/*!
	\file RegArchCompute.cpp
	\brief implementation of the Simulation / Estimation procedures for general RegArchModel
	
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - last change feb-18-2011
*/
 namespace RegArchLib {

	// please complete
	void RegArchSimul(uint t, cRegArchValue &Data, const cCondMean mean, const cCondVar var, const cAbstResiduals& residus)
	{
            double h0 = Data.mHt[0];
            double moyenne = Data.mMt[0];
            double u0 = Data.mUt[0];
            double y0 = Data.mYt[0];
            cout<< "\nh(0) = "<<Data.mHt[0];
            cout<< "\nM(0) = "<<Data.mMt[0];
            cout<< "\nu(0) = "<<Data.mUt[0];
            cout<< "\nY(0) = "<<Data.mYt[0];
            
            Data.ReAlloc(t +1);
            residus.Generate(t+1, Data.mEpst);  
            Data.mEpst[0] = -1.726;
            Data.mEpst[1] = -0.757;
            
            Data.mHt[0] = h0;
            Data.mMt[0] = moyenne;
            Data.mUt[0] = u0;
            Data.mYt[0] = y0;
            
            cout<< "\nh(0) = "<<Data.mHt[0];
            cout<< "\nM(0) = "<<Data.mMt[0];
            cout<< "\nu(0) = "<<Data.mUt[0];
            cout<< "\nY(0) = "<<Data.mYt[0];
            
            
            double varCond = var.ComputeVar(t, Data);
            Data.mHt[t] = varCond;
            double u = std::sqrt(Data.mHt[t]) * Data.mEpst[Data.mEpst.GetSize()-1];  
            Data.mUt[t] = u;
            
            double esperanceCond = mean.ComputeMean(t, Data);
            Data.mMt[t] = esperanceCond;

            Data.mYt[t] = Data.mMt[t] + Data.mUt[t];            
	}

} //namespace
