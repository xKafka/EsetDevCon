//
// Created by xkafka on 7/10/20.
//

#ifndef ESETDEVCON_FTWSORTER_H
#define ESETDEVCON_FTWSORTER_H

#include "AdressQueue.h"

constexpr auto depth = 10;

namespace FTWSorter {

    static std::unique_ptr<AdressQueue> p_adressQueue = {};

    int nftwfunc(const char filePath[], const struct stat *stat, int fileType);

    AdressQueue *getQueue(const std::string &path);

}

#endif //ESETDEVCON_FTWSORTER_H
