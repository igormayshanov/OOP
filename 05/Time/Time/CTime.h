#pragma once
#include "stdafx.h"
// ���������� ����� �����, ���������� ����������� ����� (0-23), ����� (0-59) �
// ������ (0-59)
class CTime
{
public:
	// �������������� ����� �������� ����������� �����, ����� � ������
	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);
	CTime(const CTime& refTime);

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
	CTime operator+(CTime const& time);
	CTime operator-(CTime const& time);
	CTime& operator+=(CTime const& time);
	CTime& operator-=(CTime const& time);
	CTime operator*(int const factor);
	CTime& operator*=(int const& factor);
	CTime operator/(int const divisor);
	CTime operator/(CTime const& divisor);
	CTime& operator/=(int const divisor);
	friend std::istream& operator>>(std::istream& stream, CTime& time);
	bool operator==(CTime const& other) const;
	bool operator!=(CTime const& other) const;



private:
	const unsigned MAX_SECONDS = 86399;
	unsigned m_timeStamp;
};

CTime operator*(int const factor, CTime& time);

std::ostream& operator<<(std::ostream& stream, CTime const& time);