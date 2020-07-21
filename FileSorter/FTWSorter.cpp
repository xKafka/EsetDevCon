//
// Created by xkafka on 7/10/20.
//

#include "FTWSorter.h"

int FTWSorter::nftwfunc(const char filePath[], const struct stat *stat, int fileType) {

    switch (fileType) {
        case FTW_F:
            p_adressList->push(filePath + p_adressList->rootPath()->size(), stat->st_size);
            break;

        case FTW_D:
            //do nothing
            break;


        default:
            return EXIT_FAILURE;
    }
    //add another cases!!!!


    return EXIT_SUCCESS;
}

AdressList *FTWSorter::getAdressList(const std::string &path) {
    if (!p_adressList)
        p_adressList = std::make_unique<AdressList>(&path);
    else
        p_adressList = {};

    switch (ftw(path.c_str(), &nftwfunc, depth)) {
        case 0:
            return p_adressList.get();
    }


    // add another cases!!!!
}