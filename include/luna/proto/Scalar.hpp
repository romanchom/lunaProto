#pragma once

#include <cstdint>

namespace luna {
namespace proto {

template<typename T>
class Scalar
{
public:
    Scalar & operator=(T value)
    {
        set(value);
        return *this;
    }
    
    T get() const
    {
        return reinterpret_cast<T const&>(mStorage);
    }

    operator T() const
    {
        return get();
    }
private:
    void set(T value)
    {
        reinterpret_cast<T&>(mStorage) = value;
    }
    uint8_t mStorage[sizeof(T)] = {};
};

}
}
