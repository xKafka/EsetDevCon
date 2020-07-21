//
// Created by xkafka on 7/11/20.
//

#include "ParallelQueue.h"

using mMap = std::multimap<size_t, AdressHolder>;

ParallelQueue::ParallelQueue(AdressList *adressList, int8_t numOfThreads)
    : m_data(numOfThreads)
{
    construct(*adressList, numOfThreads);
}

void ParallelQueue::construct(AdressList &adressList, int8_t numOfThreads) {

   int i = 0;

   for(auto &m : greedySort(adressList, numOfThreads))
       m_data.at(i++) = std::move(m.second);
}

AdressHolder &ParallelQueue::at(size_t pos) {
    return m_data.at(pos);
}

mMap ParallelQueue::greedySort(AdressList &adressList, int8_t numOfThreads)
{
    const int adrSize = adressList.files().size();
    mMap map;

    for (int i = 0, j = adrSize - 1; i < numOfThreads; ++i, --j)
        map.emplace(adressList.at(j)->size(), AdressHolder { adressList.at(j) , adressList.rootPath() });

    for (int i = adrSize - numOfThreads - 1; i >= 0; --i) {

        auto node = map.extract(map.begin());

        node.mapped().push(adressList.at(i));

        node.key() += adressList.at(i)->size();
        map.insert(std::move(node));
    }

    return std::move(map);
}

