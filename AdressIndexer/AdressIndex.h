//
// Created by xkafka on 6/23/20.
//

#ifndef ESETDEVCON_ADRESSINDEX_H
#define ESETDEVCON_ADRESSINDEX_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>

using pr = std::pair<const std::string, size_t>;

namespace AdressIndexer
{
    struct AdressIndex {

        std::vector<pr> m_data;

        std::pair<const std::string, size_t> fileNameSize;
        const size_t size{};
        const std::string path{};

        AdressIndex() = default;
        AdressIndex(AdressIndex &&) = default;
        explicit AdressIndex(size_t size, const char *path);

    };
}


#endif //ESETDEVCON_ADRESSINDEX_H
