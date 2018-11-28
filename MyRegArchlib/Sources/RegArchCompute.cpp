#include "StdAfxRegArchLib.h"
/*!
	\file RegArchCompute.cpp
	\brief implementation of the Simulation / Estimation procedures for general RegArchModel
	
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - last change feb-18-2011
*/
 namespace RegArchLib {

	/*!
	 * \fn void RegArchSimul(uint t, cRegArchValue &Data, const cRegArchModel& model)
	 * \param uint t: time until data is computed
         * \param cRegArchValue &Data: Object where the data simulated is stored
         * \param const cRegArchModel& model: mathematic model for the mean, var and residuals
	 */
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
        
        double RegArchLLH(const cRegArchModel& myModelArma, const cRegArchValue& myGivenValue)
        {
                       
            uint T = myGivenValue.mYt.GetSize();
            
            double sum_h = 0;
            double sum_logV = 0;
            for(uint t = 0; t < T; t++){
                
                myGivenValue.mMt[t] = myModelArma.mMean->ComputeMean(t, myGivenValue);
                myGivenValue.mUt[t] = myGivenValue.mYt[t] - myGivenValue.mMt[t];
                myGivenValue.mHt[t] = myModelArma.mVar->ComputeVar(t, myGivenValue);
                myGivenValue.mEpst[t] = (myGivenValue.mYt[t] - myGivenValue.mMt[t])/(std::sqrt(myGivenValue.mHt[t]));
                
                sum_h += std::log(myGivenValue.mHt[t]);
                sum_logV += myModelArma.mResids->LogDensity(myGivenValue.mEpst[t]); 
            }
            
            return (sum_logV - 0.5 * sum_h);
        }

} //namespace
