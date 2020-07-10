//
// Created by xkafka on 7/10/20.
//

#include "FTWSorter.h"

int FTWSorter::nftwfunc(const char filePath[], const struct stat *stat, int fileType) {

    switch (fileType) {
        case FTW_F:
            p_adressQueue->push(filePath + p_adressQueue->rootPath().size(), stat->st_size );
            break;

        case FTW_D:
            //do nothing
            break;


        default:
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

AdressQueue *FTWSorter::getQueue(const std::string &path) {
    if (!p_adressQueue)
        p_adressQueue = std::make_unique<AdressQueue>(path);
    else
        p_adressQueue = {};

    switch (ftw(path.c_str(), &nftwfunc, depth)) {
        case 0:
            return p_adressQueue.get();

    }
}