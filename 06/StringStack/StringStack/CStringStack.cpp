#include "CStringStack.h"

CStringStack::CStringStack()
{
}

CStringStack::CStringStack(CStringStack const& other) noexcept
	//переделать копирование
	: m_pTop(nullptr)
	, m_size(0)
{
	Copy(other);
}

CStringStack::CStringStack(CStringStack&& other) noexcept
	: m_pTop(nullptr)
	, m_size(0)
{
	*this = std::move(other);
}

void CStringStack::Copy(CStringStack const& other)
{
	NodePtr curr = nullptr;
	for (auto i = other.m_pTop; i != nullptr; i = i->pNext)
	{
		NodePtr item = std::make_shared<Node>(i->value, item);
		if (m_pTop==nullptr)
		{
			m_pTop = item;	
		}
		else
		{
			curr->pNext = item;
		}
		curr = item;
		++m_size;
	}
}

bool CStringStack::IsEmpty() const
{
	return !m_pTop;
}

void CStringStack::Push(std::string const& value)
{
	m_pTop = std::make_shared<Node>(value, m_pTop);
	m_size++;
}

void CStringStack::Pop()
{
	if (IsEmpty())
		throw std::logic_error("Stack is empty");
	m_pTop = m_pTop->pNext;
	m_size--;
}

std::string& CStringStack::Top()
{
	if (IsEmpty())
		throw std::logic_error("Stack is empty");
	return m_pTop->value;
}

std::string& CStringStack::Top() const
{
	return CStringStack::Top();
}

void CStringStack::Print(std::ostream& stream)
{
	auto curr = m_pTop;
	while (curr != nullptr)
	{
		stream << curr->value << "\n";
		curr = curr->pNext;
	}
}

void CStringStack::Clear()
{
	while (m_pTop != nullptr)
	{
		m_pTop = m_pTop->pNext;
	}
	m_size = 0;
}

unsigned int CStringStack::Size() const
{
	return m_size;
}

CStringStack& CStringStack::operator=(CStringStack const& other) noexcept
{
	if (this != &other)
	{
		Copy(other);
	}
	return *this;
}

CStringStack& CStringStack::operator=(CStringStack&& other) noexcept
{
	if (this != &other)
	{
		Copy(other);
		other.Clear();
		// size имеет не то значение
	}
	return *this;
}