#include <iostream>
#include <fstream>
#include <sys/stat.h>

#include <ftw.h>

#include "KeyFinder/FileParser.h"
#include "Arguments/Args.h"
#include "FileSorter/AdressQueue.h"
#include "FileSorter/FTWSorter.h"

#include <fstream>

//since C++17 filesystem::file_size added ... this codes is built using C++14, which has not such feature

int main(int argc, const char *argv[]) {

    const std::string filePath(argv[1]);

    std::fstream fstr("/home/xkafka/Documents/Test/test.txt");

    Arguments::Args args = Arguments::Args::parseArgs(argc, argv);

    auto queue = FTWSorter::getQueue(args.path());      /// points to the created filequeue (points to unique_ptr)

    FileParser parser(args.key());

    for(const auto &q : *queue)
    {
        std::string str = queue->getNext();

        parser.changePath(str);
        std::cout << str << '\n';

        ParsingResult result = parser.parse();

        if(result.isFound()) {
            std::cout << str << '\n';
          //  parser.parse().print();
        }
    }

/*
    const std::string key = "time";

    FileParser parser("/home/xkafka/Documents/", key);

    parser.changePath("/home/xkafka/Documents/test.txt");
    parser.parse();

*/

    return 0;
}
