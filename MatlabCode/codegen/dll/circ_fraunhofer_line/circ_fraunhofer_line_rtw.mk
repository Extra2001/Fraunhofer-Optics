###########################################################################
## Makefile generated for MATLAB file/project 'circ_fraunhofer_line'. 
## 
## Makefile     : circ_fraunhofer_line_rtw.mk
## Generated on : Tue Dec 14 17:38:14 2021
## MATLAB Coder version: 5.0 (R2020a)
## 
## Build Info:
## 
## Final product: .\circ_fraunhofer_line.dll
## Product type : dynamic-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# DEF_FILE                Definition file

PRODUCT_NAME              = circ_fraunhofer_line
MAKEFILE                  = circ_fraunhofer_line_rtw.mk
MATLAB_ROOT               = C:\PROGRA~1\Matlab
MATLAB_BIN                = C:\PROGRA~1\Matlab\bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)\win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:\Users\jingx\Projects\fraunhofer-optics\MatlabCode\codegen\dll\circ_fraunhofer_line
TGT_FCN_LIB               = ISO_C++
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
COMPILER_COMMAND_FILE     = circ_fraunhofer_line_rtw_comp.rsp
CMD_FILE                  = circ_fraunhofer_line_rtw.rsp
DEF_FILE                  = $(PRODUCT_NAME).def
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
NODEBUG                   = 1

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Microsoft Visual C++ 2019 v16.0 | nmake (64-bit Windows)
# Supported Version(s):    16.0
# ToolchainInfo Version:   2020a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# NODEBUG
# cvarsdll
# cvarsmt
# conlibsmt
# ldebug
# conflags
# cflags

#-----------
# MACROS
#-----------

MW_EXTERNLIB_DIR    = $(MATLAB_ROOT)\extern\lib\win64\microsoft
MW_LIB_DIR          = $(MATLAB_ROOT)\lib\win64
CPU                 = AMD64
APPVER              = 5.02
CVARSFLAG           = $(cvarsmt)
CFLAGS_ADDITIONAL   = -D_CRT_SECURE_NO_WARNINGS
CPPFLAGS_ADDITIONAL = -EHs -D_CRT_SECURE_NO_WARNINGS
LIBS_TOOLCHAIN      = $(conlibs)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Microsoft Visual C Compiler
CC = cl

# Linker: Microsoft Visual C Linker
LD = link

# C++ Compiler: Microsoft Visual C++ Compiler
CPP = cl

# C++ Linker: Microsoft Visual C++ Linker
CPP_LD = link

# Archiver: Microsoft Visual C/C++ Archiver
AR = lib

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)\mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: NMAKE Utility
MAKE = nmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -Zi
C_OUTPUT_FLAG       = -Fo
LDDEBUG             = /DEBUG
OUTPUT_FLAG         = -out:
CPPDEBUG            = -Zi
CPP_OUTPUT_FLAG     = -Fo
CPPLDDEBUG          = /DEBUG
OUTPUT_FLAG         = -out:
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = -out:
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @ren
RUN                 = @cmd /C

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = /nologo
CFLAGS               = $(cflags) $(CVARSFLAG) $(CFLAGS_ADDITIONAL) \
                       /O2 /Oy-
CPPFLAGS             = /TP $(cflags) $(CVARSFLAG) $(CPPFLAGS_ADDITIONAL) \
                       /O2 /Oy-
CPP_LDFLAGS          = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
CPP_SHAREDLIB_LDFLAGS  = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                         -dll -def:$(DEF_FILE)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                       -dll -def:$(DEF_FILE)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = .\circ_fraunhofer_line.dll
PRODUCT_TYPE = "dynamic-library"
BUILD_TYPE = "Dynamic Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DBUILDING_CIRC_FRAUNHOFER_LINE -DMODEL=circ_fraunhofer_line
DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=circ_fraunhofer_line

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)\rt_nonfinite.cpp $(START_DIR)\rtGetNaN.cpp $(START_DIR)\rtGetInf.cpp $(START_DIR)\circ_fraunhofer_line_data.cpp $(START_DIR)\circ_fraunhofer_line_initialize.cpp $(START_DIR)\circ_fraunhofer_line_terminate.cpp $(START_DIR)\circ_fraunhofer_line.cpp $(START_DIR)\fft2.cpp $(START_DIR)\FFTImplementationCallback.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj circ_fraunhofer_line_data.obj circ_fraunhofer_line_initialize.obj circ_fraunhofer_line_terminate.obj circ_fraunhofer_line.obj fft2.obj FFTImplementationCallback.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  /LIBPATH:"$(MATLAB_ROOT)\bin\win64" "$(MATLAB_ROOT)\bin\win64\libiomp5md.lib"

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_OPTS = /openmp /wd4101
CFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CFLAGS = $(CFLAGS) $(CFLAGS_OPTS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_OPTS = /openmp /wd4101
CPPFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS = $(CPPFLAGS) $(CPPFLAGS_OPTS) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = /nodefaultlib:vcomp  

CPP_LDFLAGS = $(CPP_LDFLAGS) $(CPP_LDFLAGS_)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = /nodefaultlib:vcomp  

CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS) $(CPP_SHAREDLIB_LDFLAGS_)

