@echo off

REM ���� � ����������� ��������� ���������� ����� 1-� �������� ��������� ������
SET MyProgram="%~1"

REM ������ ������� ��� ���������, ��������� ���� � ���������
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM Enter empty argument
%MyProgram% && goto err
echo Test 1 passed

REM Enter min argument > 0
%MyProgram% "1" > "%TEMP%\output.txt" || goto err
fc MinDigit.txt "%TEMP%\output.txt" > nul  || goto err
echo Test 2 passed

REM Enter min argument
%MyProgram% "0" > "%TEMP%\output.txt" || goto err
fc CheckNull.txt "%TEMP%\output.txt" > nul  || goto err
echo Test 3 passed

REM Enter max argument
%MyProgram% "2147483647" > "%TEMP%\output.txt" || goto err
fc MaxDigit.txt "%TEMP%\output.txt" > nul  || goto err
echo Test 4 passed

REM Enter number > max argument
%MyProgram% 2147483648 && goto err
echo Test 5 passed

REM ����� ������ �������
echo All tests passed successfuly
exit /B 0

REM ���� ����� �������� � ������ ������
:err
echo Test failed
exit /B 1 