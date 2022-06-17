#include "CStringStack.h"

bool CStringStack::IsEmpty() const
{
	return !m_pTop;
}

void CStringStack::Push(std::string const& value)
{
	m_pTop = std::make_unique<Node>(value, m_pTop);
}

void CStringStack::Pop()
{
	if (IsEmpty())
		throw std::logic_error("Stack is empty");
	m_pTop = std::move(m_pTop->pNext);
}

std::string& CStringStack::Top() const
{
	if (IsEmpty())
		throw std::logic_error("Stack is empty");
	return m_pTop->value;
}

void CStringStack::Print(std::ostream& stream)
{
	if (IsEmpty())
		throw std::logic_error("Stack is empty");
	NodePtr curr = std::move(m_pTop);
	while (curr != nullptr)
	{
		stream << curr->value << "\n";
		curr = std::move(curr->pNext);
	}
}

void CStringStack::Erase()
{
	if (IsEmpty())
		throw std::logic_error("Stack is empty");
	while (m_pTop != nullptr)
	{
		m_pTop = std::move(m_pTop->pNext);
	}
}