#include <fstream>
#include "stack.h"
#include "cgi.h"
#include "utils.h"

using namespace std;
using namespace cgi_utils;

char *collect_data();
void run_validator(const char* data);

int main()
{
    setlocale(LC_ALL, "");
    cout << "Content-type: text/html; charset=windows-1251\n\n";

	int counter = 0; // to keep track of stack items
	char stack_val = NULL;	// to keep track of the popped item's value\

    char* brace_str = nullptr;

    ifstream f("page.tmpl");
    if (f.is_open())
    {
        char* line = new char[1024];
        while (!f.eof())
        {
            f.getline(line, 1024);
            if (!strcmp(line, "<!--FORM-->"))
            {
                /*/
                cout << "<form method='post' action='checker.cgi' class=\"login-form\">\n";
                cout << "<label for=\"braces\">Enter a string of braces:</label><br>\n";
                cout << "<input type=\"text\" name='sequence' required>";
                cout << "<input type=\"submit\" value=\"Submit\">" << endl;

                cout << "<p>IP address: " << ip_addr << "</p>\n";
                cout << "Method: " << (get_request_method() == post ? "Post" : "Get") << endl;
                if (get_request_method() == post)
                {
                    char* data = nullptr;

                    get_form_data(data);

                    char* expr = nullptr;

                    cout << "<p>Data: " << data << "</p>";
                    cout << "<p>IP address: " << ip_addr << "</p>\n";

                    get_param_value(data, "sequence", expr);
                    if (expr)
                    {
                        write_to_file("test_data.txt", 2, expr, expr[0]);
                        cout << "<p>Expression entered: " << expr << "</p>" << endl;
                    }
                    write_to_file("test_braces.txt", 1, expr);
                    delete[] data;
                }
                */

                brace_str = collect_data();
            }
            if (!strcmp(line, "<!--RESULT-->"))
            {
                run_validator(brace_str);
            }
            else
                cout << line << endl;
        }
        delete[] line;
        f.close();
    }
	return 0;
}

char *collect_data()
{
    cout << "<form action=\"checker.cgi\" method=\"post\" class=\"comment-form\">";
    cout << "<div>";
    cout << "<label for=\"comment\" class=\"required\">Enter an expression of braces</label>";
    cout << "<textarea name=\"user-comment\" id=\"comment\" rows=\"2\" cols=\"30\" placeholder=\"([{}])...\" minlength=\"1\" maxlength=\"256\" required=\"required\"></textarea>";
    cout << "</div>";
    cout << "<input name=\"submit\" type=\"submit\" value=\"Submit\"/>";
    cout << "</form>";

    if (get_request_method() == post) {
        char* ip_addr = get_host_ip();
        char* data = nullptr;
        const char* filename = "test_data.txt";
        char* result = nullptr;

        get_form_data(data);

        get_param_value(data, "user-comment", result);
        if (result)
        {
            cout << "<p>Expression entered: <span style='color: darkslateblue'>";
            for (int i = 0; result[i] != NULL; i++)
                cout << "<span>" << result[i] << "</span>";
            cout << "</span></p>" << endl;

            write_to_file_3(filename, 1, result);
        }
        delete[] data;
        return result;
    }
}

void run_validator(const char* data)
{
    if (!data) return;

    cout << "<p class='info'> Starting brace validator!</p>\n";
    is_matching_braces(data);
    cout << "<p class='info'> Validator stopped!</p>" << endl;
}
