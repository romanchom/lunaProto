#pragma once

#include "Scalar.hpp"
#include "Union.hpp"
#include "SetColor.hpp"

namespace luna {
namespace proto {

struct Command
{
    Scalar<uint16_t> id; 
    Scalar<uint16_t> ack;
    Union<SetColor> command;
};

}
}
