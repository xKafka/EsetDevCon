//
// Created by xkafka on 6/23/20.
//

#ifndef ESETDEVCON_ADRESSQUEUE_H
#define ESETDEVCON_ADRESSQUEUE_H

#include <queue>

#include "AdressIndex.h"

namespace AdressIndexer {

    int ftwCallBack(const char filepath[], const struct stat *stat, int fileType)
    {

    }

    namespace AdressQueue {

       static std::vector<AdressIndex> files;
    };
}
/*
int ftwCallback(const char filePath[], const struct stat *stat, int fileType)
{
    switch(fileType) {
        case FTW_F:
        {
            AdressIndexer::AdressIndex indexer(stat->st_size, filePath);
            AdressIndexer::AdressQueue::files.push_back(std::move(indexer));
        }
            break;

        case FTW_D:
            break;

        default:
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
int main(int argc, const char *argv[]) {

    const std::string filePath(argv[1]);
    std::cout << argv[1] << '\n';

    switch(ftw(filePath.c_str(), &ftwCallback, 10))
    {

    }
    size_t sum = 0;

    for(auto &qq : AdressIndexer::AdressQueue::files)
        sum += qq.size;

    const std::string key = "time";

    FileParser parser("/home/xkafka/Documents/", key);


    for(auto &qq : AdressIndexer::AdressQueue::files) {

        parser.changePath(qq.path);
        parser.parse();
    }

*/

//extern a definovat v zdrojaku inak sa povytvara viac krat pri viacnasobmom definovani


#endif //ESETDEVCON_ADRESSQUEUE_H
