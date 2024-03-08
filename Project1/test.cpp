#include "stack.h"
#include "cgi.h"
#include "utils.h"

using namespace std;

int main()
{

	char c = '{';
	char b = ']';

	cout << c << " is brace: " << is_opening_brace(c) << endl;
	cout << b << " is brace: " << is_opening_brace(b) << endl;
	cout << "Corresp. clsoing brace to " << c << " is " << get_closing_brace(c) << endl;
	cout << "Corresp. clsoing brace to " << b << " is " << get_closing_brace(b) << endl;
	return 0;
}
