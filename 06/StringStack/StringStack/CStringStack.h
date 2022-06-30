#pragma once
#include "stdafx.h"
#include <memory>

class CStringStack
{
	struct Node
	{
		Node(std::string const& v, std::shared_ptr<Node> const& next)
			: value(v)
			, pNext(next)
		{
		}
		~Node()
		{
		}
		std::string value;
		std::shared_ptr<Node> pNext;
	};

	typedef std::shared_ptr<Node> NodePtr;
	NodePtr m_pTop;
	unsigned int m_size = 0;
	void Copy(CStringStack const& other);

public:
	CStringStack();
	CStringStack(CStringStack const& other) noexcept;
	CStringStack(CStringStack&& other) noexcept;
	~CStringStack()
	{
		//�� �������� ������� � ��������
		Clear();
	}
	void Pop();
	void Push(std::string const& value);
	bool IsEmpty() const;
	unsigned int Size() const;
	std::string& Top() const; //������� const � �� const
	std::string& Top();
	void Print(std::ostream& stream);
	void Clear();
	CStringStack& operator=(CStringStack const& other) noexcept;
	CStringStack& operator=(CStringStack&& other) noexcept;
};