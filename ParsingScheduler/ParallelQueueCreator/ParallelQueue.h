//
// Created by xkafka on 7/11/20.
//

#ifndef ESETDEVCON_PARALLELQUEUE_H
#define ESETDEVCON_PARALLELQUEUE_H

#include "../../FileSorter/File.h"
#include "AdressHolder.h"
#include <map>

using mMap = std::multimap<size_t, AdressHolder>;


class ParallelQueue {

    std::vector<AdressHolder> m_data{};

    mMap greedySort(AdressList &adressList, int8_t numOfThreads);

public:
    ParallelQueue() = default;
    ParallelQueue(AdressList *adressList, int8_t numOfThreads);

    auto &data() { return m_data; }
    void construct(AdressList &adressList, int8_t numOfThreads);

    [[nodiscard]] inline auto size() const { return m_data.size(); }

    inline AdressHolder &at(size_t pos);
};

#endif //ESETDEVCON_PARALLELQUEUE_H
