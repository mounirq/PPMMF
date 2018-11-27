#include "StdAfxRegArchLib.h"

/*!
	\file cArch.cpp
	\brief sources for class cArch methods.

	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - Last change feb-18-2011
*/

namespace RegArchLib {
	/*!
	 * \fn cArch::cArch(uint theNArch):cAbstCondVar(eArch)
	 * \param uint theNArch: number of lags
	 */
	cArch::cArch(uint theNArch)
	:cAbstCondVar(eArch)   // call constructor of cAbstCondVar with type eArch
	{
		mvArch.ReAlloc(theNArch) ;
		MESS_CREAT("cArch")
	}
        
        cArch::cArch(const cDVector& theArch):cAbstCondVar(eArch)
	{
		mvArch = theArch ;
		MESS_CREAT("cArch")
	}

	/*!
	 * \fn cArch::~cArch()
	 */
	cArch::~cArch()
	{	mvArch.Delete() ;
  		MESS_DESTR("cArch") ;
	}

	/*!
	 * \fn cArch::PtrCopy()
	 */
	cAbstCondVar* cArch::PtrCopy() const
	{	            
            return new cArch(this->mvArch);            
	}

	/*!
	 * \fn void cArch::Delete(void)
	 * \param void
	 * \details Delete mvVar
	 */
	void cArch::Delete(void)
	{	mvArch.Delete() ;
	}

	/*!
	 * \fn void cArch::Print(ostream& theOut) const
	 * \param ostream& theOut: output stream (file or screen). Default cout.
	 */
	void cArch::Print(ostream& theOut) const
	{
	uint myNArch = mvArch.GetSize() ;
		theOut << "ARCH(" << myNArch << ") model with:" << endl ;
		for (register uint i = 0 ; i < mvArch.GetSize() ; i++)
			theOut << "\tARCH[" << i+1 << "]=" << mvArch[i] << endl ;
	}

	/*!
	 * \fn void cArch::ReAlloc(uint theSize, uint theNumParam)
	 * \param uint theSize: new size of mvAr
	 * \param uint theNumParam: not used here.
	 * \details new allocation of mvArch
	 */
	void cArch::ReAlloc(uint theSize, uint theNumParam)
	{
		mvArch.ReAlloc(theSize) ;
	}

	/*!
	 * \fn void cArch::ReAlloc(const cDVector& theVectParam, uint theNumParam)
	 * \param const cDVector& theVectParam: the vector of Const or ARCH coefficients
	 * \param uint theNumParam: =0, the constant part; =1 the ARCH coefficients
	 * \details new allocation of mvArch or mvConst
	 */
	void cArch::ReAlloc(const cDVector& theVectParam, uint theNumParam)
	{	switch (theNumParam)
		{	case 0: // mvConst
				mvArch = theVectParam ;
			break ;
			default :
	//			throw cError("cArch::ReAlloc - theNumParam must be in 0, 1") ;
			break ;
		}
	}

	/*!
	 * \fn void cArch::Set(double theValue, uint theIndex, uint theNumParam)
	 * \brief fill the parameters vector
	 * \param double theValue: the value of the "theIndex" th lag. Default 0.
	 * \param uint theIndex: the index.
	 * \param uint theNumParam: =0, mvConst, =1, ARCH parameters
	 * \details mvArch[theIndex] = theValue or mvConst = theValue
	 */
	void cArch::Set(double theValue, uint theIndex, uint theNumParam)
	{	switch (theNumParam)
		{	case 0 :
				if (theIndex < mvArch.GetSize())
					mvArch[theIndex] = theValue ;
				else
					throw cError("cArch::Set - wrong index") ;
			break ;
			default:
				throw cError("cArch::Set - theNumParam must be in 0, 1") ;
			break ;
		}
	}

	double cArch::Get(uint theIndex, uint theNumParam)
	{
		double res = 0.0;
		switch (theNumParam)
		{	case 0 :
				res = mvArch[theIndex] ;
			break ;
		}
		return res;
	}


	/*!
	 * \fn void cArch::Set(const cDVector& theVectParam, uint theNumParam)
	 * \brief fill the parameters vector
	 * \param const cDVector& theVectParam: the vector of values
	 * \param uint theNumParam: =0, mvConst; =1, mvArch
	 * \details mvArch = theVectParam or mvConst = theVectParam[0]
	 */
	void cArch::Set(const cDVector& theVectParam, uint theNumParam)
	{	switch (theNumParam)
		{	case 0 :
				mvArch = theVectParam ;
			break ;
			default:
				throw cError("cArch::Set - theNumParam must be in 0, 1") ;
			break ;
		}
	}



	/*!
	 * \fn double cArch::ComputeVar(uint theDate, const cRegArchValue& theData) const
	 * \param int theDate: date of computation
	 * \param const cRegArchValue& theData: past datas
	 * \details theData is not updated here.
	*/
	double cArch::ComputeVar(uint theDate, const cRegArchValue& theDatas) const
	{
            double somme = 0;
            for (uint i=1; i<= this->mvArch.GetSize(); i++)
            {
                if (theDate >= i)
                {
                    somme += this->mvArch[i-1] * theDatas.mUt[theDate - i] * theDatas.mUt[theDate - i];
                }
            }
            return somme;
	}

	uint cArch::GetNParam(void) const
	{
		return mvArch.GetSize() ;
	}

	void cArch::copy(const cArch& theArch)
	{
		mvArch = theArch.mvArch;
	}
	

}//namespace
