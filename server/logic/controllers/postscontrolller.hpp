#pragma once

#include <lib/controllers/basecontroller.hpp>

namespace controllers
{
class PostsController : public BaseController
{
public:
    explicit PostsController(const string_t& url);
    virtual ~PostsController();

protected:
    void get_handle(web::http::http_request request) override;

private:
    void test_database();
};
}