#pragma once
#include "CStudentImpl.h"
#include "IStudent.h"
class CAdvancedStudent : public CStudentImpl<IStudent>
{
public:
	CAdvancedStudent(std::string dissertationTopic)
		: m_dissertationTopic(dissertationTopic)
	{
	}
	std::string GetDissertationTopic() const
	{
		return m_dissertationTopic;
	}

private:
	std::string m_dissertationTopic;
};
