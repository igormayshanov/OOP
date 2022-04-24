#include "stdafx.h"
#include "TVSet.h"
#include "RemoteControl.h"

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

	validTV.SelectChannel(2);
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
	CRemoteControl remoteControl(tv, cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!remoteControl.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
	return 0;
}