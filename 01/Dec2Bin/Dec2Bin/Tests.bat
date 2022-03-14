@echo off

REM Путь к тестируемой программе передается через 1-й аргумент командной строки
SET MyProgram="%~1"

REM Защита запуска без аргумента, задающего путь к программе
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

REM Enter not number argument
%MyProgram% "1a" && goto err
echo Test 6 passed

REM Enter not number argument
%MyProgram% "a1" && goto err
echo Test 7 passed

REM Enter not number argument
%MyProgram% "a" && goto err
echo Test 8 passed


REM Тесты прошли успешно
echo All tests passed successfuly
exit /B 0

REM Сюда будем попадать в случае ошибки
:err
echo Test failed
exit /B 1 