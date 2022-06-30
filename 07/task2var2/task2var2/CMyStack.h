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
	void Copy(CMyStack const& other)
	{
		NodePtr curr;
		for (auto i = other.m_pTop; i != nullptr; i = i->pNext)
		{
			NodePtr item = std::make_shared<Node>(i->value, item);
			if (!m_pTop)
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

public:
	CMyStack() = default;
	CMyStack(CMyStack const& other) noexcept
		: m_pTop(nullptr)
		, m_size(0)
	{
		Copy(other);
	}

	CMyStack(CMyStack&& other) noexcept
		: m_pTop(nullptr)
	{
		*this = std::move(other);
		other.m_size = 0;
	}

	void Clear()
	{
		while (m_pTop)
		{
			m_pTop = m_pTop->pNext;
		}
		m_size = 0;
	}

	~CMyStack()
	{
		//от рекурсии перейти к итерации
		Clear();
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

	T& Top()
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

	CMyStack& operator=(CMyStack const& other) noexcept
	{
		if (this != &other)
		{
			Copy(other);
		}
		return *this;
	}

	CMyStack& operator=(CMyStack&& other) noexcept
	{
		if (this != &other)
		{
			Copy(other);
			other.Clear();
		}
		return *this;
	}
};

//template <>
//class CMyStack<void*>
//{
//	struct Node
//	{
//		Node(void* const& v, std::shared_ptr<Node> const& next)
//			: value(v)
//			, pNext(next)
//		{
//		}
//		~Node()
//		{
//		}
//		void* value;
//		std::shared_ptr<Node> pNext;
//	};
//
//	typedef std::shared_ptr<Node> NodePtr;
//	NodePtr m_pTop;
//	unsigned int m_size = 0;
//	void Copy(CMyStack const& other)
//	{
//		NodePtr curr;
//		for (NodePtr i = other.m_pTop; i != nullptr; i = i->pNext)
//		{
//			NodePtr item = std::make_shared<Node>(i->value, item);
//			if (!m_pTop)
//			{
//				m_pTop = item;
//			}
//			else
//			{
//				curr->pNext = item;
//			}
//			curr = item;
//			++m_size;
//		}
//	}
//
//public:
//	CMyStack() = default;
//	CMyStack(CMyStack const& other) noexcept
//	{
//		Copy(other);
//	}
//
//	CMyStack(CMyStack&& other) noexcept
//		: m_pTop(nullptr)
//	{
//		*this = std::move(other);
//	}
//
//	void Clear()
//	{
//		while (m_pTop)
//		{
//			m_pTop = m_pTop->pNext;
//		}
//		m_size = 0;
//	}
//
//	~CMyStack()
//	{
//		//от рекурсии перейти к итерации
//		Clear();
//	}
//
//	void Pop()
//	{
//		if (IsEmpty())
//			throw std::logic_error("Stack is empty");
//		m_pTop = m_pTop->pNext;
//		m_size--;
//	}
//
//	void Push(void* value)
//	{
//		m_pTop = std::make_shared<Node>(value, m_pTop);
//		m_size++;
//	}
//	bool IsEmpty() const
//	{
//		return !m_pTop;
//	}
//	unsigned int Size() const
//	{
//		return m_size;
//	}
//
//	void* Top()
//	{
//		if (IsEmpty())
//			throw std::logic_error("Stack is empty");
//		return m_pTop->value;
//	}
//
//	void Print(std::ostream& stream)
//	{
//		NodePtr curr = m_pTop;
//		while (curr != nullptr)
//		{
//			stream << curr->value << "\n";
//			curr = curr->pNext;
//		}
//	}
//
//	CMyStack& operator=(CMyStack const& other) noexcept
//	{
//		if (this != &other)
//		{
//			Copy(other);
//		}
//		return *this;
//	}
//
//	CMyStack& operator=(CMyStack&& other) noexcept
//	{
//		if (this != &other)
//		{
//			Copy(other);
//			other.Clear();
//		}
//		return *this;
//	}
//};
//
//template <typename T>
//class CMyStack<T*> : private CMyStack<void*>
//{
//private:
//	typedef CMyStack<void*> CBase;
//
//public:
//	bool IsEmpty() const
//	{
//		CBase::IsEmpty();
//	}
//	void Pop()
//	{
//		CBase::Pop();
//	}
//
//	void Push(T* value)
//	{
//		CBase::Push(value);
//	}
//
//	unsigned int Size() const
//	{
//		CBase::Size();
//	}
//
//	T* Top()
//	{
//		return static_cast<T*>(CBase::Top());
//	}
//
//	void Print(std::ostream& stream)
//	{
//		CBase::Print(stream);
//	}
//
//	void Clear()
//	{
//		CBase::Clear();
//	}
//};