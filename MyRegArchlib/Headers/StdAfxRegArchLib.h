#pragma once 
// StdAfxRegArchLib.h : fichier Include pour les fichiers Include systeme standard,
// ou les fichiers Include specifiques aux projets qui sont utilises frequemment,
// et sont rarement modifies
//

#include <cmath>
#include <iostream>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_linalg.h> 
#include "StdAfxError.h"
#include "StdAfxVectorAndMatrix.h"

#include "RegArchDef.h"
#include "cAbstCondMean.h"
#include "cAbstCondVar.h"
#include "cAbstResiduals.h"

#include "cConst.h"
#include "cAr.h"
#include "cMa.h"

#include "cConstCondVar.h"
#include "cArch.h"
#include "cGarch.h"

#include "cNormResiduals.h"

#include "cCondMean.h"
#include "cCondVar.h"
#include "RegArchCompute.h"
#include "cRegArchModel.h"
#include "cRegArchValue.h"

#define WIN32_LEAN_AND_MEAN             // Exclure les en-tetes Windows rarement utilises



// TODO: faites reference ici aux en-tetes supplementaires necessaires au programme
