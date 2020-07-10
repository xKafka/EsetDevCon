cmake_minimum_required(VERSION 3.16)
project(EsetDevCon)

set(CMAKE_CXX_STANDARD 17)

add_executable(EsetDevCon main.cpp Arguments/Args.cpp Arguments/Args.h Arguments/InputArgsIndexes.h Arguments/Limits.h Arguments/LimitsException.cpp Arguments/LimitsException.h KeyFinder/FileParser.cpp KeyFinder/FileParser.h KeyFinder/FileReader.cpp KeyFinder/FileReader.h KeyFinder/ParsingResult.cpp KeyFinder/ParsingResult.h KeyFinder/SubstringFinder.h KeyFinder/ParserBuffer/ParserBuffer.h KeyFinder/FileIterator.h Utility/Utility.h KeyFinder/PosController.cpp KeyFinder/PosController.h FileSorter/File.cpp FileSorter/File.h FileSorter/AdressQueue.cpp FileSorter/AdressQueue.h FileSorter/FTWSorter.cpp FileSorter/FTWSorter.h)