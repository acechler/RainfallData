// EchlerAaronMidterm : 
// 
// Name: Aaron Echler
// Course Section (CIS 2207 N01)
// Date: 3/14/22
// 
//      Description: Exception that is thrown when a logic error occurs in the program. This exception is thrown when an invalid index is accessed.
//	Examples include accessing an index greater than the list size, or less than 0.
//  

#ifndef _PRECOND_VIOLATED_EXCEPT_H
#define _PRECOND_VIOLATED_EXCEPT_H

#include <stdexcept>
#include <string>

/// <summary>
///		Exception thrown when condition does not logically work.
/// </summary>
class PrecondViolatedExcept : public std::logic_error
{
public:
	PrecondViolatedExcept(const std::string& message = "");
};

#endif