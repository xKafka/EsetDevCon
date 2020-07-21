//
// Created by xkafka on 7/11/20.
//

#ifndef ESETDEVCON_PARALLELQUEUECREATOR_H
#define ESETDEVCON_PARALLELQUEUECREATOR_H

#include "../../FileSorter/AdressList.h"
#include "ParallelQueue.h"

constexpr auto numOfThreads = 4;

namespace ParallelQueueCreator {

    static std::unique_ptr<ParallelQueue> p_parallelQueue = {};

    ParallelQueue *getParallelQueue(AdressList *adressList);
};


#endif //ESETDEVCON_PARALLELQUEUECREATOR_H
