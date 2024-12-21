@title PTSource DOS Cross Compiler  
@set DJGPP=%cd%\DJGPP.ENV
@echo Setting up the variables:
@echo.
@set _tmpdir=%cd%/tmp
@set tmpdir=%_tmpdir:\=/%
@set _tmpdir=
@set path=%cd%\bin;%PATH%
@echo these are for GCC 2
@set _C_INCLUDE_PATH=%cd%/include
@SET C_INCLUDE_PATH=%_C_INCLUDE_PATH:\=/%
@set _C_INCLUDE_PATH=
@echo C_INCLUDE_PATH %C_INCLUDE_PATH%
@set _LIBRARY_PATH=%cd%/lib
@set LIBRARY_PATH=%_LIBRARY_PATH:\=/%
@set _LIBRARY_PATH=
@echo LIBRARY_PATH %LIBRARY_PATH%
@echo.
@echo setting up bison
@set _BISON_SIMPLE=%cd%/lib/bison.simple
@set BISON_SIMPLE=%_BISON_SIMPLE:\=/%
@set _BISON_SIMPLE=
@set _BISON_HAIRY=%cd%/lib/bison.hairy
@set BISON_HAIRY=%_BISON_HAIRY:\=/%
@set _BISON_HAIRY=
@echo BISON_SIMPLE %BISON_SIMPLE%
@echo BISON_HAIRY %BISON_HAIRY%
@echo.
@echo Finished. Visit us at www.wiki.ptsource.eu