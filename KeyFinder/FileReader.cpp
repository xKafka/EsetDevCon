//
// Created by xkafka on 6/23/20.
//
#include <iostream>
#include <algorithm>
#include "FileReader.h"
/*
FileReader::FileReader(const std::string &fileName)
        : m_file(std::make_unique<std::fstream>(fileName)),
          m_iterator{}
{
 //   fileInit(fileName);
}
*/

FileReader::FileReader()
    : m_file(std::make_unique<std::fstream>()),
      m_iterator{}
{}
void FileReader::fileInit(const std::string &fileName) {

    if(m_file->is_open())
        m_file->close();
    else
        m_file->open(fileName);

    m_iterator.clr();
}

void FileReader::readNextChunkIntoBuffer(Buffer &buffer) {

    if(isOnEnd()) {
        std::cout << "eof\n";                   //here exception
        return;
    }

    m_file->read(buffer.bBegin(), buffer.bufferSize());

    buffer.resize(static_cast<size_t>(m_file->gcount()));
}

bool FileReader::isOnEnd() const {
    return m_file->eof();
}

void FileReader::setPosition(size_t pos) {

    if(isOnEnd())
        std::cout << "eof";

    m_file->clear();
    m_file->seekp(pos);
}

std::string FileReader::readSuffix(size_t position, size_t sufSize) {

    std::string suffix;

    auto iteratorPosition = m_file->tellp();

    while(sufSize-- && !isOnEnd())
    {
        setPosition(position++);
        suffix.push_back(m_file->peek());
    }

    if(*(suffix.end() - 1) == -1)
        suffix.pop_back();

    setPosition(iteratorPosition);

    return std::move(suffix);
}

std::string FileReader::readPrefix(size_t position, size_t prefSize) {

    std::string prefix;

    if(position < prefSize)
        prefSize -= position;

    auto iteratorPosition = m_file->tellp();

    while(prefSize--)
    {
        setPosition(position--);
        prefix.push_back(m_file->peek());
    }

    m_file->seekp(iteratorPosition);


 //   setPosition(iteratorPosition);

    return std::move(prefix);
}

FileIterator &FileReader::iterator() {
    return m_iterator;
}
