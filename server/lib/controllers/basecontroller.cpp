#include <lib/controllers/basecontroller.hpp>

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

namespace controllers
{

BaseController::BaseController(utility::string_t url) : _listener(url)
{
    _listener.support(methods::GET, std::bind(&BaseController::get_handle, this, std::placeholders::_1));
    _listener.support(methods::PUT, std::bind(&BaseController::put_handle, this, std::placeholders::_1));
    _listener.support(methods::POST, std::bind(&BaseController::post_handle, this, std::placeholders::_1));
    _listener.support(methods::DEL, std::bind(&BaseController::delete_handle, this, std::placeholders::_1));
}

BaseController::~BaseController() {}

void BaseController::get_handle(web::http::http_request request)
{
    request.reply(status_codes::NotImplemented);
}

void BaseController::put_handle(web::http::http_request request)
{
    request.reply(status_codes::NotImplemented);
}

void BaseController::post_handle(web::http::http_request request)
{
    request.reply(status_codes::NotImplemented);
}

void BaseController::delete_handle(web::http::http_request request)
{
    request.reply(status_codes::NotImplemented);
}
}