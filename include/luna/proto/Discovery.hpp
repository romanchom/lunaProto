#pragma once

#include "Scalar.hpp"
#include "Array.hpp"
#include "Union.hpp"

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

enum ColorChannels : uint8_t {
    red = 1 << 0,
    green = 1 << 1,
    blue = 1 << 2,
    white = 1 << 3,
    redGreenBlue = red | green | blue,
};

struct StrandProperties
{
    Scalar<uint8_t> id;
    Scalar<ColorChannels> channels;
    Scalar<uint16_t> pixelCount;
    Point begin;
    Point end;
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
