#include "stack.h"
#include "cgi.h"
#include "utils.h"
#include <fstream>
#include <stdarg.h>

using namespace std;

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
	return (_opening == '(' && _closing == ')') ||
		(_opening == '{' && _closing == '}') ||
		(_opening == '[' && _closing == ']') ||
		(_opening == '<' && _closing == '>') ? true : false;
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

void is_matching_braces(const char* str)
{
	stack_t* brace_stack = new stack_t;

	std::cout << "<p>";
	while (*str)
	{
		if (is_opening_brace(*str))
		{
			if (strlen(str) == 1)
			{
				std::cout << "<span class=\"error-status\">" << *str << "</span>";
			}
			else
				std::cout << *str;
			push(brace_stack, *str);
		}
		else if (!brace_stack || !check_expr(brace_stack->c, *str)) // checks if str is a closing brace or stack is empty
		{
			if (!isalnum(*str) && is_closing_brace(*str))
			{
				std::cout << "<span class=\"error-status\">" << *str << "</span>";
			}
			else
				std::cout << *str;
		}
		else if (brace_stack && *str == NULL)
		{
			std::cout << "<span class=\"error-status\" style='color: blue'>" << brace_stack->c << "</span>";
		}
		else {
			std::cout << *str;
			pop(brace_stack);
		}
		str++;
	}	
	std::cout << "</p>" << std::endl;

	delete brace_stack;
}

void write_to_file_2(const char* filename, unsigned int argc, ...)
{
	va_list pdata;
	char* s = nullptr;

	va_start(pdata, argc);

	ofstream outfile(filename, ios_base::app);
	if (outfile.is_open())
	{
		for (unsigned int i = 0; i < argc; i++)
		{
			s = va_arg(pdata, char*);
			outfile << s;
		}
		outfile << '\n';
		outfile.close();
	}
	va_end(pdata);
}
