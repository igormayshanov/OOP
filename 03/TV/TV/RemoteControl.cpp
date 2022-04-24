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
	  })
{
}

bool CRemoteControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);
	int channel;
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
	m_output << "TV is turned on" << endl;
	return true;
}

bool CRemoteControl::TurnOff(std::istream& /*args*/)
{
	m_tv.TurnOff();
	m_output << "TV is turned off" << endl;
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
	int channel;
	args >> channel;
	m_tv.SelectChannel(channel);
	m_output << "Selected channel: " << m_tv.GetChannel() << endl;
	return true;
}

bool CRemoteControl::SelectPreviosChannel(std::istream& /*args*/)
{
	m_tv.SelectPreviousChannel();
	m_output << "Previos channel is: " << m_tv.GetChannel() << endl;
	return true;
}