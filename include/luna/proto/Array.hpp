#pragma once

#include "Pointer.hpp"
#include "Scalar.hpp"

namespace luna {
namespace proto {

template<typename T> 
class Array
{
public:
    void set(T* data, size_t size)
    {
        mSize = size;
        mData = data;
    }

    T& operator[](size_t index)
    {
        return data()[index]; 
    }

    T const& operator[](size_t index) const
    {
        return data()[index]; 
    }

    T* data() 
    {
        return mData;
    }

    T const* data() const 
    {
        return mData;
    }

    size_t size() const
    {
        return mSize;
    }

    T* begin()
    {
        return data();
    }

    T const* begin() const
    {
        return data();
    }

    T* end()
    {
        return data() + size();
    }

    T const* end() const
    {
        return data() + size();
    }
private:
    Scalar<uint16_t> mSize;
    Pointer<T> mData;
};

}
}