#-----------
# Linker
#-----------

LDFLAGS_ = /nodefaultlib:vcomp  

LDFLAGS = $(LDFLAGS) $(LDFLAGS_)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = /nodefaultlib:vcomp  

SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS) $(SHAREDLIB_LDFLAGS_)

###########################################################################
## INLINED COMMANDS
###########################################################################


!include $(MATLAB_ROOT)\rtw\c\tools\vcdefs.mak


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute set_environment_variables


all : build
	@cmd /C "@echo ### Successfully generated all binary outputs."


build : set_environment_variables prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


set_environment_variables : 
	@set INCLUDE=$(INCLUDES);$(INCLUDE)
	@set LIB=$(LIB)


###########################################################################
## FINAL TARGET
###########################################################################

#----------------------------------------
# Create a dynamic library
#----------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@cmd /C "@echo ### Creating dynamic library "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_SHAREDLIB_LDFLAGS) -out:$(PRODUCT) @$(CMD_FILE) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@cmd /C "@echo ### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{C:\Users\jingx\Projects\fraunhofer-optics\MatlabCode}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{C:\Users\jingx\Projects\fraunhofer-optics\MatlabCode}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


rt_nonfinite.obj : $(START_DIR)\rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\rt_nonfinite.cpp


rtGetNaN.obj : $(START_DIR)\rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\rtGetNaN.cpp


rtGetInf.obj : $(START_DIR)\rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\rtGetInf.cpp


circ_fraunhofer_line_data.obj : $(START_DIR)\circ_fraunhofer_line_data.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\circ_fraunhofer_line_data.cpp


circ_fraunhofer_line_initialize.obj : $(START_DIR)\circ_fraunhofer_line_initialize.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\circ_fraunhofer_line_initialize.cpp


circ_fraunhofer_line_terminate.obj : $(START_DIR)\circ_fraunhofer_line_terminate.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\circ_fraunhofer_line_terminate.cpp


circ_fraunhofer_line.obj : $(START_DIR)\circ_fraunhofer_line.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\circ_fraunhofer_line.cpp


fft2.obj : $(START_DIR)\fft2.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\fft2.cpp


FFTImplementationCallback.obj : $(START_DIR)\FFTImplementationCallback.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\FFTImplementationCallback.cpp


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@cmd /C "@echo ### PRODUCT = $(PRODUCT)"
	@cmd /C "@echo ### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@cmd /C "@echo ### BUILD_TYPE = $(BUILD_TYPE)"
	@cmd /C "@echo ### INCLUDES = $(INCLUDES)"
	@cmd /C "@echo ### DEFINES = $(DEFINES)"
	@cmd /C "@echo ### ALL_SRCS = $(ALL_SRCS)"
	@cmd /C "@echo ### ALL_OBJS = $(ALL_OBJS)"
	@cmd /C "@echo ### LIBS = $(LIBS)"
	@cmd /C "@echo ### MODELREF_LIBS = $(MODELREF_LIBS)"
	@cmd /C "@echo ### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@cmd /C "@echo ### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@cmd /C "@echo ### CFLAGS = $(CFLAGS)"
	@cmd /C "@echo ### LDFLAGS = $(LDFLAGS)"
	@cmd /C "@echo ### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### CPPFLAGS = $(CPPFLAGS)"
	@cmd /C "@echo ### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@cmd /C "@echo ### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### ARFLAGS = $(ARFLAGS)"
	@cmd /C "@echo ### MEX_CFLAGS = $(MEX_CFLAGS)"
	@cmd /C "@echo ### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@cmd /C "@echo ### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@cmd /C "@echo ### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@cmd /C "@echo ### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@cmd /C "@echo ### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@cmd /C "@echo ### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	@if exist $(PRODUCT) $(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


