#include "stack.h"
#include "cgi.h"
#include "utils.h"

// Returns true if the character is an opening brace, otherwise false
bool is_opening_brace(char c)
{
	return c == '(' || c == '{' || c == '[' || c == '<' ? true : false;
}

// Returns true if the character is a closing brace, otherwise false
bool is_closing_brace(char c)
{
	return  c == ')' || c == '}' || c == ']' || c == '>' ? true : false;
}

// Returns the corresponding closing brace to an opening brace
char get_closing_brace(char c)
{
	switch (c)
	{
	case '(':
		return ')';
	case '{':
		return '}';
	case '[':
		return ']';
	default:
		return '\0';	// anything other than an opening brace
						// will be null
	}
}

// Returns the corresponding opening brace to a closing brace
char get_opening_brace(char c)
{
	switch (c)
	{
	case ')':
		return '(';
	case '}':
		return '{';
	case ']':
		return '[';
	case '>':
		return '<';
	default:
		return '\0';
	}
}

// Validates the expression with braces
bool check_expr(char _opening, char _closing)
{
	return true ? (_opening == '(' && _closing == ')') ||
		(_opening == '{' && _closing == '}') ||
		(_opening == '[' && _closing == ']') ||
		(_opening == '<' && _closing == '>') : false;
}

// Returns true if braces are matching, otherwise false
bool is_matching_braces(const char* str, stack_t*& brace_stack)
{
	//auto* curr = brace_stack;
	while (*str)
	{
		if (is_opening_brace(*str))
		{
			std::cout << *str << " -> ";
			//std::cout << *str << " pushed to stack" << std::endl;
			push(brace_stack, *str);
		}
		else if (!brace_stack || !check_expr(brace_stack->c, *str))
		{
			// checks if str is a closing brace or stack is empty
			return false;
		}
		else {
			std::cout << *str << " <- ";
			//std::cout << *str << " popped from stack" << std::endl;
			pop(brace_stack);
		}
		str++;
	}
	return true;
}
