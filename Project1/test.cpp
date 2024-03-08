#include "stack.h"
#include "cgi.h"
#include "utils.h"

using namespace std;

int main()
{

	char c = '{';
	char b = ']';
	const char* long_str = "Hello the I am a [{){((({)}}))))}}}](";

	cout << c << " is brace: " << is_opening_brace(c) << endl;
	cout << b << " is brace: " << is_opening_brace(b) << endl;
	cout << "Corresp. clsoing brace to " << c << " is " << get_closing_brace(c) << endl;
	cout << "Corresp. clsoing brace to " << b << " is " << get_closing_brace(b) << endl;
	cout << endl;
	
	for (int i = 0; long_str[i] != '\0'; i++)
	{
		if (is_opening_brace(long_str[i]))
		{
			cout << long_str[i] << " is an opening brace ";
			cout << "and its corresponding closing brace is " << get_closing_brace(long_str[i]) << endl;
		}
		else if ((get_closing_brace(long_str[i]) == NULL) && has_opening_brace(long_str[i]))
		{
			// is closing brace
			cout << long_str[i] << " is a closing brace" << endl;
		}
		else
		{
			// not a closing brace
			cout << long_str[i] << " is not a brace!" << endl;
		}
	}

	return 0;
}
