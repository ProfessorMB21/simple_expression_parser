#pragma once
#ifndef CGI_H
#define CGI_H

#include <stdlib.h>
#include <iostream>

/*/
enum request_method
{
	get, post
};

/
size_t get_content_length();
request_method get_req_method();
void get_form_data(char*& data);
void get_param_value(const char* data, const char* param_name, char*& value);
void get_current_url(char*& url_);
char* get_host_ip();
*/

namespace cgi_utils
{
	enum request_method {
		get, post
	};

	request_method get_request_method();
	void get_form_data(char*& result);
	void get_param_value(const char* data, const char* param_name, char*& value);
	char* get_current_url();
	char* get_host_ip();
}


#endif // !CGI_H
