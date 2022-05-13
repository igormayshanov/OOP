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

void TestSetChannelName()
{
	CTVSet validTV;
	
	// Задать имя каналу при выключенном телевизоре
	validTV.TurnOff();
	assert(validTV.SetChannelName(1, "ORT") == false);
	
	// Включить ТВ, задать 1 каналу название ORT
	validTV.TurnOn();
	validTV.SetChannelName(1, "ORT");
	assert(validTV.GetChannelName(1) == "ORT");

	// Задать каналу имя, которое уже закреплено за каналом 1
	validTV.SetChannelName(5, "ORT");
	assert(validTV.GetChannelName(5) == "ORT");
	assert(validTV.GetChannelName(1) == "Channel has no name");

	// Изменение названия у канала с ранее закрепленным названием
	validTV.SetChannelName(5, "STS");
	assert(validTV.GetChannelName(5) == "STS");
	
	//Получить номер у канала с именем "Russia"
	validTV.SetChannelName(2, "Russia");
	assert(validTV.GetChannelByName("Russia") == 2);

	//Установить канал по имени
	validTV.SelectChannel("Russia");
	assert(validTV.GetChannel() == 2);

	//Получить номер у канала с несуществующим именем "RU"
	assert(validTV.GetChannelByName("RU") == 0);

	//Удалить канал с именем "Russia"
	assert(validTV.DeleteChannelName("Russia") == true);
	assert(validTV.GetChannelName(2) == "Channel has no name");

	//Удалить канал с несуществующим именем
	assert(validTV.DeleteChannelName("Russia") == false);
	assert(validTV.GetChannelByName("Russia") == 0);

	cout << "TV Set Channel Name test is ok\n";
}

int main()
{
	TestTVCreation();
	TestSelectPreviosChannel();
	TestSetChannelName();
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