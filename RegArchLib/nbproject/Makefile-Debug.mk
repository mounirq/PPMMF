#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Sources/RegArchCompute.o \
	${OBJECTDIR}/Sources/StdAfxRegArchLib.o \
	${OBJECTDIR}/Sources/cAbstCondMean.o \
	${OBJECTDIR}/Sources/cAbstCondVar.o \
	${OBJECTDIR}/Sources/cAbstResiduals.o \
	${OBJECTDIR}/Sources/cAr.o \
	${OBJECTDIR}/Sources/cArch.o \
	${OBJECTDIR}/Sources/cCondMean.o \
	${OBJECTDIR}/Sources/cCondVar.o \
	${OBJECTDIR}/Sources/cConst.o \
	${OBJECTDIR}/Sources/cConstCondVar.o \
	${OBJECTDIR}/Sources/cGarch.o \
	${OBJECTDIR}/Sources/cMa.o \
	${OBJECTDIR}/Sources/cNormResiduals.o \
	${OBJECTDIR}/Sources/cRegArchGradient.o \
	${OBJECTDIR}/Sources/cRegArchModel.o \
	${OBJECTDIR}/Sources/cRegArchValue.o \
	${OBJECTDIR}/Sources/cStudentResiduals.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-D_DEBUG
CXXFLAGS=-D_DEBUG

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libRegArchLib.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libRegArchLib.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libRegArchLib.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/Sources/RegArchCompute.o: Sources/RegArchCompute.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/RegArchCompute.o Sources/RegArchCompute.cpp

${OBJECTDIR}/Sources/StdAfxRegArchLib.o: Sources/StdAfxRegArchLib.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/StdAfxRegArchLib.o Sources/StdAfxRegArchLib.cpp

${OBJECTDIR}/Sources/cAbstCondMean.o: Sources/cAbstCondMean.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cAbstCondMean.o Sources/cAbstCondMean.cpp

${OBJECTDIR}/Sources/cAbstCondVar.o: Sources/cAbstCondVar.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cAbstCondVar.o Sources/cAbstCondVar.cpp

${OBJECTDIR}/Sources/cAbstResiduals.o: Sources/cAbstResiduals.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cAbstResiduals.o Sources/cAbstResiduals.cpp

${OBJECTDIR}/Sources/cAr.o: Sources/cAr.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cAr.o Sources/cAr.cpp

${OBJECTDIR}/Sources/cArch.o: Sources/cArch.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cArch.o Sources/cArch.cpp

${OBJECTDIR}/Sources/cCondMean.o: Sources/cCondMean.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cCondMean.o Sources/cCondMean.cpp

${OBJECTDIR}/Sources/cCondVar.o: Sources/cCondVar.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cCondVar.o Sources/cCondVar.cpp

${OBJECTDIR}/Sources/cConst.o: Sources/cConst.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cConst.o Sources/cConst.cpp

${OBJECTDIR}/Sources/cConstCondVar.o: Sources/cConstCondVar.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cConstCondVar.o Sources/cConstCondVar.cpp

${OBJECTDIR}/Sources/cGarch.o: Sources/cGarch.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cGarch.o Sources/cGarch.cpp

${OBJECTDIR}/Sources/cMa.o: Sources/cMa.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cMa.o Sources/cMa.cpp

${OBJECTDIR}/Sources/cNormResiduals.o: Sources/cNormResiduals.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cNormResiduals.o Sources/cNormResiduals.cpp

${OBJECTDIR}/Sources/cRegArchGradient.o: Sources/cRegArchGradient.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cRegArchGradient.o Sources/cRegArchGradient.cpp

${OBJECTDIR}/Sources/cRegArchModel.o: Sources/cRegArchModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cRegArchModel.o Sources/cRegArchModel.cpp

${OBJECTDIR}/Sources/cRegArchValue.o: Sources/cRegArchValue.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cRegArchValue.o Sources/cRegArchValue.cpp

${OBJECTDIR}/Sources/cStudentResiduals.o: Sources/cStudentResiduals.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -IHeaders -I../Error/Headers -I../VectorAndMatrix/Headers -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/cStudentResiduals.o Sources/cStudentResiduals.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libRegArchLib.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
