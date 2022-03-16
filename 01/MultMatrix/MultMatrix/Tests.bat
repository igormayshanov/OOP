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

REM multiplication of matrix 1 by matrix 2
%MyProgram% "matrix1.txt" "matrix2.txt" > "%TEMP%\output.txt" || goto err
fc ResultMultMatrix.txt "%TEMP%\output.txt" > nul  || goto err
echo Test 2 passed

REM enter a smaller matrix
%MyProgram% "matrix1.txt" "matrix2x2.txt" > "%TEMP%\output.txt" || goto err
fc ResultMatrix2x2.txt "%TEMP%\output.txt" > nul  || goto err
echo Test 3 passed

REM enter a bigger matrix
%MyProgram% "matrix1.txt" "matrix4x4.txt" && goto err
echo Test 4 passed

REM enter a matrix whith not number literals
%MyProgram% "matrix1.txt" "MatrixWithNotNumberCoeffic.txt" && goto err
echo Test 5 passed

REM enter a matrix whith null coefficient
%MyProgram% "matrix1.txt" "NullMatrix.txt" > "%TEMP%\output.txt" || goto err
fc MultNullMatrixResult.txt "%TEMP%\output.txt" > nul  || goto err
echo Test 6 passed

REM input missing file should fail
%MyProgram% "matrix1.txt" "Matrix.txt" && goto err
echo Test 7 passed

REM input empty file should fail
%MyProgram% "matrix1.txt" "EmptyFile.txt" && goto err
echo Test 8 passed

REM Тесты прошли успешно
echo All tests passed successfuly
exit /B 0		

REM Сюда будем попадать в случае ошибки
:err
echo Test failed
exit /B 1 