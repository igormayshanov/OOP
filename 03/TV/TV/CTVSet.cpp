#include "CTVSet.h"
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
void CTVSet::SelectChannel(int channel)
{
	int minChannel = 1;
	int maxChannel = 99;
	if (channel >= minChannel && channel <= maxChannel && m_isOn)
		m_selectedChannel = channel;
}
int CTVSet::GetChannel() const
{
	if (!m_isOn)
		return 0;
	return m_selectedChannel;
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
