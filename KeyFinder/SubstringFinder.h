//
// Created by xkafka on 7/1/20.
//

#ifndef ESETDEVCON_SUBSTRINGFINDER_H
#define ESETDEVCON_SUBSTRINGFINDER_H

#include "FileParser.h"
#include <algorithm>

namespace SubStringFinder
{
    static auto searchUsingBMH(const char *const beg, const char *const end, const std::string &key)
    {
        auto  itr = std::search(beg, end,
                       std::boyer_moore_horspool_searcher(
                               key.begin(), key.end()
                                )
        );

        return itr != end ? itr - beg : std::string::npos;
    }

    static auto find(char *begin, const char *const end, const std::string &key)
    {
        std::vector<size_t> positions;

        auto beg = begin;
        size_t pos;

        do
        {
            pos = SubStringFinder::searchUsingBMH(beg, end, key);

            if(pos == std::string::npos)
                return std::move(positions);
            else
            {
                positions.push_back(pos + beg - begin);

                beg += pos + key.size();
            }

        }while(beg < end);

        return std::move(positions);
    }
}

#endif //ESETDEVCON_SUBSTRINGFINDER_H
