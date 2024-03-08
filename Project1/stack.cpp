#include "stack.h"


// Adds an item on top of the stack
void push(stack_t*& stack, char value)
{
	stack_t* new_el = new stack_t;
	new_el->c = value;
	new_el->next = stack;
	stack = new_el;
}

// Removes the item on top of the stack
// and returns the value of the removed item
bool pop(stack_t*& stack, char& value)
{
	if (stack)	// check if stack is not empty
	{
		value = stack->c;
		auto* temp = stack;	// remove item on top of stack
		delete temp;
		stack = stack->next;
		return true;
	}
	return false;
}

// Removes the item on top of the stack
bool pop(stack_t*& stack)
{
	if (stack)
	{
		auto* temp = stack;
		stack = stack->next;
		delete temp;
		return true;
	}
	return false;
}

// Returns the value of the item on top of the stack
bool peek(stack_t*& stack, char& value)
{
	if (stack)
	{
		value = stack->c;
		return true;
	}
	return false;
}

// Deallocates memory alloc'd to the stack
// Frees the entire stack
void clear(stack_t*& stack)
{
	while (stack) // check if top of stack is NULL
	{
		auto* temp = stack;
		stack = stack->next;
		delete temp;
	}
}

