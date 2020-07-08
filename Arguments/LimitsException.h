//
// Created by xkafka on 6/23/20.
//

#ifndef ESETDEVCON_LIMITSEXCEPTION_H
#define ESETDEVCON_LIMITSEXCEPTION_H

#include <stdexcept>

namespace Arguments
{
    struct LimitsException : public std::runtime_error {

        explicit LimitsException(const std::string &what);

        static LimitsException BadArgCount(int argCount);
        static LimitsException BadKeyLength(const std::string &key);
        static LimitsException BadOption(const std::string &option);
    };
}

#endif //ESETDEVCON_LIMITSEXCEPTION_H
