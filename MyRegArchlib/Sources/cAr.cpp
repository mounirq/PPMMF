#include "StdAfxRegArchLib.h"
/*!
	\file cAr.cpp
	\brief sources for class cAr methods.

	\author Jean-Baptiste Durand, Ollivier TARAMASCO
	\date dec-18-2006 - Last change feb-18-2011
*/

namespace RegArchLib {
	/*!
	 * \fn cAr::cAr(uint theNAr):cAbstCondMean(eAr)
	 * \param uint theNAr: number of AR lags.
	 */
	cAr::cAr(uint theNAr)
	:cAbstCondMean(eAr) // call constructor of cAbstCondMean with type eAr
	{
		mvAr.ReAlloc(theNAr) ;
		MESS_CREAT("cAr")
	}

	/*!
	 * \fn cAr::cAr(const cDVector& theAr):cAbstCondMean(eAr)
	 * \param const cDVector& theAr: vector of AR coefficients.
	 */
	cAr::cAr(const cDVector& theAr)
	:cAbstCondMean(eAr) // call constructor of cAbstCondMean with type eAr
	{
		mvAr = theAr ;
		MESS_CREAT("cAr")
	}

	/*!
	 * \fn cAr::~cAr()
	 */
	cAr::~cAr()
	{
		mvAr.Delete() ;
		MESS_DESTR("cAr")
	}

	/*!
	 * \fn cAr::PtrCopy()
	 */
	cAbstCondMean* cAr::PtrCopy() const
	{
		// complete
            return new cAr(this->mvAr);
	}


	/*!
	 * \fn void cAr::Delete(void)
	 * \param void
	 */
	void cAr::Delete(void)
	{
		mvAr.Delete() ;
	}

	/*!
	 * \fn void cAr::Print(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
	void cAr::Print(ostream& theOut) const
	{
	uint myNAr = mvAr.GetSize() ;
		theOut << "AR(" << myNAr << ") model with:" << endl ;
		for (register uint i = 0 ; i < myNAr ; i++)
			theOut << "\tAR[" << i+1 << "]=" << mvAr[i] << endl ;
	}

	/*!
	 * \fn void cAr::Set(double theValue, uint theIndex, uint theNumParam)
	 * \brief fill the parameters vector
	 * \param double theValue: the value of the "theIndex" th lag. Default 0.
	 * \param uint theIndex: the index.
	 * \param uint theNumParam: not used for AR model. Default 0.
	 * \details mvAr[theIndex] = theValue
	 */
	void cAr::Set(double theValue, uint theIndex, uint theNumParam)
	{	if (theIndex < mvAr.GetSize())
			mvAr[theIndex] = theValue ;
		else
			throw cError("wrong index") ;
	}

	/*!
	 * \fn void cAr::Set(const cDVector& theVectParam, uint theNumParam)
	 * \brief fill the parameters vector
	 * \param const cDVector& theVectParam: the vector of AR param
	 * \param uint theNumParam: not used for AR model. Default 0.
	 * \details mvAr = theVectParam
	 */
	void cAr::Set(const cDVector& theVectParam, uint theNumParam)
	{
		mvAr = theVectParam ;
	}

	/*!
	 * \fn void cAr::ReAlloc(uint theSize, uint theNumParam)
	 * \param uint theSize: new size of mvAr
	 * \param uint theNumParam; not used here.
	 * \details new allocation of mvAr
	 */

	double  cAr::Get(uint theIndex, uint theNumParam)
	{
		return mvAr[theIndex] ;
	}

	void cAr::ReAlloc(uint theSize, uint theNumParam)
	{
		mvAr.ReAlloc(theSize) ;
	}

	/*!
	 * \fn void cAr::ReAlloc(const cDVector& theVectParam, uint theNumParam)
	 * \param const cDVector& theVectParam: the vector of AR coefficients
	 * \param uint theNumParam: not used here.
	 * \details new allocation of mvAr
	 */
	void cAr::ReAlloc(const cDVector& theVectParam, uint theNumParam)
	{
		mvAr = theVectParam ;
	}

	/*!
	 * \fn double cAr::ComputeMean(uint theDate, const cRegArchValue& theData) const
	 * \brief Compute conditional mean component for an AR model
	 * \param int theDate: date of the computation
	 * \param const cRegArchValue& theData: past datas.
	 * \details theData is not updated here.
	 */
	double cAr::ComputeMean(uint theDate, const cRegArchValue& theData) const
	{
            
            double result = 0;
            uint size = this->mvAr.GetSize();
            for (uint i=0; i<size; i++)
            {
                if (theDate -i >= 0)
                {
                    result += this->mvAr[i] * theData.mYt[theDate - i];
                }
            }
            return result;
	}

	uint cAr::GetNParam(void) const
	{
		return mvAr.GetSize() ;
	}

	void cAr::copy(const cAr& theAr)
	{
		mvAr = theAr.mvAr;
	}

}//namespace
