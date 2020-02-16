#pragma once

#include <lib/controllers/basecontroller.hpp>

namespace controllers
{
class UserController : public BaseController
{
public:
    explicit UserController(const std::string& url);
    virtual ~UserController();

protected:
    void get_handle(web::http::http_request request) override;
};
}