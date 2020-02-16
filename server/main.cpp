#include <iostream>
#include <stdafx.h>
#include <memory>
#include <logic/controllers/usercontroller.hpp>
#include <logic/controllers/postscontrolller.hpp>
#include <lib/controllers/controllerpool.hpp>

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;
using namespace controllers;

void initialize(const string_t& address)
{
    ControllerPool::reg<UserController>(address, "user");
    ControllerPool::reg<PostsController>(address, "posts");

    ControllerPool::start();
}

void shutdown()
{
    ControllerPool::stop();
}

int main()
{
    utility::string_t port = U("8000");
    utility::string_t address = U("http://localhost:");
    utility::string_t version = U("1.0");

    uri_builder uri(address + port);
    uri.append(version);

    initialize(uri.to_string());

    ucout << "Press enter to exit..." << endl;

    std::string line;
    std::getline(std::cin, line);

    shutdown();

    return 0;
}