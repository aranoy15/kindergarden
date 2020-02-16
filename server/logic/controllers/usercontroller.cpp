#include <logic/controllers/usercontroller.hpp>

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

namespace controllers
{
UserController::UserController(const std::string& url) : BaseController(url)
{

}

UserController::~UserController() {}

void UserController::get_handle(http_request request) 
{
    ucout << "User handle GET command: " << request.to_string();

    request.reply(status_codes::OK);
}
}