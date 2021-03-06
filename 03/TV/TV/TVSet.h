#pragma once
#include "stdafx.h"

class CTVSet
{
public:
	void TurnOn();
	void TurnOff();
	bool SelectChannel(int channelNum);
	bool SelectChannel(std::string channelName);
	int GetChannel() const;
	bool IsTurnedOn() const;
	void SelectPreviousChannel();
	bool SetChannelName(int channelNum, std::string channelName);
	bool DeleteChannelName(std::string channelName);
	std::string GetChannelName(int channelNum);
	int GetChannelByName(std::string channelName);
	std::map<int, std::string> GetChannelsMap();
	bool isChannelInRange(int channel);

private:
	int m_selectedChannel = 1;
	bool m_isOn = false;
	int m_previosChannel = 1;
	std::string m_channelName;
	std::map<int, std::string> m_channelsMap;
};