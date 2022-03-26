#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>

const int MATRIX_SIZE = 3;

typedef float Matrix3x3[MATRIX_SIZE][MATRIX_SIZE];

struct WrappedMatrix3x3
{
	Matrix3x3 items;
};

struct Args
{
	std::string inputFileName1;
	std::string inputFileName2;
};

std::optional<Args> ParseArgs(int argc, char* argv[]);
std::optional<std::ifstream> OpenFile(std::string fileName);
std::optional<WrappedMatrix3x3> GetMatrixFromInput(std::ifstream& input);
WrappedMatrix3x3 MultMatrix(WrappedMatrix3x3 matrix1, WrappedMatrix3x3 matrix2);
void PrintMatrix(Matrix3x3 matr);

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: MultMatrix.exe <input file name 1> <input file name 2>\n";
		return 1;
	}
	auto inputFile1 = OpenFile(args->inputFileName1);
	if (!inputFile1)
	{
		std::cout << "Failed to open '" << args->inputFileName1 << "' for reading\n";
		return 1;
	}
	auto matrix1 = GetMatrixFromInput(*inputFile1);
	if (!matrix1)
	{
		std::cout << "Invalid matrix in file\n";
		std::cout << "Matrix size should be 3*3 and contain only numbers\n";
		return 1;
	}
	auto inputFile2 = OpenFile(args->inputFileName2);
	if (!inputFile2)
	{
		std::cout << "Failed to open '" << args->inputFileName2 << "' for reading\n";
		return 1;
	}
	auto matrix2 = GetMatrixFromInput(*inputFile2);
	if (!matrix2)
	{
		std::cout << "Invalid matrix in file\n";
		std::cout << "Matrix size should be 3*3 and contain only numbers\n";
		return 1;
	}
	WrappedMatrix3x3 multMatrix = MultMatrix(*matrix1, *matrix2);
	PrintMatrix(multMatrix.items);

	return 0;
}

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		return std::nullopt;
	}
	Args args;
	args.inputFileName1 = argv[1];
	args.inputFileName2 = argv[2];
	return args;
}

std::optional<std::ifstream> OpenFile(std::string fileName)
{
	std::ifstream input;
	input.open(fileName);
	if (!input.is_open())
	{
		// 1. попробуй отделить вывод ошибок от логики
		return std::nullopt;
	}
	else
	{
		return input;
	}
}

std::optional<WrappedMatrix3x3> FillMatrixFromInput(std::ifstream& input)
{
	// 4. попробуй декомпозировать
	WrappedMatrix3x3 wrappedMat = {};
	float matrixCoefficient;
	std::string stringFromFile;
	int i = 0;
	while (!input.eof())
	{
		// 3. стоит добавить проверку на то что данных меньше чем нужно (матрица 2х2)
		if (i >= MATRIX_SIZE)
		{
			return std::nullopt;
		}
		// 2. приходится догадываться что такое s и ss
		getline(input, stringFromFile);
		std::stringstream stringStream;
		stringStream.str(stringFromFile);
		int j = 0;
		while (!stringStream.eof())
		{
			stringStream >> matrixCoefficient;
			if (stringStream.fail())
			{
				return std::nullopt;
			}
			if (j >= MATRIX_SIZE)
			{
				return std::nullopt;
			}
			else
			{
				wrappedMat.items[i][j] = matrixCoefficient;
			}
			j++;
		}
		if (j < MATRIX_SIZE)
		{
			return std::nullopt;
		}
		i++;
	}
	if (i < MATRIX_SIZE)
	{
		return std::nullopt;
	}
	if (input.bad())
	{
		std::cout << "Failed to read data from input file\n";
		return std::nullopt;
	}
	return wrappedMat;
}

WrappedMatrix3x3 MultMatrix(WrappedMatrix3x3 matrix1, WrappedMatrix3x3 matrix2)
{
	WrappedMatrix3x3 resultMatrix = {};
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			for (int r = 0; r < MATRIX_SIZE; r++)
			{
				resultMatrix.items[i][j] += matrix1.items[i][r] * matrix2.items[r][j];
			}
		}
	}
	return resultMatrix;
}


void PrintMatrix(Matrix3x3 matr)
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			std::cout.setf(std::ios::fixed);
			std::cout.precision(3);
			std::cout << matr[i][j] << " ";
		}
		std::cout << "\n";
	}
}