#pragma once
#include <memory>
#include "stdafx.h"

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
			std::cout << "Node destroyed " << value << "\n ";
		}
		std::string value;
		std::shared_ptr<Node> pNext;
	};

	typedef std::shared_ptr<Node> NodePtr;
	NodePtr m_pTop;

public:

		~CStringStack()
	{
		std::cout << "Stack is destroyed\n";
	}

	void Pop();
	void Push(std::string const& value);
	bool IsEmpty() const;
	std::string& Top() const;
	void Print(std::ostream& stream);
	void Erase();
};