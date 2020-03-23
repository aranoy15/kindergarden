#pragma once

#include <kaguya/kaguya.hpp>

namespace utils
{
class ServerData
{
public:
    explicit ServerData(const char* lua_path);
    explicit ServerData(const std::string& luat_path);
    explicit ServerData(const std::string&& luat_path);
};
}