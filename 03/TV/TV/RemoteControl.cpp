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
	m_output << "TV is turned on"
			 << "\n";
	return true;
}

bool CRemoteControl::TurnOff(std::istream& /*args*/)
{
	m_tv.TurnOff();
	m_output << "TV is turned off"
			 << "\n";
	return true;
}

bool CRemoteControl::Info(std::istream& /*args*/)
{
	string info = (m_tv.IsTurnedOn())
		? ("TV is turned on\nChannel is: " + to_string(m_tv.GetChannel()) + "\n")
		: "TV is turned off\n";

	m_output << info;

	return true;
}

bool CRemoteControl::SelectChannel(std::istream& args)
{
	int channelNum;
	args >> channelNum;
	m_tv.SelectChannel(channelNum);
	m_output << "Selected channel: " << m_tv.GetChannel() << "\n";
	return true;
}

bool CRemoteControl::SelectPreviosChannel(std::istream& /*args*/)
{
	m_tv.SelectPreviousChannel();
	m_output << "Previos channel is: " << m_tv.GetChannel() << "\n";
	return true;
}

bool CRemoteControl::SetChannelName(std::istream& args)
{
	int channelNum;
	string channelName;
	args >> channelNum;
	getline(args, channelName);
	m_tv.SetChannelName(channelNum, channelName);
	m_output << m_tv.GetChannelByName(channelName) << " - " << m_tv.GetChannelName(channelNum) << "\n";
	return true;
}

bool CRemoteControl::GetChannelName(std::istream& args)
{
	int channelNum;
	args >> channelNum;
	m_tv.GetChannelName(channelNum);
	m_output << "Channel name is " << m_tv.GetChannelName(channelNum) << "\n";
	return true;
}

bool CRemoteControl::GetChannelByName(std::istream& args)
{
	string channelName;
	getline(args, channelName);
	m_output << channelName << endl;
	m_tv.GetChannelByName(channelName);
	m_output << "Channel number is " << m_tv.GetChannelByName(channelName) << "\n";
	return true;
}

bool CRemoteControl::DeleteChannelName(std::istream& args)
{
	string channelName;
	args >> channelName;
	m_tv.DeleteChannelName(channelName);
	m_output << "Channel " << channelName << " deleted\n ";
	return true;
}
