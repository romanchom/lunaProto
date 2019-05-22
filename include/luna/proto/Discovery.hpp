#pragma once

#include "Scalar.hpp"
#include "Array.hpp"
#include "Union.hpp"
#include "Format.hpp"

namespace luna {
namespace proto {

struct UV
{
    Scalar<float> u, v;
};

struct ColorSpace
{
    UV white, red, green, blue;
};

struct Point
{
    Scalar<float> x, y, z;
};

struct Location
{
    Point begin;
    Point end;
};

struct StrandProperties
{
    Scalar<uint8_t> id;
    Scalar<Format> format;
    Scalar<uint16_t> pixelCount;
    Location location;
    ColorSpace colorSpace;
};

struct Discovery
{
    Scalar<uint16_t> port;
    Pointer<char> name;
    Array<StrandProperties> strands;
};

}
}
