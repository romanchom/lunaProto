#pragma once

#include "Scalar.hpp"
#include "Array.hpp"
#include "Union.hpp"

namespace luna {
namespace proto {

struct RGB {
    Scalar<uint8_t> r, g, b;
};

struct StrandData {
    Scalar<uint8_t> id;
    Union<Array<RGB>> data;
};

struct SetColor
{
    Array<StrandData> strands;
};

}
}
