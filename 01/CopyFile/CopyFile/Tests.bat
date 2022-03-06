@echo off

REM ���� � ����������� ��������� ���������� ����� 1-� �������� ��������� ������
SET MyProgram="%~1"

REM ������ ������� ��� ���������, ��������� ���� � ���������
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM Copy empty file
%MyProgram% empty.txt "%TEMP%\output.txt" || goto err
fc empty.txt "%TEMP%\output.txt" > nul  || goto err
echo Test 1 passed

REM Copy non empty file
%MyProgram% NonEmptyFile.txt "%TEMP%\output.txt" || goto err
fc NonEmptyFile.txt "%TEMP%\output.txt" > nul || goto err
echo Test 2 passed

REM Copy missing file should fail
%MyProgram% MissingFile.txt "%TEMP%\output.txt" && goto err
echo Test 3 passed

REM Is output file is not specfied, program mast fail
%MyProgram% MissingFile.txt && goto err
echo Test 4 passed

REM Is input and output file are not specfied, program mast fail
%MyProgram% && goto err
echo Test 5 passed

REM ����� ������ �������
echo All tests passed successfuly
exit /B 0

REM ���� ����� �������� � ������ ������
:err
echo Test failed
exit /B 1 