
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

void PrintMatrix(Matrix3x3 matr)
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			std::cout.width(15);
			std::cout.setf(std::ios::fixed);
			std::cout.precision(3);
			std::cout << matr[i][j];
		}
		std::cout << "\n";
	}
}

std::optional<WrappedMatrix3x3> ReadFileInMatrix(std::string fileName)
{
	std::ifstream input;
	input.open(fileName);
	if (!input.is_open())
	{
		std::cout << "Failed to open '" << fileName << "' for reading\n";
		return std::nullopt;
	}
	WrappedMatrix3x3 wrappedMat = {};
	float matrixCoefficient;
	std::string s;
	int i = 0;
	while (!input.eof())
	{
		
		if (i >= MATRIX_SIZE)
		{
			return std::nullopt;
		}
		getline(input, s);
		std::stringstream ss;
		ss.str(s);
		int j = 0;
		while (!ss.eof())
		{
			ss >> matrixCoefficient;
			if (ss.fail())
			{
				std::cout << "Invalid matrix in file ss >> matrixCoef\n";
				return std::nullopt;
			}
			/*if (!(ss >> matrixCoefficient))
			{
				std::cout << "Invalid matrix in file ss >> matrixCoef\n";
				return std::nullopt;
			}*/
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
		
		i++;
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

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: MultMatrix.exe <input file name 1> <input file name 2>\n";
		return 1;
	}
	auto matrix1 = ReadFileInMatrix(args->inputFileName1);
	if (!matrix1)
	{
		std::cout << "Invalid matrix in file\n";
		std::cout << "Matrix size should be 3*3 and contain only numbers\n";
		return 1;
	}
	auto matrix2 = ReadFileInMatrix(args->inputFileName2);
	if (!matrix2)
	{
		std::cout << "Invalid matrix in file\n";
		std::cout << "Matrix size should be 3*3 and contain only numbers\n";
		return 1;
	}

	PrintMatrix(matrix1->items);
	PrintMatrix(matrix2->items);

	WrappedMatrix3x3 multMatrix = MultMatrix(*matrix1, *matrix2);
	PrintMatrix(multMatrix.items);

	return 0;
}
