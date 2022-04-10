#include <iostream>
#include "stdafx.h"
#include "CTVSet.h"
#include <assert.h>
#include <cstring>


using namespace std;

int getMenuItemNumber(int count);

void TestTVCreation()
{
	CTVSet validTV;

	assert(validTV.IsTurnedOn() == false);
	assert(validTV.GetChannel() == 0);

	validTV.TurnOn();
	assert(validTV.IsTurnedOn() == true);
	assert(validTV.GetChannel() == 1);

	validTV.SelectChannel(2);
	assert(validTV.GetChannel() == 2);

	validTV.TurnOff();
	assert(validTV.IsTurnedOn() == false);
	assert(validTV.GetChannel() == 0);

	validTV.SelectChannel(2);
	assert(validTV.GetChannel() == 0);

	validTV.TurnOn();
	assert(validTV.IsTurnedOn() == true);
	assert(validTV.GetChannel() == 2);
	
	validTV.SelectChannel(100);
	assert(validTV.GetChannel() == 2);

	cout << "TV creation test is ok\n";
}

void TestSelectPreviosChannel()
{
	CTVSet validTV;

	validTV.TurnOn();
	validTV.SelectPreviousChannel();
	assert(validTV.GetChannel() == 1);

	validTV.SelectChannel(2);
	validTV.SelectPreviousChannel();
	assert(validTV.GetChannel() == 1);

	validTV.SelectChannel(3);
	validTV.SelectPreviousChannel();
	assert(validTV.GetChannel() == 2);

	validTV.TurnOff();
	validTV.SelectPreviousChannel();
	assert(validTV.GetChannel() == 0);

	validTV.TurnOn();
	validTV.SelectPreviousChannel();
	assert(validTV.GetChannel() == 3);

	validTV.TurnOn();
	validTV.SelectPreviousChannel();
	assert(validTV.GetChannel() == 2);

	cout << "TV select previos channel test is ok\n";
}

int main()
{
	TestTVCreation();
	TestSelectPreviosChannel();
	CTVSet tv;
	int choice;
	bool exit = true;
	while (exit)
	{
		std::cout << "Choose an action" << std::endl;
		std::cout << "1. Turn on TV" << std::endl;
		std::cout << "2. Turn off TV" << std::endl;
		std::cout << "3. Select channel" << std::endl;
		std::cout << "4. Select previos channel" << std::endl;
		std::cout << "5. Exit" << std::endl;
		choice = getMenuItemNumber(6);
		switch (choice)
		{
		case 1:
			tv.TurnOn();
			break;
		case 2:
			tv.TurnOff();
			break;
		case 3:
			int channel;
			cout << "Enter the channel number in the range from 1 to 99: ";
			cin >> channel;
			tv.SelectChannel(channel);
			break;
		case 4:
			tv.SelectPreviousChannel();
			break;
		
		case 5:
			exit = false;
			break;
		}
		string onOrOff;
		tv.IsTurnedOn() ? onOrOff = "ON" : onOrOff = "OFF";
		cout << "TV is " << onOrOff << ", "
			 << " current channel is " << tv.GetChannel() << "\n";
	}
	return 0;
}

int getMenuItemNumber(int menuItems)
{
	int itemNumber;
	cin >> itemNumber;
	while ( itemNumber < 1 || itemNumber > menuItems)
	{
		std::cout << "Incorrect input. Try again: ";
		cin >> itemNumber;
	}
	return itemNumber;
}
