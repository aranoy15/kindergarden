#pragma once

template<typename T>
class Singleton
{
public:
    Singleton(const Singleton&) = delete;
    Singleton operator=(const Singleton&) = delete;

    virtual ~Singleton() {}

    T& instance();
};