#pragma once

#include "Scalar.hpp"

namespace luna {
namespace proto {

template<typename T>
class Pointer
{
public:
    Pointer& operator=(T* value)
    {
        mOffset = static_cast<uint16_t>(
            reinterpret_cast<char*>(value) - reinterpret_cast<char*>(this + 1)
        );
        return *this;
    }

    operator T* (){
        return get();
    }

    operator T const* () const {
        return get();
    }

    T* get()
    {
        return reinterpret_cast<T*>( 
            reinterpret_cast<char*>(this + 1) + mOffset
        );
    }

    T const* get() const
    {
        return reinterpret_cast<T const*>(
            reinterpret_cast<char const*>(this + 1) + mOffset
        );
    }
private:
    Scalar<uint16_t> mOffset;
};

}
}
