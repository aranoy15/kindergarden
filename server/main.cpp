#include <iostream>
#include <stdafx.h>
#include <memory>
#include <logic/controllers/usercontroller.hpp>
#include <logic/controllers/postscontrolller.hpp>
#include <lib/controllers/controllerpool.hpp>
#include <kaguya/kaguya.hpp>
#include <lib/models/field.hpp>

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

struct ServerSettings
{
    std::string address;
    std::string port;
    std::string version;

	ServerSettings() : address("http://localhost"), port("8000"), version("1.0")
	{
	}

	ServerSettings(const std::string& address, const std::string& port,
	               const std::string version)
	    : address(address), port(port), version(version)
	{
	}
};

ServerSettings get_settings()
{
    kaguya::State state;

    if (state.dofile("config/serversetting.lua")) {
        auto settings = state["settings"];

        std::string address = settings["address"].get<std::string>();
        std::string port = settings["port"].get<std::string>();
        std::string version = settings["version"].get<std::string>();

        return ServerSettings(address, port, version);
    }

    return ServerSettings();
}

int main()
{
    ServerSettings settings = get_settings();

    utility::string_t port = U(settings.port);
    utility::string_t address = U(settings.address);
    utility::string_t version = U(settings.version);

    std::unique_ptr<BaseField> field_test = std::make_unique<Field<float>>();

    float test_value = field_test->value();

    uri_builder uri(address + ":" + port);
    uri.append(version);

    initialize(uri.to_string());

    ucout << "Press enter to exit ..." << endl;

    std::string line;
    std::getline(std::cin, line);

    shutdown();

    return 0;
}