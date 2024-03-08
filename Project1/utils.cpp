#include "stack.h"
#include "cgi.h"
#include "utils.h"

// Returns true if the character is an opening brace, otherwise false
bool is_opening_brace(char c)
{
	return true ? c == '(' || c == '{' || c == '[' || c == '<' : false;
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

// Returns true if braces are matching, otherwise false
bool is_matching_braces(const char& s, stack_t *&brace_stack)
{
	if (is_opening_brace(s))	// push to the stack if s is an opening brace
	{
		push(brace_stack, s);
	}
	else if (!brace_stack || brace_stack->c != get_closing_brace(s))
	{
		// check if the stack is empty or the current brace
		// does not have a closing braces
		return false;
	}
	else {
		if (brace_stack)
			pop(brace_stack);
	}

}

// Returns true if braces are matching, otherwise false
bool is_matching_braces(const char* str, stack_t*& brace_stack)
{
	//auto* curr = brace_stack;
	while (*str)
	{
		if (is_opening_brace(*str))
		{
			push(brace_stack, *str);
		}
		else if (!brace_stack || ((*str == get_closing_brace(*str)) == NULL))
		{
			// checks if str is a closing brace or stack is empty
			return false;
		}
		else {
			if (brace_stack)
				pop(brace_stack);
		}
		str++;
	}
}
