#pragma once
#include "stdafx.h"
#include "IShape.h"

class CShapeStorage
{
public:
	CShapeStorage(std::istream& input, std::ostream& output);
	bool HandleCommand();

	// Избавляемся от предупреждения компилятора о том, что он не сможет сгенерировать оператор присваивания
	// CRemoteControl& operator=(const CRemoteControl &) = delete;
private:
	bool AddRectangle(std::istream& args);
	bool AddCircle(std::istream& args);
	bool AddTriangle(std::istream& args);

private:
	// функция-обработчик команды пользователя.
	// Возвращает true, если команда распознана и false, если были ошибки
	using Handler = std::function<bool(std::istream& args)>;

	using ActionMap = std::map<std::string, Handler>; // Отображает название команды на её обработчик

	std::istream& m_input;
	std::ostream& m_output;
	std::vector<IShape*> m_shapeStorage;

	const ActionMap m_actionMap;
};