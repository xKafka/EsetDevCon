//
// Created by xkafka on 6/23/20.
//

#ifndef ESETDEVCON_FILEPARSER_H
#define ESETDEVCON_FILEPARSER_H

#include "FileReader.h"
#include "FileIterator.h"
#include "PosController.h"

class FileParser {

    FileReader m_reader;
    Buffer m_buffer;
    PosController m_posController;
    const std::string m_key;

    template<typename F> void iterateInText(F textIterator);
    void searchInText(ParsingResult &result);

public:
    FileParser(FileParser &) = delete;
    FileParser(FileParser &&) = delete;

    explicit FileParser(const std::string &key);

    void changePath(const std::string &path);
    ParsingResult parse();

    void processPositions(std::vector<size_t> pos, ParsingResult &result);
};


#endif //ESETDEVCON_FILEPARSER_H
