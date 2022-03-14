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

REM multiplication of matrix 1 by matrix 2
%MyProgram% "matrix1.txt" "matrix2.txt" > "%TEMP%\output.txt" || goto err
fc ResultMultMatrix.txt "%TEMP%\output.txt" > nul  || goto err
echo Test 2 passed

REM ����� ������ �������
echo All tests passed successfuly
exit /B 0

REM ���� ����� �������� � ������ ������
:err
echo Test failed
exit /B 1 