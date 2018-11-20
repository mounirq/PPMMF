#pragma once 
#ifndef _CABSTRESIDUALS_H_
#define _CABSTRESIDUALS_H_
/*!
	\file cAbstResiduals.h
	\brief Definition of the abstract class to implement a distribution for residuals
	
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - last change feb-18-2011
*/

#include "RegArchDef.h"
#include <gsl/gsl_randist.h>
#include <ctime>
#include <cmath>
#include "cRegArchValue.h"

namespace RegArchLib {

	/*! 
	 * \class cAbstResiduals
	 * \brief Abstract class to implement a conditional distribution model
	 */
	class _DLLEXPORT_ cAbstResiduals
	{
	private :
		eDistrTypeEnum	mvDistr	; ///< Code for distribution type
	protected :
		gsl_rng* mtR ; ///< random generator
	public :
		cDVector	mDistrParameter ; ///< Parameters of the distribution (if any)
	public :
	
		cAbstResiduals(eDistrTypeEnum theDistr, cDVector* theDistrParam=NULL, bool theSimulFlag=true) ; ///< A simple constructor
		virtual ~cAbstResiduals() ; ///< A simple destructor
		// Complete
		// PtrCopy() const ; /// < Return a copy of *this
		void Delete(void) ; ///< Delete
		eDistrTypeEnum GetDistrType(void) const ; ///< Return the distribution type
		void SetSimul(void) ; ///< Change for simulation
		double Get(uint theIndex=0) ;
		void Set(double theValue, uint theIndex=0) ;
		virtual void Print(ostream& theOut=cout) const=0 ; ///< Print the distribution type
		friend ostream& operator <<(ostream& theOut, const cAbstResiduals& theAbstResisuals) ; ///< Print the distribution type
		virtual void Generate(uint theNSample, cDVector& theYt) const=0; ///< Draw a sample from residual distribution
		virtual double LogDensity(double theX) const=0 ; ///< log density function
		/** Return the number of parameters in distribution */
		virtual uint GetNParam(void) const = 0 ;
	} ;

}
#endif //_CABSTRESIDUALS_H_

