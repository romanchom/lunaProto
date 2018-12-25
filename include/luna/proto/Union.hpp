#pragma once

#include "Pointer.hpp"
#include "Scalar.hpp"

namespace luna {
namespace proto {

namespace detail {

template<typename... T>
struct type_tuple;

template<typename...>
struct union_get;

template<typename First>
struct union_get<First, type_tuple<>>
{
    static constexpr size_t index = 0;
};

template<typename T, typename... Rest>
struct union_get<T, type_tuple<T, Rest...>>
{
    static constexpr size_t index = 1;
};

template<typename T, typename First, typename... Rest>
struct union_get<T, type_tuple<First, Rest...>>
{
    static constexpr size_t index = union_get<T, type_tuple<Rest...>>::index + 1;
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
        mTypeIndex = detail::union_get<T, detail::type_tuple<Types...>>::index;
    }

    template<typename T, typename F>
    int tryCall(T * object, void(T::*function)(F&))
    {
        if (detail::union_get<F, detail::type_tuple<Types...>>::index == mTypeIndex) {
            (object->*function)(*static_cast<F*>(mData.get()));
        }
        return 0;
    }
    
    template<typename T, typename... F>
    void call(T * object, F... functions)
    {
        detail::discard(tryCall(object, functions)...);
    }

private:
    Scalar<uint8_t> mTypeIndex;
    Pointer<void> mData;
};

}
}
