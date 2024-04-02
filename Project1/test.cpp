#include <fstream>
#include "stack.h"
#include "cgi.h"
#include "utils.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    cout << "Content-type: text/html; charset=windows-1251\n\n";

	int counter = 0; // to keep track of stack items
	char stack_val = NULL;	// to keep track of the popped item's value

    ifstream f("page.tmpl");
    if (f.is_open())
    {
        char* line = new char[1024];
        while (!f.eof())
        {
            f.getline(line, 1024);
            if (!strcmp(line, "<!--FORM-->"))
            {
                cout << "<form method='post' action=\"checker.cgi\" class=\"login-form\">\n";
                cout << "<label for=\"braces\">Enter a string of braces:</label><br>\n";
                cout << "<input type=\"text\" name='email' placeholder=\"Brackets expression\" required>";
                cout << "<input type=\"submit\" value=\"Submit\">\n";

                if (get_req_method() == post)
                {
                    char* data = nullptr;

                    get_form_data(data);

                    char* expr = nullptr;
                    get_param_value(expr, "email", data);
                    if (expr)
                    {
                        cout << "<p>Data: " << data << "</p>";
                        cout << "<p>Expression entered: " << expr << "</p>" << endl;
                    }
                    write_to_file("test_braces.txt", 1, expr);
                    delete[] data;
                }
            }
            else
                cout << line << endl;
        }
        delete[] line;
        f.close();
    }
	return 0;
}
