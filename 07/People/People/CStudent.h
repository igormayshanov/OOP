#pragma once
#include "CStudentImpl.h"
#include "IStudent.h"
class CStudent : public CStudentImpl<IStudent>
{
};
