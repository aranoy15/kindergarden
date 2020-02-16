#include <lib/controllers/controllerpool.hpp>
#include <logic/controllers/usercontroller.hpp>

namespace controllers
{

bool ControllerPool::exists(const string_t& path)
{
    return _pool.find(path) != _pool.end();
}

void ControllerPool::start()
{
    for (auto& item : _pool) {
        item.second->open().wait();
    }
}

void ControllerPool::stop()
{
    for (auto& item : _pool) {
        item.second->close().wait();
    }
}

string_t ControllerPool::get_address(const string_t& base_address, const string_t& address)
{
    uri_builder builder(base_address);
    builder.append(address);

    return builder.to_uri().to_string();
}
}