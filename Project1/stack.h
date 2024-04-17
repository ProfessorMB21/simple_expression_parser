#pragma once
#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <iostream>

struct stack_t
{
	char c = NULL;
	//bool hasError;
	int id = 0;
	stack_t* next = nullptr;
};

void push(stack_t*& stack, char value);
bool pop(stack_t*& stack, char& value);
bool pop(stack_t*& stack);
bool peek(stack_t*& stack, char& value);
void clear(stack_t*& stack);

#endif // !STACK_H
