#pragma once 
#ifndef _CAR_H_
#define _CAR_H_

#include "cAbstCondMean.h"
#include "cRegArchValue.h"
#include "cRegArchGradient.h"

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
		virtual cAbstCondMean* PtrCopy() const ; /// < Return a copy of *this
		void Delete(void) ; ///< Delete mvAr
		void Print(ostream& theOut=cout) const ; ///< Print the parameters
		void Set(double theValue, uint theIndex=0, uint theNumParam=0) ; ///< Set model parameters.
		void Set(const cDVector& theVectParam, uint theNumParam=0) ; ///< Set model parameters.
		double Get(uint theIndex=0, uint theNumParam=0) ;
		void ReAlloc(uint theSize, uint theNumParam=0) ; ///< Allocation of the model parameters
		void ReAlloc(const cDVector& theVectParam, uint theNumParam=0) ; ///< Allocation of the model parameters
		cAbstCondMean& operator=(cAbstCondMean& theSrc) ; ///< Standard affectation
		double ComputeMean(uint theDate, const cRegArchValue& theData) const ; ///< Compute subtle conditional mean value
		uint GetNParam(void) const ;
		uint GetNLags(void) const ;
		void ComputeGrad(uint theDate, const cRegArchValue& theData, cRegArchGradient& theGradData, uint theBegIndex, cAbstResiduals* theResiduals) ;
		void RegArchParamToVector(cDVector& theDestVect, uint theIndex) ;
		void VectorToRegArchParam(const cDVector& theSrcVect, uint theIndex = 0) ;
	protected :
		void copy(const cAr& theAr) ; /// < Copy attribute from instance

	} ;
}
#endif // _CAR_H_
