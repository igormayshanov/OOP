#pragma once
#include "stdafx.h"

class CTVSet;

class CRemoteControl
{
public:
	CRemoteControl(CTVSet& tv, std::istream& input, std::ostream& output);
	bool HandleCommand();

	// Избавляемся от предупреждения компилятора о том, что он не сможет сгенерировать оператор присваивания
	// CRemoteControl& operator=(const CRemoteControl &) = delete;
private:
	bool TurnOn(std::istream& args);
	bool TurnOff(std::istream& args);
	bool Info(std::istream& args);
	bool SelectChannel(std::istream& args);
	bool SelectPreviosChannel(std::istream& args);
	bool SetChannelName(std::istream& args);
	bool GetChannelName(std::istream& args);
	bool GetChannelByName(std::istream& args);
	bool DeleteChannelName(std::istream& args);

private:
	// функция-обработчик команды пользователя.
	// Возвращает true, если команда распознана и false, если были ошибки
	using Handler = std::function<bool(std::istream& args)>;

	using ActionMap = std::map<std::string, Handler>; 	// Отображает название команды на её обработчик

	CTVSet& m_tv;
	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;

	std::string RemoveExtraSpaces(std::string const& str);

	std::string TurnedOffMessage = "Can't do action becuase TV is turned off\n";
};
