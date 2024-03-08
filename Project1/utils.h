#pragma once
#ifndef UTILS_H
#define UTILS_H

#include "stack.h";
#include "cgi.h";

bool is_opening_brace(char c);
char get_closing_brace(char c);
bool is_matching_braces(const char& s, stack_t*& brace_stack);
bool is_matching_braces(const char* str, stack_t*& brace_stack);

#endif // !UTILS_H
