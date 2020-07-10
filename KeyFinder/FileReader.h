//
// Created by xkafka on 6/23/20.
//

#ifndef ESETDEVCON_FILEREADER_H
#define ESETDEVCON_FILEREADER_H

#include <fstream>
#include <string>
#include <utility>
#include <memory>

#include "ParsingResult.h"
#include "ParserBuffer/ParserBuffer.h"
#include "FileIterator.h"

/*
 * FileReader opens the file and reads next chunk of text into the buffer
 * buffer is used via reference on it (avoiding copies). Size of buffer (default = 2048)
 */

class FileReader {

    std::unique_ptr<std::fstream> m_file;
    FileIterator m_iterator;

    //function show EOF

public:
   // FileReader() = default;
    FileReader(FileReader &) = delete;
    FileReader(FileReader &&) = delete;

    //construct FileReader and creat unique_ptr on file
    FileReader();

    //init next file
    void fileInit(const std::string &fileName);

    //read into buffer
    void readNextChunkIntoBuffer(Buffer &buffer);

    void setPosition(size_t pos);
    [[nodiscard]] inline bool isOnEnd() const;

    std::string readPrefix(size_t pos, size_t prefSize);
    std::string readSuffix(size_t pos, size_t sufSize);

    FileIterator &iterator(); // dangerous construction
};

#endif //ESETDEVCON_FILEREADER_H
