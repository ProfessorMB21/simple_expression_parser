#include "stack.h"
#include "cgi.h"
#include "utils.h"

using namespace std;

int main()
{
	const char* long_str = "[{()}(({)])]";
	int counter = 0; // to keep track of stack items
	char stack_val = NULL;	// to keep track of the popped item's value
	stack_t *braces = new stack_t;

	is_matching_braces(long_str, braces);

	return 0;
}
