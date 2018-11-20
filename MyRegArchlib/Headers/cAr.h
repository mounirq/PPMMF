#pragma once 
#ifndef _CAR_H_
#define _CAR_H_

#include "cAbstCondMean.h"
#include "cRegArchValue.h"

/*!
	\file cAr.h
	\brief header for class cAr.

	\author Jean-Baptiste DURAND, Ollivier TARAMASCO
	\date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {
	/*! 
	 * \class cAr
	 * \brief  Class to implement an AR model
	 */
	class _DLLEXPORT_ cAr: public cAbstCondMean
	{
	private :
		cDVector mvAr ; ///< Vector of AR coefficients.
	public :
		cAr(uint theNAr = 0) ; ///< A simple constructor
		cAr(const cDVector& theAr) ; ///< Another constructor
		virtual ~cAr() ;  ///< aA simple destructor
		cAbstCondMean* PtrCopy() const ; /// < Return a copy of *this
		void Delete(void) ; ///< Delete mvAr
		void Print(ostream& theOut=cout) const ; ///< Print the parameters
		void Set(double theValue, uint theIndex=0, uint theNumParam=0) ; ///< Set model parameters.
		void Set(const cDVector& theVectParam, uint theNumParam=0) ; ///< Set model parameters.
		double Get(uint theIndex=0, uint theNumParam=0) ;
		void ReAlloc(uint theSize, uint theNumParam=0) ; ///< Allocation of the model parameters
		void ReAlloc(const cDVector& theVectParam, uint theNumParam=0) ; ///< Allocation of the model parameters
		// Complete source		
		double ComputeMean(uint theDate, const cRegArchValue& theData) const ; ///< Compute the conditional mean value
		uint GetNParam(void) const ; ///< Number of parameters in that model part
	protected :
		void copy(const cAr& theAr) ; /// < Copy attribute from instance

	} ;
}
#endif // _CAR_H_
