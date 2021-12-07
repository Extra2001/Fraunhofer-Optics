@echo off
call setEnv.bat
"C:\Program Files\Matlab\toolbox\shared\coder\ninja\win64\ninja.exe" -v %*
