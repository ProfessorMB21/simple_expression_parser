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

	cout << c << " is brace: " << is_opening_brace(c) << endl;
	cout << b << " is brace: " << is_opening_brace(b) << endl;
	cout << "Corresp. clsoing brace to " << c << " is " << get_closing_brace(c) << endl;
	cout << "Corresp. clsoing brace to " << b << " is " << get_closing_brace(b) << endl;
	cout << endl;
	
	is_matching_braces(long_str, braces);

	return 0;
}
