#include "CTime.h"

CTime::CTime(unsigned hours, unsigned minutes, unsigned seconds)
	: m_timeStamp(hours * 3600 + minutes * 60 + seconds)
{
	try
	{
		if (hours > 23 || hours < 0)
		{
			throw std::out_of_range("Hours argument must be from 0 to 24");
		}
		if (minutes > 59 || minutes < 0)
		{
			throw std::out_of_range("Minutes argument must be from 0 to 60");
		}
		if (seconds > 59 || seconds < 0)
		{
			throw std::out_of_range("Seconds argument must be from 0 to 60");
		}
	}
	catch (std::out_of_range const& e)
	{
		std::cout << "Error: " << e.what() << "\n";
		throw;
	}
}
// инициализирует время количеством секунд после полуночи
CTime::CTime(unsigned timeStamp)
	: m_timeStamp(timeStamp)
{
}

// возвращает количество часов
unsigned CTime::GetHours() const
{
	return m_timeStamp / 3600;
}

// возвращает количество минут
unsigned CTime::GetMinutes() const
{
	return m_timeStamp % 3600 / 60;
}

// возвращает количество секунд
unsigned CTime::GetSeconds() const
{
	return m_timeStamp % 60;
}

CTime& CTime::operator++()
{
	m_timeStamp = m_timeStamp == MAX_SECONDS ? 0 : ++m_timeStamp;
	return *this;
}

CTime CTime::operator++(int)
{
	auto temp = *this;
	++*this;
	return temp;
}

CTime& CTime::operator--()
{
	m_timeStamp = m_timeStamp != 0 ? --m_timeStamp : MAX_SECONDS;
	return *this;
}

CTime CTime::operator--(int)
{
	auto temp = *this;
	--*this;
	return temp;
}

CTime CTime::operator+(CTime const& time)
{
	auto temp = m_timeStamp + time.m_timeStamp;
	temp = temp > MAX_SECONDS ? (temp % MAX_SECONDS) - 1 : temp;
	return CTime(temp);
}

CTime& CTime::operator+=(CTime const& time)
{
	m_timeStamp += time.m_timeStamp;
	m_timeStamp = m_timeStamp > MAX_SECONDS ? (m_timeStamp % MAX_SECONDS) - 1 : m_timeStamp;
	return *this;
}

CTime CTime::operator-(CTime const& time)
{
	auto temp = m_timeStamp < time.m_timeStamp ? time.m_timeStamp - m_timeStamp : m_timeStamp - time.m_timeStamp;
	return CTime(temp);
}

CTime& CTime::operator-=(CTime const& time)
{
	m_timeStamp = m_timeStamp < time.m_timeStamp ? time.m_timeStamp - m_timeStamp : m_timeStamp - time.m_timeStamp;
	return *this;
}

CTime CTime::operator*(int const factor)
{
	auto temp = static_cast<int>(m_timeStamp * factor);
	if (factor < 0)
	{
		auto result = std::abs(temp) % MAX_SECONDS;
		result = MAX_SECONDS - result + 1;
		return CTime(result);
	}
	temp = temp > MAX_SECONDS ? (temp % MAX_SECONDS) - 1 : temp;
	return CTime(temp);
}

CTime operator*(int const factor, CTime& time)
{
	return CTime(time * factor);
}

CTime CTime::operator/(int const divisor)
{
	if (divisor == 0)
	{
		throw std::invalid_argument("Argument must not be null");
	}
	auto temp = static_cast<int>(m_timeStamp / divisor);
	if (divisor < 0)
	{
		auto result = std::abs(temp) % MAX_SECONDS;
		result = MAX_SECONDS - result + 1;
		return CTime(result);
	}
	return CTime(m_timeStamp / divisor);
}

CTime CTime::operator/(CTime const& divisor)
{
	return CTime(*this / divisor.m_timeStamp);
}

CTime& CTime::operator*=(int const& factor)
{
	m_timeStamp *= factor;
	return *this;
}

CTime& CTime::operator/=(int const divisor)
{
	m_timeStamp /= divisor;
	return *this;
}