#pragma once 
#ifndef _REGARCHCOMPUTE_H_
#define _REGARCHCOMPUTE_H_

#include "cRegArchModel.h"
#include "cRegArchValue.h"
#include "cRegArchGradient.h"

/*!
 \file RegArchCompute.h
 \brief Header for simulation / estimation of general RegArch models.

 \author Jean-Baptiste DURAND, Ollivier TARAMASCO
 \date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {

extern _DLLEXPORT_ void RegArchSimul(uint theNSample, const cRegArchModel& theModel, cRegArchValue& theData) ; ///< Simulation of a general RegArch Model
extern _DLLEXPORT_ double RegArchLLH(const cRegArchModel& theParam, cDVector* theYt, cDMatrix* theXt=NULL) ; ///< Log-Likelihood of a general RegArch Model
extern _DLLEXPORT_ double RegArchLLH(const cRegArchModel& theParam, cRegArchValue& theData) ; ///< Log-Likelihood of a general RegArch Model
extern _DLLEXPORT_ void RegArchGradLt(int theDate, cRegArchModel& theParam, cRegArchValue& theData, cRegArchGradient& theGradData, cDVector& theGradlt) ;
extern _DLLEXPORT_ void RegArchGradLLH(cRegArchModel& theParam, cRegArchValue& theData, cDVector& theGradLLH) ;
extern _DLLEXPORT_ void NumericRegArchGradLLH(cRegArchModel& theModel, cRegArchValue& theValue, cDVector& theGradLLH, double theh = 1e-3) ;

}

#endif //_REGARCHCOMPUTE_H_
