#include "StdAfxRegArchLib.h"
/*!
	\file RegArchCompute.cpp
	\brief implementation of the Simulation / Estimation procedures for general RegArchModel
	
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - last change feb-18-2011
*/
 namespace RegArchLib {

	// please complete
	void RegArchSimul(uint t, cRegArchValue &Data, const cRegArchModel& model)
	{
            double varianceCond = 0;
            double meanCond = 0;
            Data.ReAlloc(t+1);
            if (model.mResids != NULL)
            {
                model.mResids->Generate(t + 1, Data.mEpst );
            }
            else
            {
                Data.mEpst.ReAlloc(t+1);
            }
            for (uint i=0; i<=t; i++)
            {
                if (model.mVar != NULL)
                {
                    varianceCond = model.mVar->ComputeVar(i, Data);
                }
                Data.mHt[i] = varianceCond;
                Data.mUt[i] = std::sqrt(Data.mHt[i]) * Data.mEpst[i];
                
                if (model.mMean != NULL)
                {
                    meanCond = model.mMean->ComputeMean(i, Data);
                }
                Data.mMt[i] = meanCond;
                Data.mYt[i] = Data.mMt[i] + Data.mUt[i];
            }           
	}

} //namespace
