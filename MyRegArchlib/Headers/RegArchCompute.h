#pragma once 
#ifndef _REGARCHCOMPUTE_H_
#define _REGARCHCOMPUTE_H_

#include "cRegArchModel.h"
#include "cRegArchValue.h"

/*!
 \file RegArchCompute.h
 \brief Header for simulation / estimation of general RegArch models.

 \author Jean-Baptiste DURAND, Ollivier TARAMASCO
 \date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {
// please complete function profile
extern _DLLEXPORT_ void RegArchSimul(uint t, cRegArchValue &vectorPast, const cCondMean mean, const cCondVar var, const cAbstResiduals& residus) ; ///< Simulation of a general RegArch Model

extern _DLLEXPORT_ double RegArchLLH(cRegArchModel myModelArma, cRegArchValue myGivenValue);

}

#endif //_REGARCHCOMPUTE_H_
