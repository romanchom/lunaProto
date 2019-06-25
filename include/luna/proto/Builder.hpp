#pragma once

#include <cstddef>

namespace luna {
namespace proto {

class Builder
{
public:
    explicit Builder(std::byte * storage) :
        mBegin(storage),
        mPointer(storage)
    {}

    template<typename T>
    T* allocate(size_t size = 1)
    {
        auto ret = reinterpret_cast<T *>(mPointer);
        for (size_t i = 0; i < size; ++i) {
            new (ret + i) T();
        }
        mPointer += sizeof(T) * size;
        return ret;
    }

    std::byte const * data()
    {
        return mBegin;
    }

    size_t size() const
    {
        return mPointer - mBegin;
    }
private:
    std::byte * const mBegin;
    std::byte * mPointer;
};

}
}
