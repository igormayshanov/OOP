#include <cstring>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <cctype>

struct Args
{
	int number;
};

bool IsNumber(std::string argvToCheck)
{
	for (char ch : argvToCheck)
	{
		if (!isdigit(ch))
		{
			return false;
		}
	}
	return true;
}

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid argument count\n"
				  << "Usage: Dec2Bin.exe <number>\n";
		return std::nullopt;
	}
	Args args;
	try
	{
		if (!IsNumber(argv[1]))
		{
			throw std::invalid_argument("Argument is not number");
		}
		int number = std::stol(argv[1]);
		if (number >= 0)
		{
			args.number = number;
			return args;
		}
		else
		{
			std::cout << "Invalid argument " << number << ". Entered number is less than 0\n";
		}
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "Invalid arguments\n"
				  << "Usage: Dec2Bin.exe <number>. "
				  << e.what()<<"\n ";
	}
	catch (std::out_of_range& oor)
	{
		std::cout << "Out of Range error: " << oor.what() << '\n';

	}
	return std::nullopt;
}

void PrintDec2Bin(std::optional<Args>& args)
{
	bool printDigitFlag = false;
	short numberDigit;
	for (int i = 31; i >= 0; i--)
	{
		numberDigit = ((args->number >> i) & 0b1);
		if (!printDigitFlag && numberDigit)
		{
			printDigitFlag = true;
		}
		if (printDigitFlag)
		{
			std::cout << numberDigit;
		}
	}
	if (!printDigitFlag)
	{
		std::cout << numberDigit;
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}
	PrintDec2Bin(args);
	return 0;
}
