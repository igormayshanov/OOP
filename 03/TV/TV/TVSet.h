#pragma once
class CTVSet
{
public:
	void TurnOn();
	void TurnOff();
	bool SelectChannel(int channel);
	int GetChannel() const;
	bool IsTurnedOn() const;
	void SelectPreviousChannel();

private:
	int m_selectedChannel = 1;
	bool m_isOn = false;
	int m_previosChannel = 1;
};