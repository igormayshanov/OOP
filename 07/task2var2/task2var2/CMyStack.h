#pragma once
#include "stdafx.h"
#include <memory>

template <typename T>
class CMyStack
{
	struct Node
	{
		Node(T const& v, std::shared_ptr<Node> const& next)
			: value(v)
			, pNext(next)
		{
		}
		~Node()
		{
		}
		T value;
		std::shared_ptr<Node> pNext;
	};

	typedef std::shared_ptr<Node> NodePtr;
	NodePtr m_pTop;
	unsigned int m_size = 0;

public:
	CMyStack() = default;
	CMyStack(CMyStack const& other) noexcept
	: m_pTop(other.m_pTop)
	, m_size(other.m_size)
	{
	}

	CMyStack(CMyStack&& other) noexcept
		: m_pTop(nullptr)
	{
		*this = std::move(other);
	}

	~CMyStack()
	{
	}

	void Pop()
	{
		if (IsEmpty())
			throw std::logic_error("Stack is empty");
		m_pTop = m_pTop->pNext;
		m_size--;
	}

	void Push(T const& value)
	{
		m_pTop = std::make_shared<Node>(value, m_pTop);
		m_size++;
	}
	bool IsEmpty() const
	{
		return !m_pTop;
	}
	unsigned int Size() const
	{
		return m_size;
	}

	T& Top() const
	{
		if (IsEmpty())
			throw std::logic_error("Stack is empty");
		return m_pTop->value;
	}
	void Print(std::ostream& stream)
	{
		NodePtr curr = m_pTop;
		while (curr != nullptr)
		{
			stream << curr->value << "\n";
			curr = curr->pNext;
		}
	}

	void Clear()
	{
		while (m_pTop != nullptr)
		{
			m_pTop = m_pTop->pNext;
		}
		m_size = 0;
	}

	CMyStack& operator=(CMyStack const& other) noexcept
	{
		if (this != &other)
		{
			CMyStack tmpCopy(other);
			std::swap(m_pTop, tmpCopy.m_pTop);
			std::swap(m_size, tmpCopy.m_size);
		}
		return *this;
	}

	CMyStack& operator=(CMyStack&& other) noexcept
	{
		if (this != &other)
		{
			m_pTop = std::move(other.m_pTop);
			m_size = std::move(other.m_size);
		}
		return *this;
	}
};

template <>
class CMyStack <void*>
{
	struct Node
	{
		Node(void* v, std::shared_ptr<Node> const& next)
			: value(v)
			, pNext(next)
		{
		}
		~Node()
		{
		}
		void* value;
		std::shared_ptr<Node> pNext;
	};

	typedef std::shared_ptr<Node> NodePtr;
	NodePtr m_pTop;
	unsigned int m_size = 0;

public:
	CMyStack() = default;
	CMyStack(CMyStack const& other) noexcept
		: m_pTop(other.m_pTop)
		, m_size(other.m_size)
	{
	}

	CMyStack(CMyStack&& other) noexcept
		: m_pTop(nullptr)
	{
		*this = std::move(other);
	}

	~CMyStack()
	{
	}

	void Pop()
	{
		if (IsEmpty())
			throw std::logic_error("Stack is empty");
		m_pTop = m_pTop->pNext;
		m_size--;
	}

	void Push(void* value)
	{
		m_pTop = std::make_shared<Node>(value, m_pTop);
		m_size++;
	}
	bool IsEmpty() const
	{
		return !m_pTop;
	}
	unsigned int Size() const
	{
		return m_size;
	}

	void* Top() const
	{
		if (IsEmpty())
			throw std::logic_error("Stack is empty");
		return m_pTop->value;
	}
	void Print(std::ostream& stream)
	{
		NodePtr curr = m_pTop;
		while (curr != nullptr)
		{
			stream << curr->value << "\n";
			curr = curr->pNext;
		}
	}

	void Clear()
	{
		while (m_pTop != nullptr)
		{
			m_pTop = m_pTop->pNext;
		}
		m_size = 0;
	}

	CMyStack& operator=(CMyStack const& other) noexcept
	{
		if (this != &other)
		{
			CMyStack tmpCopy(other);
			std::swap(m_pTop, tmpCopy.m_pTop);
			std::swap(m_size, tmpCopy.m_size);
		}
		return *this;
	}

	CMyStack& operator=(CMyStack&& other) noexcept
	{
		if (this != &other)
		{
			m_pTop = std::move(other.m_pTop);
			m_size = std::move(other.m_size);
		}
		return *this;
	}
};

template <typename T>
class CMyStack<T*> : private CMyStack<void*>
{
private:
	typedef CMyStack<void*> CBase;

public:
	bool IsEmpty() const
	{
		CBase::IsEmpty();
	}
	void Pop()
	{
		CBase::Pop();
	}

	void Push(T* value)
	{
		CBase::Push(value);
	}
	unsigned int Size() const
	{
		CBase::Size();
	}

	void* Top() const
	{
		return static_cast<T*>(CBase::Top());
	}
	void Print(std::ostream& stream)
	{
		CBase::Print(stream);
	}

	void Clear()
	{
		CBase::Clear();
	}

};