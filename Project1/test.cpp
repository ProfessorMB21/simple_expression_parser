#include "stack.h"
#include "cgi.h"
#include "utils.h"
#include <fstream>

using namespace std;

void show_content();

int main()
{
    cout << "Content-type: text/html;\n";

	int counter = 0; // to keep track of stack items
	char stack_val = NULL;	// to keep track of the popped item's value

    ifstream f("page.tmpl");
    if (f.is_open())
    {
        char* line = new char[1024];
        while (!f.eof())
        {
            f.getline(line, sizeof(line));
            if (!strcmp(line, "<!--CONTENT-->"))
                show_content();
            else
                cout << line << endl;
        } delete[] line; f.close();
    }
	return 0;
}

// Show content on the web
void show_content()
{
    cout << "<form method=\"post\" action=\"checker.cgi\" class=\"login-form\">\n";
    cout << "<label for=\"braces\">Enter a string of braces:</label><br>\n";
    cout << "<input type=\"text\" id=\"braces\" name=\"braces-expr\"><br>\n";
    cout << "<input type=\"submit\" value=\"Submit\">\n";
    cout << "</form>\n";
    char* data = nullptr;

#ifndef _DEBUG
    cout << "<br>Method: " << (get_req_method() == post ? "POST" : "GET");
    get_form_data(data);
#else
    data = _strdup("braces-expr=%D1%E5%F0%E3%E5%E9");
#endif
    cout << "Data: " << data << endl;

    char* str = nullptr;
    stack_t* braces = new stack_t;

    get_param_value(str, "braces-expr", data);

    cout << "The string now: " << str << endl;

    // show the user where the error in the expresson is
    // if there exists any
    cout << "<div class=validator-result>\n";
    is_matching_braces((const char *)str, braces);
    cout << "</div>\n";
}
