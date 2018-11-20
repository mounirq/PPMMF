#pragma once
#ifndef _CNORMRESIDUALS_H_
#define _CNORMRESIDUALS_H_
#include "cAbstResiduals.h"
#include "cRegArchValue.h"
/*!
 \file cNormResiduals.h
 \brief Definition of the class for N(0, 1) conditional distribution.

 \author Jean-Baptiste DURAND, Ollivier TARAMASCO
 \date dec-18-2006 - Last change feb-18-2011
*/

namespace RegArchLib {

	/*! 
	 * \class cNormResiduals
	 * \brief  Class to implement the N(0, 1) residuals
	 */

	class _DLLEXPORT_ cNormResiduals: public cAbstResiduals
	{
	public :
		cNormResiduals(const cDVector* theDistrParameter=NULL, bool theSimulFlag=true) ; ///< a simple constructor
		virtual ~cNormResiduals() ; ///< a simple destructor
		// Complete
		cAbstResiduals* PtrCopy() const ; /// < Return a copy of *this
		void Print(ostream& theOut) const ; ///< print the distribution type
		// Complete source		
		void Generate(uint theNSample, cDVector& theYt) const ; ///< Draw a sample from residual distribution 
		// Complete source		
		double LogDensity(double theX) const ;
		/** Return the number of parameters in distribution */
		uint GetNParam(void) const ;
	} ;

}

#endif //_CNORMRESIDUALS_H_

