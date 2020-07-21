//
// Created by xkafka on 7/11/20.
//

#include "ParallelQueueCreator.h"


ParallelQueue *ParallelQueueCreator::getParallelQueue(AdressList *adressList) {

    if(!p_parallelQueue)
        p_parallelQueue = std::make_unique<ParallelQueue>(adressList, numOfThreads);
    else
        p_parallelQueue = {};

   // p_parallelQueue->construct(*adressList, numOfThreads);

    return p_parallelQueue.get();
}

