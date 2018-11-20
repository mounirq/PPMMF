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
	${OBJECTDIR}/Source/Tests.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../VectorAndMatrix/build/Debug/GNU-Linux-x86 -L../Error/build/Debug/GNU-Linux-x86 -Wl,-rpath,../VectorAndMatrix/dist/Debug/GNU-Linux -L../VectorAndMatrix/dist/Debug/GNU-Linux -lVectorAndMatrix -Wl,-rpath,../Error/dist/Debug/GNU-Linux -L../Error/dist/Debug/GNU-Linux -lError -lgsl -lgslcblas

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tests

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tests: ../VectorAndMatrix/dist/Debug/GNU-Linux/libVectorAndMatrix.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tests: ../Error/dist/Debug/GNU-Linux/libError.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tests: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tests ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Source/Tests.o: Source/Tests.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../Error/Headers -I../VectorAndMatrix/Headers -I../RegArchLib/Headers -IHeaders -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/Tests.o Source/Tests.cpp

# Subprojects
.build-subprojects:
	cd ../VectorAndMatrix && ${MAKE}  -f Makefile CONF=Debug
	cd ../Error && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Subprojects
.clean-subprojects:
	cd ../VectorAndMatrix && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../Error && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
