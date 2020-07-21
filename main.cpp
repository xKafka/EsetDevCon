#include <iostream>
#include <fstream>
#include <sys/stat.h>

#include <ftw.h>

#include "KeyFinder/FileParser.h"
#include "Arguments/Args.h"
#include "FileSorter/AdressList.h"
#include "FileSorter/FTWSorter.h"
#include "ParsingScheduler/ParallelQueueCreator/ParallelQueueCreator.h"

#include <fstream>

//since C++17 filesystem::file_size added ... this codes is built using C++14, which has not such feature

int main(int argc, const char *argv[]) {

    const std::string filePath(argv[1]);

    Arguments::Args args = Arguments::Args::parseArgs(argc, argv);

    auto queue = FTWSorter::getAdressList(args.path());      /// points to the created filequeue (points to unique_ptr)

    auto parallelQueue = ParallelQueueCreator::getParallelQueue(queue);

    FileParser parser(args.key());



    return 0;
}
