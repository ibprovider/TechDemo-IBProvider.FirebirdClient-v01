@SETLOCAL

@SET TEST_PARAMS=/thread_count 4 /auto /log_dir "_log\fb03-0" /log_file_prefix fb03-0 /inet_host HOME4 /db d:\database\ram\ibp_test_fb30_d3.gdb /db_user GAMER /db_password vermut /new_db_dir d:\database\ram\ /isc_api_library fbclient_30.dll /cn_str "remote:protocol_arch=symmetric,generic" /dbms "FB-3" %*

target\vs2019-Win32-Debug\test_db_client_fb_1.exe %TEST_PARAMS%
@set ERRORLEVEL__win32debug=%ERRORLEVEL%
@set /A ERRORLEVEL_T=%ERRORLEVEL_T% + %ERRORLEVEL__win32debug%

target\vs2019-Win32-Release\test_db_client_fb_1.exe %TEST_PARAMS%
@set ERRORLEVEL__win32release=%ERRORLEVEL%
@set /A ERRORLEVEL_T=%ERRORLEVEL_T% + %ERRORLEVEL__win32release%

target\vs2019-x64-Debug\test_db_client_fb_1.exe %TEST_PARAMS%
@set ERRORLEVEL__x64debug=%ERRORLEVEL%
@set /A ERRORLEVEL_T=%ERRORLEVEL_T% + %ERRORLEVEL__x64debug%

target\vs2019-x64-Release\test_db_client_fb_1.exe %TEST_PARAMS%
@set ERRORLEVEL__x64release=%ERRORLEVEL%
@set /A ERRORLEVEL_T=%ERRORLEVEL_T% + %ERRORLEVEL__x64release%

@rem --------------------------------------
@ECHO.
@IF NOT %ERRORLEVEL_T% == 0 ECHO ----------- BATCH DETAILS

@IF NOT %ERRORLEVEL__win32debug% == 0    ECHO ERROR: ERRORLEVEL__win32debug    =%ERRORLEVEL__win32debug%
@IF NOT %ERRORLEVEL__win32release% == 0  ECHO ERROR: ERRORLEVEL__win32release  =%ERRORLEVEL__win32release%
@IF NOT %ERRORLEVEL__x64debug% == 0      ECHO ERROR: ERRORLEVEL__x64debug      =%ERRORLEVEL__x64debug%
@IF NOT %ERRORLEVEL__x64release% == 0    ECHO ERROR: ERRORLEVEL__x64release    =%ERRORLEVEL__x64release%

@ECHO ----------- BATCH SUMMARY

@ECHO TOTAL ERRORS: %ERRORLEVEL_T%

@ENDLOCAL