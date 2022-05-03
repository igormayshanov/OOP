#include "stdafx.h"
#include "TVSet.h"

using namespace std;

void CTVSet::TurnOn()
{
	if (!m_isOn)
		m_isOn = true;
}
void CTVSet::TurnOff()
{
	if (m_isOn)
		m_isOn = false;
}

bool CTVSet::isChannelInRange(int channel)
{
	int minChannel = 1;
	int maxChannel = 99;
	return (channel >= minChannel && channel <= maxChannel) ? true : false;
}

bool CTVSet::SelectChannel(int channelNum)
{
	if (m_isOn && isChannelInRange(channelNum))
	{
		m_previosChannel = m_selectedChannel;
		m_selectedChannel = channelNum;
		return true;
	}
	return false;
}

bool CTVSet::SelectChannel(std::string channelName)
{
	return SelectChannel(GetChannelByName(channelName));
}

int CTVSet::GetChannel() const
{
	return m_isOn ? m_selectedChannel : 0;
}

bool CTVSet::IsTurnedOn() const
{
	return m_isOn;
}

void CTVSet::SelectPreviousChannel()
{
	if (m_isOn)
		std::swap(m_selectedChannel, m_previosChannel);
}

std::map<int, std::string> CTVSet::GetChannelsMap()
{
	return m_channelsMap;
}

bool CTVSet::SetChannelName(int channelNum, std::string channelName)
{
	if (m_isOn && isChannelInRange(channelNum))
	{
		for (auto channel = m_channelsMap.begin(); channel != m_channelsMap.end();)
		{
			if (channel->second == channelName || channel->first == channelNum)
			{
				channel = m_channelsMap.erase(channel);
			}
			else
			{
				channel++;
			}
		}
		m_channelsMap.insert(make_pair(channelNum, channelName));
		return true;
	}
	return false;
}

std::string CTVSet::GetChannelName(int channelNum)
{
	if (m_isOn)
	{
		auto it = m_channelsMap.find(channelNum);
		if (it != m_channelsMap.end())
		{
			return it->second;
		}
	}
	return "Channel has no name";
}

int CTVSet::GetChannelByName(string channelName)
{
	if (m_isOn)
	{
		for (const auto& channel : m_channelsMap)
		{
			if (channelName == channel.second)
			{
				return channel.first;
			}
		}
	}
	return 0;
}

bool CTVSet::DeleteChannelName(std::string channelName)
{
	if (!m_isOn)
	{
		return false;
	}
	for (auto channel = m_channelsMap.begin(); channel != m_channelsMap.end();)
	{
		if (channel->second == channelName)
		{
			channel = m_channelsMap.erase(channel);
			return true;
		}
		else
		{
			channel++;
		}
	}
	return false;
}