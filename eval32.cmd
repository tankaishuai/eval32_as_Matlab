@echo off
cls
path %cd%\bin;%cd%\bin\win32;%cd%\work;%cd%\toolbox;%path%
color f9
:restartshell
eval32.exe
echo\
echo =========================================================
echo ��Ĵ����˳���ѡ�����������»ָ����й��ϳ���
set /p usersel=ѡ��[Y/"N"]��
echo =========================================================
if /I not "%usersel%"=="Y" (
	cls
	goto :restartshell
)
exit
@echo on