@echo off

set GPP_BIN=
where /q g++.exe
if %ERRORLEVEL%==0 (
	set GPP_BIN=g++
)
if "%GPP_BIN%"=="" (
    echo "Cannot find g++ binary.\n"
    goto END
) else (
    echo "Found G++ binary.\n"
)
set CFLAGS="-std=c++17"

set BUILD_FLAGS="-O2"
@REM set BUILD_FLAGS=""

%GPP_BIN% %CFLAGS% %BUILD_FLAGS% -o sgp.exe src/main.cpp
if %ERRORLEVEL%==0 (
	echo "Done!"
)
:ENDs
timeout 10 > NUL
pause 1