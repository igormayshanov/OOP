#pragma once
#include "stdafx.h"
// ���������� ����� �����, ���������� ����������� ����� (0-23), ����� (0-59) �
// ������ (0-59)
class CTime
{
public:
	// �������������� ����� �������� ����������� �����, ����� � ������
	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);

	// �������������� ����� ����������� ������ ����� ��������
	CTime(unsigned timeStamp = 0);

	// ���������� ���������� �����
	unsigned GetHours() const;

	// ���������� ���������� �����
	unsigned GetMinutes() const;

	// ���������� ���������� ������
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
