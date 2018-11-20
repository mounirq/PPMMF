#include "StdAfxRegArchLib.h"
/*!
	\file cAbstCondMean.cpp
	\brief sources for abstract class cConst methods.

	\author Jean-Baptiste Durand, Ollivier TARAMASCO
	\date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {
	/*!
	 * \fn cConst::cConst(double theVal):cAbstCondMean(eConst)
	 * \param double theVal: constant value, default 0.0L.
	 */
	cConst::cConst(double theVal)
	:cAbstCondMean(eConst) // call constructor of cAbstCondMean with type eConst
	{	
		mvConst = theVal ;
		MESS_CREAT("cConst") ;
	}


	/*!
	 * \fn cConst::~cConst()
	 * \details Nothing to do.
	 */
	cConst::~cConst()
	{	MESS_DESTR("cConst") ;
	}

	/*!
	 * \fn cAbstCondMean* cConst::PtrCopy()
	 */
	cAbstCondMean* cConst::PtrCopy() const
	{
            return new cConst(this->mvConst);
	}

	/*!
	 * \fn void cConst::Delete(void)
	 * \\details Delete. Nothing to do.
	 */
	void cConst::Delete(void)
	{	MESS_DESTR("cConst") ;
	}

	/*!
	 * \fn void cConst::Print(ostream& theOut) const
	 * \param ostream& theOut: output stream (screen or file). Default cout.
	 */
	void cConst::Print(ostream& theOut) const
	{	theOut << "Constant conditional mean with:" << endl ;
		theOut << "\tConstant=" << mvConst << endl ;
	}

	/*!
	 * \fn void cConst::Set(double theValue, uint theIndex, uint theNumParam)
	 * \brief fill the parameters vector
	 * \param double theValue: the constant value.
	 * \param uint theIndex: not used here. Default 0.
	 * \param uint theNumParam: not used for cConst model. Default 0.
	 * \details mvConst = theValue
	 */
	void cConst::Set(double theValue, uint theIndex, uint theNumParam)
	{	mvConst = theValue ;
	}

	/*!
	 * \fn void cConst::Set(const cDVector& theVectParam, uint theNumParam)
	 * \brief fill the parameters vector
	 * \param const cDVector& theVectParam: the constant value is in theVectParam[0].
	 * \param uint theIndex: not used here. Default 0.
	 * \param uint theNumParam: not used for cConst model. Default 0.
	 * \details mvConst = theVectParam[0]
	 */

	void cConst::Set(const cDVector& theVectParam, uint theNumParam)
	{	if (theVectParam.GetSize() > 0)
			mvConst = theVectParam[0] ;
		else
			throw cError("the size of theVectParam must be > 0") ;
	}


	double  cConst::Get(uint theIndex, uint theNumParam)
	{
		return mvConst ;
	}

	/*!
	 * \fn void cConst::ReAlloc(uint theSize, uint theNumParam=0)
	 * \param uint theSize: not used. Not used for cConstClass
	 * \param uint theNumParam: not used for cConst class
	 * \details Nothing to do for cConst Class.
	 */
	void cConst::ReAlloc(uint theSize, uint theNumParam)
	{
	}

	/*!
	 * \fn void cConst::ReAlloc(const cDVector& theVectParam, uint theNumParam)
	 * \param const cDVector& theVectParam: the constant value is in theVectParam[0]
	 * \param uint theNumParam: not used for cConst class
	 * \details Here, mvConst = theVectParam[0]
	 */
	void cConst::ReAlloc(const cDVector& theVectParam, uint theNumParam)
	{
		if (theVectParam.GetSize() > 0)
			mvConst = theVectParam[0] ;
		else
			throw cError("Size of 'theVectParam' must be > 0") ;
	}

	/*!
	 * \param int theDate: date of the computation
	 * \param cRegArchValue& theData: past datas.
	 * \details theData must not be updated here.
	 */
	double cConst::ComputeMean(uint theDate, const cRegArchValue& theData) const
	{
		// Complete	
	}

	uint cConst::GetNParam(void) const
	{
		return 1 ;
	}

	void cConst::copy(const cConst& theConst)
	{
		mvConst = theConst.mvConst;
	}

}//namespace
