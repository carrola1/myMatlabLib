@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2012b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2012b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=myBERToolMex_x
set MEX_NAME=myBERToolMex_x
set MEX_EXT=.mexw64
call mexopts.bat
echo # Make settings for myBERToolMex > myBERToolMex_mex.mki
echo COMPILER=%COMPILER%>> myBERToolMex_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> myBERToolMex_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> myBERToolMex_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> myBERToolMex_mex.mki
echo LINKER=%LINKER%>> myBERToolMex_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> myBERToolMex_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> myBERToolMex_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> myBERToolMex_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> myBERToolMex_mex.mki
echo BORLAND=%BORLAND%>> myBERToolMex_mex.mki
echo OMPFLAGS= >> myBERToolMex_mex.mki
echo OMPLINKFLAGS= >> myBERToolMex_mex.mki
echo EMC_COMPILER=msvcsdk>> myBERToolMex_mex.mki
echo EMC_CONFIG=optim>> myBERToolMex_mex.mki
"C:\Program Files\MATLAB\R2012b\bin\win64\gmake" -B -f myBERToolMex_mex.mk
