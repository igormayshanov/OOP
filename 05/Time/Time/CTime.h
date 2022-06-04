#pragma once
#include "stdafx.h"
// моделирует время суток, задаваемое количеством часов (0-23), минут (0-59) и
// секунд (0-59)
class CTime
{
public:
	// инициализирует время заданным количеством часов, минут и секунд
	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);

	// инициализирует время количеством секунд после полуночи
	CTime(unsigned timeStamp = 0);

	// возвращает количество часов
	unsigned GetHours() const;

	// возвращает количество минут
	unsigned GetMinutes() const;

	// возвращает количество секунд
	unsigned GetSeconds() const;

	CTime& operator++();
	CTime operator++(int);
	CTime& operator--();
	CTime operator--(int);
	CTime& operator+(CTime const& time);
	CTime& operator-(CTime const& time);
	CTime& operator+=(CTime const& time);
	CTime& operator-=(CTime const& time);

private:
	const unsigned MAX_SECONDS = 86399;
	unsigned m_timeStamp;
};
