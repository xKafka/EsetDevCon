//
// Created by xkafka on 6/23/20.
//

#include <iostream>
#include "Args.h"
#include "Limits.h"
#include "LimitsException.h"
#include "InputArgsIndexes.h"

namespace Arguments {

    Args Args::parseArgs(int argc, const char **arg) {

        if(argc < Limits::minNumOfArgLines || argc > Limits::maxNumOfArgLines)
            throw LimitsException::BadArgCount(argc);

        std::string path = arg[ArgIndex::Path];
        std::string key = arg[ArgIndex::Key];
        bool parallel = false;

        if(key.length() && key.length() > Limits::inputMaxLength)
            throw LimitsException::BadKeyLength(key);

        if(argc == Limits::maxNumOfArgLines)
        {
            const std::string parallelize = arg[ArgIndex::Option];

            if(parallelize == "-p")
                parallel = true;
            else
                throw LimitsException::BadOption(parallelize);
        }

        return Args(std::move(key), std::move(path), parallel);
    }
}