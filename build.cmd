@echo off

set GCC_BIN=
where /q g++.exe
if %ERRORLEVEL%==0 (
	set GCC_BIN=g++
)
if "%GCC_BIN%"=="" (
    echo "Cannot find g++ binary.\n"
    goto END
) else (
    echo "Found G++ binary.\n"
)
set CFLAGS="-std=c++17"

set BUILD_FLAGS="-O2"
@REM set BUILD_FLAGS=""

%GCC_BIN% %CFLAGS% %BUILD_FLAGS% -o sgp.exe src/main.cpp
if %ERRORLEVEL%==0 (
	echo "Done!"
)
:ENDs
timeout 10 > NUL
pause 1