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

extern _DLLEXPORT_ double RegArchLLH(const cRegArchModel& myModelArma, const cRegArchValue& myGivenValueOld);
extern _DLLEXPORT_ void RegArchSimul(uint t, cRegArchValue &vectorPast, const cRegArchModel& model) ; ///< Simulation of a general RegArch Model
}

#endif //_REGARCHCOMPUTE_H_
