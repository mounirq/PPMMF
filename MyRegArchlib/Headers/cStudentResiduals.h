#pragma once 
#ifndef _CSTUDENTRESIDUALS_H_
#define _CSTUDENTRESIDUALS_H_

#include <gsl/gsl_sf_gamma.h>
#include <gsl/gsl_sf_psi.h>
#include "cAbstResiduals.h"
#include "cRegArchValue.h"
#include "cRegArchGradient.h"

/*!
 \file cStudentResiduals.h
 \brief Definition of the class for Student conditional distribution.

 \author Jean-Baptiste DURAND, Ollivier TARAMASCO
 \date dec-18-2006 - Last change feb-18-2011
*/


namespace RegArchLib {

	/*! 
	 * \class cStudentResiduals
	 * \brief  Class to implement a Student distribution with unitary variance for residuals
	 */
	class _DLLEXPORT_ cStudentResiduals: public cAbstResiduals
	{
	public :
		cStudentResiduals(double theDof, bool theSimulFlag=true) ; ///< A constructor
		cStudentResiduals(cDVector* theDistrParameter=NULL, bool theSimulFlag=true) ;	///< A constructor
		virtual ~cStudentResiduals() ; ///< A simple destructor
		virtual cAbstResiduals* PtrCopy() const ; /// < Return a copy of *this
		void Print(ostream& theOut) const ; ///< Print the distribution type
		void Generate(uint theNSample, cDVector& theYt) const; ///< Draw a sample from residual distribution 
		double LogDensity(double theX) const ;
		uint GetNParam(void) const ;
		/** Compute the derivatives of the log-density with respect to the variable \e and the parameters */
		void ComputeGrad(uint theDate, const cRegArchValue& theData, cRegArchGradient& theGradData) ;
		void RegArchParamToVector(cDVector& theDestVect, uint theIndex) const ;
		void VectorToRegArchParam(const cDVector& theSrcVect, uint theIndex = 0) ;
	} ;
}
#endif //_CSTUDENTRESIDUALS_H_

