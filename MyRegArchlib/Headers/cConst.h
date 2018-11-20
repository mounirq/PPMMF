#pragma once 
#ifndef _CCONST_H_
#define _CCONST_H_
/*!
 \file cConst.h
 \brief header for class cConst.

 \author Jean-Baptiste Durand, Ollivier TARAMASCO
 \date dec-18-2006 - Last change feb-18-2011
*/
#include "cAbstCondMean.h"
#include "cRegArchValue.h"


namespace RegArchLib {
	/*! 
	 * \class cConst
	 * \brief  Class to implement a constant mean model
	 */
	class _DLLEXPORT_ cConst: public cAbstCondMean
	{
	private :
		double	mvConst	; ///< Const value
	public :
		cConst(double theVal = 0.0L) ; ///< A simple constructor
		virtual ~cConst() ; ///< A simple destructor
		// Complete
		// PtrCopy() const ; /// < Return a copy of *this
		void Delete(void) ;  ///< Free memory
		void Print(ostream& theOut=cout) const ; ///< Print the parameters
		void Set(double theValue, uint theIndex=0, uint theNumParam=0) ; ///< Set model parameters.
		void Set(const cDVector& theVectParam, uint theNumParam=0) ; ///< Set model parameters.
		double Get(uint theIndex=0, uint theNumParam=0) ;
		void ReAlloc(uint theSize, uint theNumParam) ; ///< New memory allocation of parameters
		void ReAlloc(const cDVector& theVectParam, uint theNumParam=0) ; ///< New memory allocation of parameters
		// Complete source		
		double ComputeMean(uint theDate, const cRegArchValue& theData) const ; ///< Compute the conditional mean value
		uint GetNParam(void) const ; ///< Number of parameters in that model part
	protected :
		void copy(const cConst& theConst) ; /// < Copy attribute from instance

	} ;
}
#endif //_CCONST_H_

