#pragma once 
#ifndef _CABSTCONDMEAN_H_
#define _CABSTCONDMEAN_H_

#include "RegArchDef.h"
#include "cRegArchValue.h"
/*!
	\file cAbstCondMean.h
	\brief Definition of the abstract class to implement a conditional mean component
	
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - last change feb-18-2011
*/

namespace RegArchLib {

	class _DLLEXPORT_ cAbstResiduals ;

	/*! 
	 * \class cAbstCondMean
	 * \brief Abstract class definition of a conditional mean model component
	 */
	class _DLLEXPORT_ cAbstCondMean
	{
	private :
		eCondMeanEnum	mvCondMeanType ; ///<  Code for the mean type
	public :
		cAbstCondMean(const eCondMeanEnum theType=eUnknown) ; ///< A constructor
		virtual ~cAbstCondMean() ; ///< Destructor
		// Complete
		// PtrCopy() const ; /// < Return a copy of *this
		eCondMeanEnum GetCondMeanType(void) const ; ///< Return the mean type code
		void SetCondMeanType(eCondMeanEnum theType)  ;
		virtual void Delete(void) = 0 ; ///< Free memory
		virtual void Print(ostream& theOut=cout) const = 0 ; ///< Print the parameters
		friend  _DLLEXPORT_  ostream& operator <<(ostream& theOut, const cAbstCondMean& theAbstCondMean) ; ///< Print the parameters
		virtual void Set(double theValue, uint theIndex=0, uint theNumParam=0) = 0 ; ///< Set model parameters.
		virtual void Set(const cDVector& theVectParam, uint theNumParam=0) = 0 ; ///< Set model parameters.
		virtual double Get(uint theIndex=0, uint theNumParam=0) = 0 ;
		virtual void ReAlloc(uint theSize, uint theNumParam=0) = 0 ; ///< Allocation of the model parameters
		virtual void ReAlloc(const cDVector& theVectParam, uint theNumParam=0) = 0 ; ///< Allocation of the model parameters
		virtual double ComputeMean(uint theDate, const cRegArchValue& theData) const = 0 ; ///< Compute conditional mean.
		/** Return the number of parameters in CondMean */
		virtual uint GetNParam(void) const = 0 ;

	} ;
}

#endif // _CABSTCONDMEAN_H_


