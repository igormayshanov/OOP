#include <cstring>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <cctype>

//2. Кажется излишним
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
		//1. стоит подумать как избавиться от побочных ответственностей
		std::cout << "Invalid argument count\n"
				  << "Usage: Dec2Bin.exe <number>\n";
		return std::nullopt;
	}
	Args args;
	try
	{
		if (!IsNumber(argv[1]))
		{
			//3. странно что в одном месте используется исключение, в другом просто вывод в поток
			throw std::invalid_argument("Argument is not number");
		}
		int number = std::stoi(argv[1]);
		if (number >= 0)
		{
			args.number = number;
			return args;
		}
		else
		{
			throw std::invalid_argument ("Entered number is less than 0");
		}
	}
	catch (std::invalid_argument& e)
	{
		//1. разобраться с выводами, не стоит мешать с логикой
		std::cout << "Invalid arguments\n"
				  << "Usage: Dec2Bin.exe <number>. "
				  << e.what()<<"\n ";
	}
	catch (std::logic_error& err)
	{
		std::cout << "Error, incorrect data: " << err.what() << '\n';

	}
	return std::nullopt;
}

// проверка на nullopt была, может можно передавать уже Args?
void PrintDec2Bin(std::optional<Args>& args)
{
	bool printDigitFlag = false;
	short numberDigit;
	//magic num 31
	for (int i = 31; i >= 0; i--)
	{
		numberDigit = ((args->number >> i) & 0b1);
		if (!printDigitFlag && numberDigit)
		{
			printDigitFlag = true;
		}
		if (printDigitFlag)
		{
			//3 Нужно разделить логику и вывод
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
