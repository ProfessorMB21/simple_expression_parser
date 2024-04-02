#pragma once
#ifndef UTILS_H
#define UTILS_H

#include "stack.h";
#include "cgi.h";

bool is_opening_brace(char c);
bool is_closing_brace(char c);
char get_closing_brace(char c);
char get_opening_brace(char c);
bool is_matching_braces(const char* str, stack_t*& brace_stack);
bool is_matching_braces(const char* str);
void write_to_file(const char* filename, unsigned int argc, ...);

#endif // !UTILS_H
