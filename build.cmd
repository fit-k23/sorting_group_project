@echo off

set GPP_BIN=
where /q g++.exe
if %ERRORLEVEL%==0 (
	set GPP_BIN=g++
)
if "%GPP_BIN%"=="" (
    echo Cannot find g++ binary.
    goto END
) else (
    echo Found G++ binary.
)
set CFLAGS="-std=c++17"

set BUILD_FLAGS="-O2"
@REM set BUILD_FLAGS=""

del /f /q /a src\sort.h

echo:

echo // Auto-generated by gcc build script. >> src/sort.h

for /f %%f in ('dir /b "src/sort/" ^| findstr ".cpp"') do (
    echo #include ^"sort/%%f^" >> src/sort.h
    echo Added src/sort/%%f to src/sort.h.
)

%GPP_BIN% %CFLAGS% %BUILD_FLAGS% -o sgp.exe src/main.cpp

if %ERRORLEVEL%==0 (
    echo:
	echo Done! Press enter to exit or wait 10s...
)
:ENDs
timeout 10 > NUL
@REM pause 1
