//
// Created by xkafka on 7/8/20.
//

#include "PosController.h"

size_t PosController::shiftPosition(size_t posInBuffer) const {

    return m_reader.iterator().base() + posInBuffer - m_buffer.swapSize();
}

std::string PosController::readPrefFromBuffer(size_t pos, const size_t prefSize) const {

    std::string pref;
    size_t currPos = pos;

    while(currPos-- != pos - prefSize)          // read from buffer
        pref.push_back(m_buffer.at(currPos));

    return std::move(pref);
}

std::string PosController::readPrefFromFile(size_t posInFile, size_t prefSize) const {

    return m_reader.readPrefix(posInFile, prefSize);
}

std::string PosController::readPrefix(size_t pos, size_t prefSize) const {

    if(pos <= prefSize)
        return readPrefFromFile(shiftPosition(--pos), prefSize);
    else
        return readPrefFromBuffer(pos, prefSize);
}

std::string PosController::readSufFromBuffer(size_t pos, size_t sufSize) const
{
    std::string suf;
    pos += m_buffer.swapSize() - 1;
    size_t currPos = pos;

    while(currPos++ != pos + sufSize)          // read from buffer
        suf.push_back(m_buffer.at(currPos));

    return std::move(suf);
}

std::string PosController::readSufFromFile(size_t posInFile, size_t sufSize) const
{
    return m_reader.readSuffix(posInFile, sufSize);
}

std::string PosController::readSuffix(size_t pos, size_t sufSize) const
{
    if(pos > m_buffer.size() - sufSize)
        return readSufFromFile(shiftPosition(pos), sufSize);
    else
        return readSufFromBuffer(pos, sufSize);
}
