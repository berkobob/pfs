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
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Particle.o \
	${OBJECTDIR}/Screen.o \
	${OBJECTDIR}/Swarm.o \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpptut8.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpptut8.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpptut8 ${OBJECTFILES} ${LDLIBSOPTIONS} -lmingw32 -lSDL2main -lSDL2

${OBJECTDIR}/Particle.o: Particle.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ISDL2-2.0.8/include -ISDL2-2.0.8/lib/x86 -include SDL2-2.0.8/include/SDL.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Particle.o Particle.cpp

${OBJECTDIR}/Screen.o: Screen.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ISDL2-2.0.8/include -ISDL2-2.0.8/lib/x86 -include SDL2-2.0.8/include/SDL.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Screen.o Screen.cpp

${OBJECTDIR}/Swarm.o: Swarm.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ISDL2-2.0.8/include -ISDL2-2.0.8/lib/x86 -include SDL2-2.0.8/include/SDL.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Swarm.o Swarm.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ISDL2-2.0.8/include -ISDL2-2.0.8/lib/x86 -include SDL2-2.0.8/include/SDL.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
