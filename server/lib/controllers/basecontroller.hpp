#pragma once

#include <stdafx.h>

namespace controllers
{
using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

class BaseController
{
public:
	explicit BaseController(utility::string_t url);

	virtual ~BaseController();

    pplx::task<void> open() { return _listener.open(); }
    pplx::task<void> close() { return _listener.close(); }

protected:
    virtual void get_handle(web::http::http_request request);
    virtual void put_handle(web::http::http_request request);
    virtual void post_handle(web::http::http_request request);
    virtual void delete_handle(web::http::http_request request);

private:
    http_listener _listener;
};
}//controllers