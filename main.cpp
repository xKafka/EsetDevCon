#include <iostream>
#include <fstream>
#include <sys/stat.h>

#include <ftw.h>

#include "KeyFinder/FileParser.h"
#include "Arguments/Args.h"
#include "FileSorter/AdressQueue.h"
#include "FileSorter/FTWSorter.h"

//since C++17 filesystem::file_size added ... this codes is built using C++14, which has not such feature

int main(int argc, const char *argv[]) {

    const std::string filePath(argv[1]);
    std::cout << filePath.size() << '\n';


    Arguments::Args args = Arguments::Args::parseArgs(argc, argv);

    auto queue = FTWSorter::getQueue(args.path());      /// points to the created filequeue (points to unique_ptr)

    for(const auto &q : *queue)
    {
        std::cout << queue->getNext() << '\n';
    }





/*

    size_t sum = 0;

    for(auto &qq : AdressIndexer::AdressQueue::files)
        sum += qq.size;

    const std::string key = "time";

    FileParser parser("/home/xkafka/Documents/", key);
*/


/*
    for(auto &qq : AdressIndexer::AdressQueue::files) {

        parser.changePath(qq.path);
        parser.parse();
    }
*/

    return 0;
}
