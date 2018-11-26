#include "StdAfxRegArchLib.h"
/*!
 \file cMa.cpp
 \brief sources for class cMa methods.

 \author Jean-Baptiste Durand, Ollivier TMAAMASCO
 \date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {
	/*!
	 * \fn cMa::cMa(uint theNMa):cAbstCondMean(eMa)
	 * \param int theNMa: number of lags.
	 */

	cMa::cMa(uint theNMa)
	:cAbstCondMean(eMa) // call constructor of cAbstCondMean with type eMa
	{
		mvMa.ReAlloc(theNMa) ;
		MESS_CREAT("cMa")
	}

	/*!
	 * \fn cMa::cMa(const cDVector& theMa):cAbstCondMean(eMa)
	 * \param const cDVector& theAr: vector of AR coefficients.
	 */
	cMa::cMa(const cDVector& theMa)
	:cAbstCondMean(eMa) // call constructor of cAbstCondMean with type eMa
	{
		mvMa = theMa ;
		MESS_CREAT("cMa")
	}

	/*!
	 * \fn cMa::~cMa()
	 */
	cMa::~cMa()
	{
		mvMa.Delete() ;
		MESS_DESTR("cMa")
	}

	/*!
	 * \fn cAbstCondMean* cMa::PtrCopy()
	 */
	cAbstCondMean* cMa::PtrCopy() const
	{
            return new cMa(this->mvMa);
	}

	/*!
	 * \fn void cMa::Delete(void)
	 * \param void
	 */
	void cMa::Delete(void)
	{
		mvMa.Delete() ;
	}

	/*!
	 * \fn void cMa::Print(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
	void cMa::Print(ostream& theOut) const
	{
	uint myNMa = mvMa.GetSize();
		theOut << "MA(" << myNMa << ") mean with:" << endl ;
		for (register uint i = 0 ; i <  myNMa ; i++)
			theOut << "\tMA[" << i+1 << "]=" << mvMa[i] << endl ;
	}

	/*!
	 * \fn void cMa::Set(double theValue, uint theIndex=0, uint theNumParam)
	 * \param double theValue: the theIndex th value
	 * \param uint theIndex: the index
	 * \param uint theNumParam: not used here
	 * \details mvMa[theIndex] = theValue
	 */
	void cMa::Set(double theValue, uint theIndex, uint theNumParam)
	{
		if (theIndex >= mvMa.GetSize())
			throw cError("Bad index") ;
		else
			mvMa[theIndex]=theValue ;
	}

	/*!
	 * \fn void cMa::Set(const cDVector& theVectParam, uint theNumParam)
	 * \param const cDVector& theVectParam: the vector of MA coefficients
	 * \param uint theNumParam: not used here
	 * \details mvMa = theVectParam
	 */
	void cMa::Set(const cDVector& theVectParam, uint theNumParam)
	{
		mvMa=theVectParam ;
	}

	double cMa::Get(uint theIndex, uint theNumParam)
	{
		return mvMa[theIndex] ;
	}

	/*!
	 * \fn void cMa::ReAlloc(uint theSize, uint theNumParam)
	 * \param uint theSize: new size of mvMA
	 * \param uint theNumParam; not used here.
	 * \details new allocation of mvMa 
	 */
	void cMa::ReAlloc(uint theSize, uint theNumParam)
	{
		mvMa.ReAlloc(theSize) ;
	}

	/*!
	 * \fn void cAr::ReAlloc(const cDVector& theVectParam, uint theNumParam)
	 * \param const cDVector& theVectParam: the vector of AR coefficients
	 * \param uint theNumParam: not used here.
	 * \details new allocation of mvAr
	 */
	void cMa::ReAlloc(const cDVector& theVectParam, uint theNumParam)
	{
		mvMa = theVectParam ;
	}

	/*!
	 * \fn cMa::ComputeMean(uint theDate, const cRegArchValue& theData) const
	 * \param int theDate: date of the computation
	 * \param cRegArchValue& theData: past datas.
	 * \details theData is not updated here.
	 */
	double cMa::ComputeMean(uint theDate, const cRegArchValue& theData) const
	{
            double result = 0;
            uint size = this->mvMa.GetSize();
            for (uint i=1; i<=size; i++)
            {
                if (theDate >= i)                    
                {
                    result += this->mvMa[i-1] * theData.mUt[theDate-i];
                }
            }
            return result;
	}

	uint cMa::GetNParam(void) const
	{
		return mvMa.GetSize() ;
	}

	void cMa::copy(const cMa& theMa)
	{
		mvMa = theMa.mvMa;
	}

}//namespace
