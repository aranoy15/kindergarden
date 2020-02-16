#pragma once

#include <lib/controllers/basecontroller.hpp>
#include <stdafx.h>

namespace controllers
{

class ControllerPool
{
	inline static std::map<string_t, std::unique_ptr<BaseController> > _pool;

public:
	ControllerPool() = delete;

	static bool exists(const string_t& path);
	static void start();
	static void stop();

	template <class T>
	static void reg(const std::string& base_address, const string_t& address);

private:
	static string_t get_address(const string_t& base_address,
	                            const string_t& address);
};

template <class T>
void ControllerPool::reg(const std::string& base_address,
                         const string_t& address)
{
	string_t result_address = get_address(base_address, address);

	if (not exists(result_address)) {
		_pool.insert(std::pair<string_t, std::unique_ptr<T> >(result_address, new T(result_address)));

		ucout << "Listening for request at: " << result_address << " " << endl;
	}
}
}  // namespace controllers