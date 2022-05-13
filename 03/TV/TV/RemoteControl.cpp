#include "stdafx.h"
#include "RemoteControl.h"
#include "TVSet.h"

using namespace std;
using namespace std::placeholders;

CRemoteControl::CRemoteControl(CTVSet& tv, std::istream& input, std::ostream& output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		  { "TurnOn", [this](istream& strm) {
			   return TurnOn(strm);
		   } },
		  { "TurnOff", bind(&CRemoteControl::TurnOff, this, std::placeholders::_1) }, //
		  { "Info", bind(&CRemoteControl::Info, this, _1) },
		  { "SelectChannel", bind(&CRemoteControl::SelectChannel, this, _1) },
		  { "SelectPreviosChannel", bind(&CRemoteControl::SelectPreviosChannel, this, _1) },
		  { "SetChannelName", bind(&CRemoteControl::SetChannelName, this, _1) },
		  { "GetChannelName", bind(&CRemoteControl::GetChannelName, this, _1) },
		  { "GetChannelByName", bind(&CRemoteControl::GetChannelByName, this, _1) },
		  { "DeleteChannelName", bind(&CRemoteControl::DeleteChannelName, this, _1) },

	  })
{
}

bool CRemoteControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);
	int channelNum;
	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}
	return false;
}

bool CRemoteControl::TurnOn(std::istream& /*args*/)
{
	m_tv.TurnOn();
	m_output << "TV is turned on\n";
	return true;
}

bool CRemoteControl::TurnOff(std::istream& /*args*/)
{
	m_tv.TurnOff();
	m_output << "TV is turned off\n";
	return true;
}

bool CRemoteControl::Info(std::istream& /*args*/)
{
	if (m_tv.IsTurnedOn())
	{
		m_output << ("TV is turned on\nChannel is: " + to_string(m_tv.GetChannel()) + "\n");
		for (const auto& channel : m_tv.GetChannelsMap())
		{
			m_output << channel.first << " - " << channel.second << "\n";
		}
	}
	else
	{
		m_output << TurnedOffMessage;
	}
	return true;
}

bool CRemoteControl::SelectChannel(std::istream& args)
{
	if (m_tv.IsTurnedOn())
	{
		int channelNum;
		args >> channelNum;
		if (!args.fail())
		{
			if (m_tv.isChannelInRange(channelNum))
			{
				m_tv.SelectChannel(channelNum);
				m_output << "Selected channel: " << m_tv.GetChannel() << "\n";
			}
			else
			{
				m_output << "Invalid channel\n";
			}
		}
		else
		{
			args.clear();
			string channelName;
			args >> channelName;
			m_tv.SelectChannel(channelName);
			m_output << "Selected channel: " << m_tv.GetChannel() << "\n";
		}
	}
	else
	{
		m_output << TurnedOffMessage;
	}
	return true;
}

bool CRemoteControl::SelectPreviosChannel(std::istream& /*args*/)
{
	if (m_tv.IsTurnedOn())
	{
		m_tv.SelectPreviousChannel();
		m_output << "Previos channel is: " << m_tv.GetChannel() << "\n";
	}
	else
	{
		m_output << TurnedOffMessage;
	}
	return true;
}

bool CRemoteControl::SetChannelName(std::istream& args)
{
	if (m_tv.IsTurnedOn())
	{
		int channelNum;
		string str;
		args >> channelNum;
		getline(args, str);
		string channelName = RemoveExtraSpaces(str);
		if (!channelName.empty())
		{
			m_tv.SetChannelName(channelNum, channelName);
			m_output << m_tv.GetChannelByName(channelName) << " - " << m_tv.GetChannelName(channelNum) << "\n";
		}
		else
			m_output << "Channel name is empty \n";
	}
	else
	{
		m_output << TurnedOffMessage;
	}
	return true;
}

bool CRemoteControl::GetChannelName(std::istream& args)
{
	if (m_tv.IsTurnedOn())
	{
		int channelNum;
		args >> channelNum;
		m_tv.GetChannelName(channelNum);
		m_output << "Channel name is " << m_tv.GetChannelName(channelNum) << "\n";
	}
	else
	{
		m_output << TurnedOffMessage;
	}
	return true;
}

bool CRemoteControl::GetChannelByName(std::istream& args)
{
	if (m_tv.IsTurnedOn())
	{
		string channelName;
		getline(args, channelName);
		m_output << channelName << endl;
		m_tv.GetChannelByName(channelName);
		m_output << "Channel number is " << m_tv.GetChannelByName(channelName) << "\n";
	}
	else
	{
		m_output << TurnedOffMessage;
	}
	return true;
}

bool CRemoteControl::DeleteChannelName(std::istream& args)
{
	if (m_tv.IsTurnedOn())
	{
		string channelName;
		args >> channelName;
		m_tv.DeleteChannelName(channelName);
		m_output << "Channel " << channelName << " deleted\n ";
	}
	else
	{
		m_output << TurnedOffMessage;
	}
	return true;
}

std::string CRemoteControl::RemoveExtraSpaces(std::string const& str)
{
	if (!str.empty())
	{
		std::string outputStr;
		size_t strBegin = str.find_first_not_of(' ');
		size_t strEnd = str.find_last_not_of(' ');
		if (strBegin != std::string::npos && strEnd != std::string::npos)
		{
			std::unique_copy(str.begin() + strBegin, str.begin() + strEnd + 1, std::back_inserter(outputStr),
				[](char c1, char c2) {
					return c1 == ' ' && c2 == ' ';
				});
			return outputStr;
		}
		else
			return "";
	}
	else
	{
		return "";
	}
}