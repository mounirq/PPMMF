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
            double esperanceCond = mean.ComputeMean(t, Data);
            double varCond = var.ComputeVar(t, Data);
            residus.Generate(t+1, Data.mEpst);            
            double u = std::sqrt(varCond) * Data.mEpst[Data.mEpst.GetSize()-1];            
            Data.ReAlloc(t +1);            
            Data.mYt[t] = esperanceCond + u;
            Data.mHt[t] = varCond;
            Data.mUt[t] = u;
            Data.mMt[t] = esperanceCond;
	}

} //namespace
