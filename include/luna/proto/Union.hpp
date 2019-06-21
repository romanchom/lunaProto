#pragma once

#include "Pointer.hpp"
#include "Scalar.hpp"

namespace luna {
namespace proto {

namespace detail {

template<typename...>
struct union_get;

template<typename T, typename... Rest>
struct union_get<T, T, Rest...>
{
    static constexpr size_t index = 1;
};

template<typename T, typename First, typename... Rest>
struct union_get<T, First, Rest...>
{
    static constexpr size_t index = union_get<T, Rest...>::index + 1;
};

template<typename... T>
void discard(T...) {}

}

template<typename... Types>
class Union
{
public:
    template<typename T>
    void set(T* value)
    {
        mData = static_cast<void*>(value);
        mTypeIndex = detail::union_get<T, Types...>::index;
    }

    template<typename T>
    static constexpr size_t typeIndex = detail::union_get<T, Types...>::index;

    template<typename T>
    T const* as() const
    {
        if (typeIndex<T> == mTypeIndex) {
            return static_cast<T const*>(mData.get());
        } else {
            return nullptr;
        }
    }

    template<typename T, typename F>
    int tryCall(T * object, void(T::*function)(F const&)) const
    {
        if (typeIndex<T> == mTypeIndex) {
            (object->*function)(*static_cast<F const*>(mData.get()));
        }
        return 0;
    }
    
    template<typename T, typename... F>
    void call(T * object, F... functions) const
    {
        detail::discard(tryCall(object, functions)...);
    }

private:
    Scalar<uint8_t> mTypeIndex;
    Pointer<void> mData;
};

}
}
