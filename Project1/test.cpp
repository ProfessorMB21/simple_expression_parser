#include "stack.h"
#include "cgi.h"
#include "utils.h"

using namespace std;

int main()
{

	char c = '{';
	char b = ']';
	const char* long_str = "[{()}(({)])]";
	int counter = 0; // to keep track of stack items
	char stack_val = NULL;	// to keep track of the popped item's value
	stack_t *braces = new stack_t;

	cout << c << " is brace: " << is_opening_brace(c) << endl;
	cout << b << " is brace: " << is_opening_brace(b) << endl;
	cout << "Corresp. clsoing brace to " << c << " is " << get_closing_brace(c) << endl;
	cout << "Corresp. clsoing brace to " << b << " is " << get_closing_brace(b) << endl;
	cout << endl;
	
	for (int i = 0; long_str[i] != '\0'; i++)
	{
		if (is_opening_brace(long_str[i]))
		{
			is_matching_braces(long_str[i], braces, counter, stack_val);
			cout << counter << " :: " << long_str[i] << " is an opening brace " << endl;
			cout << endl;
		}
		else if (is_closing_brace(long_str[i]))
		{
			// check if is a closing brace
			is_matching_braces(long_str[i], braces, counter, stack_val);
			cout << "\t\t\t";
			cout << "Popped value was " << stack_val << " at " << counter << " ";
			cout << long_str[i] << " is a closing brace" << endl;
		}
	}
	return 0;
}
