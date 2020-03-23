#pragma once

#include <boost/any.hpp>
#include <inttypes.h>

class field
{
private:
    boost::any _value;
public:
    field() : _value() {}

	bool is_empty() const { return _value.empty(); }
};