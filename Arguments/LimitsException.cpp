//
// Created by xkafka on 6/23/20.
//

#include <sstream>

#include "LimitsException.h"
#include "Limits.h"

namespace Arguments {

    LimitsException::LimitsException(const std::string &what) : std::runtime_error(what) {}

    LimitsException LimitsException::BadArgCount(int argCount) {
        std::stringstream stream;

        stream << "Program expects between " << (Arguments::Limits::minNumOfArgLines - 1)
               << " and" << (Arguments::Limits::maxNumOfArgLines - 1)
               << " arguments, " << (argCount - 1) << " were provided\n";

        return LimitsException(stream.str());
    }

    LimitsException LimitsException::BadKeyLength(const std::string &key) {
        std::stringstream stream;

        stream << "Key \"" << key << "\" with length " << key.length() << " is either empty, or too long.\n"
               << 'Maximum allowed key length is ' << Arguments::Limits::inputMaxLength;

        return LimitsException(stream.str());
    }
    LimitsException LimitsException::BadOption(const std::string &option) {
        std::stringstream stream;

        stream << "Invalid option " << option;

        return LimitsException(stream.str());
    }
}
