#include "CStringStack.h"
CStringStack::CStringStack()
{
}

CStringStack::CStringStack(CStringStack const& other) noexcept
	: m_pTop(other.m_pTop)
{
	std::cout << "Creating copy of object StringStack\n";
}

CStringStack::CStringStack(CStringStack&& other) noexcept
	: m_pTop(nullptr)
{
	*this = std::move(other);
	std::cout << "Move object StringStack\n";
}

bool CStringStack::IsEmpty() const
{
	return !m_pTop;
}

void CStringStack::Push(std::string const& value)
{
	m_pTop = std::make_shared<Node>(value, m_pTop);
}

void CStringStack::Pop()
{
	if (IsEmpty())
		throw std::logic_error("Stack is empty");
	m_pTop = m_pTop->pNext;
}

std::string& CStringStack::Top() const
{
	if (IsEmpty())
		throw std::logic_error("Stack is empty");
	return m_pTop->value;
}

void CStringStack::Print(std::ostream& stream)
{
	NodePtr curr = m_pTop;
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
}

CStringStack& CStringStack::operator=(CStringStack const& other) noexcept
{
	if (this != &other)
	{
		CStringStack tmpCopy(other);
		std::swap(m_pTop, tmpCopy.m_pTop);
	}
	return *this;
}

CStringStack& CStringStack::operator=(CStringStack&& other) noexcept
{
	if (this != &other)
	{
		m_pTop = std::move(other.m_pTop);
	}
	return *this;
}