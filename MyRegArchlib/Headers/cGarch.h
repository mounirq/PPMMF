#pragma once 
#ifndef _CGARCH_H_
#define _CGARCH_H_

#include "cAbstCondVar.h"
#include "cRegArchValue.h"
/*!
	\file cGarch.h
	\brief Definition of the GARCH(p, q) class
	
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {

	/*! 
	 * \class cGarch
	 * \brief Class to implement a 'pure' GARCH(p, q) model
	 */
	class _DLLEXPORT_ cGarch: public cAbstCondVar
	{
	private :
		cDVector mvGarch ; ///< Vector of GARCH coefficients.
	public :
		cGarch(uint theNGarch=0) ; ///< A simple constructor
		cGarch(const cDVector& theGarch) ; ///< Another constructor
		virtual ~cGarch() ; ///< A simple destructor
		// Complete
		cAbstCondVar* PtrCopy() const ; /// < Return a copy of *this
		void Delete(void) ; /// Delete
		void Print(ostream& theOut=cout) const ; ///< Print the parameters
		void ReAlloc(uint theSize, uint theNumParam=0) ; ///< Allocation of the model parameters
		void ReAlloc(const cDVector& theVectParam, uint theNumParam=0) ; ///< Allocation of the model parameters
		void Set(double theValue, uint theIndex=0, uint theNumParam=0) ; ///< Set model parameters.
		void Set(const cDVector& theVectParam, uint theNumParam=0) ; ///< Set model parameters.
		double Get(uint theIndex=0, uint theNumParam=0) ;
		// Complete source		
		double ComputeVar(uint theDate, const cRegArchValue& theData) const;	///< Return conditional variance.
		uint GetNParam(void) const ; ///< Number of parameters in that model part
	private :
		void copy(const cGarch& theGarch) ; /// < Copy attribute from instance

	} ;

}
#endif // _CGARCH_H_
