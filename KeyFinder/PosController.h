//
// Created by xkafka on 7/8/20.
//

#ifndef ESETDEVCON_POSCONTROLLER_H
#define ESETDEVCON_POSCONTROLLER_H

#include "ParserBuffer/ParserBuffer.h"
#include "FileReader.h"
#include "FileIterator.h"

///scans current position of file and buffer

class PosController
{
    Buffer &m_buffer;
    FileReader &m_reader;

    [[nodiscard]] std::string readPrefFromBuffer(size_t posInBuffer, size_t prefSize) const;
    [[nodiscard]] std::string readPrefFromFile(size_t posInFile, size_t prefSize) const;

    [[nodiscard]] std::string readSufFromBuffer(size_t posInBuffer, size_t prefSize) const;
    [[nodiscard]] std::string readSufFromFile(size_t posInFile, size_t sufSize) const;

public:
    PosController(Buffer &buffer, FileReader &reader)
            : m_buffer(buffer),
              m_reader(reader)
    {}
    PosController(PosController &) = delete;
    PosController(PosController &&) = delete;

    //destructor

    [[nodiscard]] size_t shiftPosition(size_t posInBuffer) const;

    [[nodiscard]] std::string readPrefix(size_t posInBuffer, size_t prefSize) const;
    [[nodiscard]] std::string readSuffix(size_t posInBuffer, size_t sufSize) const;
};

#endif //ESETDEVCON_POSCONTROLLER_H
