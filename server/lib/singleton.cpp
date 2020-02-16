#include <lib/singleton.hpp>

template<typename T>
T& Singleton<T>::instance()
{
    static T result;
    return result;
}