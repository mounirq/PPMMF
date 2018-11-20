#pragma once 
#ifndef _CABSTCONDVAR_H_
#define _CABSTCONDVAR_H_

#include "RegArchDef.h"
#include "cRegArchValue.h"
/*!
	\file cAbstCondVar.h
	\brief Definition of the abstract class to implement conditional variance
	
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - last change feb-18-2011
*/

namespace RegArchLib {
	
	class _DLLEXPORT_ cAbstResiduals ;

	/*! 
	 * \class cAbstCondVar
	 * \brief Abstract class to implement a conditional variance model
	 */
	class _DLLEXPORT_ cAbstCondVar
	{
	private :
		eCondVarEnum	mvCondVar ; ///< Conditional variance type code
	public :
		cAbstCondVar(eCondVarEnum theType = eNotKnown) ; ///< A simple constructor
		virtual ~cAbstCondVar() ;  ///< A simple destructor
		// Complete
		// PtrCopy() const ; /// < Return a copy of *this
		eCondVarEnum GetCondVarType(void) const ; ///< Return the variance type code
		virtual void Delete(void) = 0 ; ///< delete
		virtual void Print(ostream& theOut=cout) const = 0 ;  ///< Print the parameters
		friend ostream& operator <<(ostream& theOut, const cAbstCondVar& theAbstCondVar) ; ///< Print the parameters
		virtual void Set(double theValue, uint theIndex=0, uint theNumParam=0) = 0 ; ///< Set model parameters.
		virtual void Set(const cDVector& theVectParam, uint theNumParam=0) = 0 ; ///< Set model parameters.
		virtual double Get(uint theIndex=0, uint theNumParam=0) = 0 ;
		virtual void ReAlloc(uint theSize, uint theNumParam=0) = 0 ; ///< Allocation of the model parameters
		virtual void ReAlloc(const cDVector& theVectParam, uint theNumParam=0) = 0 ; ///< Allocation of the model parameters
		virtual double ComputeVar(uint theDate, const cRegArchValue& theData) const=0 ; ///< Return conditional variance.
		/** Return the number of parameters in CondVar */
		virtual uint GetNParam(void) const = 0 ;
	} ;

}
#endif // _CABSTCONDVAR_H_
