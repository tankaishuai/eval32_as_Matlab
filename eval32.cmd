@echo off
cls
path %cd%\bin;%cd%\bin\win32;%cd%\work;%cd%\toolbox;%path%
color f9
:restartshell
eval32.exe
echo\
echo =========================================================
echo 真的打算退出吗？选择其他将重新恢复运行故障程序？
set /p usersel=选择[Y/"N"]？
echo =========================================================
if /I not "%usersel%"=="Y" (
	cls
	goto :restartshell
)
exit
@echo on