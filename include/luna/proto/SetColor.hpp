#pragma once

#include "Scalar.hpp"
#include "Array.hpp"
#include "Union.hpp"

namespace luna {
namespace proto {

struct StrandData {
    Scalar<uint8_t> id;
    Array<std::byte> rawBytes;
};

struct SetColor
{
    Array<StrandData> strands;
};

}
}
