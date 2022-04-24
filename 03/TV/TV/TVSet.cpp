#include "TVSet.h"
#include <algorithm>

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
bool CTVSet::SelectChannel(int channel)
{
	int minChannel = 1;
	int maxChannel = 99;
	if (m_isOn && channel >= minChannel && channel <= maxChannel)
	{
		m_previosChannel = m_selectedChannel;
		m_selectedChannel = channel;
		return true;
	}	
	return false;
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