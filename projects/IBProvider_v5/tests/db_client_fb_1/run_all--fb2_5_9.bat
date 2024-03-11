@SETLOCAL

@SET TEST_PARAMS=/thread_count 4 /auto /log_dir _log\fb02-5-9 /log_file_prefix "fb02-5-9" /inet_host vxp2-fb02-5-9 /db e:\database\ibp_test_fb02-5-9_d3.gdb /db_user GAMER /db_password vermut /new_db_dir e:\database\ /isc_api_library fbclient.dll /cn_str "remote:protocol=12;remote:protocol_arch=symmetric,generic"/dbms "FB-2.5" %*

target\vs2022-Win32-Debug\test_db_client_fb_1.exe %TEST_PARAMS%
@set ERRORLEVEL__win32debug=%ERRORLEVEL%
@set /A ERRORLEVEL_T=%ERRORLEVEL_T% + %ERRORLEVEL__win32debug%

target\vs2022-Win32-Release\test_db_client_fb_1.exe %TEST_PARAMS%
@set ERRORLEVEL__win32release=%ERRORLEVEL%
@set /A ERRORLEVEL_T=%ERRORLEVEL_T% + %ERRORLEVEL__win32release%

target\vs2022-x64-Debug\test_db_client_fb_1.exe %TEST_PARAMS%
@set ERRORLEVEL__x64debug=%ERRORLEVEL%
@set /A ERRORLEVEL_T=%ERRORLEVEL_T% + %ERRORLEVEL__x64debug%

target\vs2022-x64-Release\test_db_client_fb_1.exe %TEST_PARAMS%
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