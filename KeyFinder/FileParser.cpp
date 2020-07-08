//
// Created by xkafka on 6/23/20.
//

#include <algorithm>
#include <iostream>

#include "SubstringFinder.h"
#include "FileParser.h"
#include "PosController.h"

constexpr size_t bufferSize = 2048;
constexpr size_t prefSize = 3;
constexpr size_t sufSize = 3;

FileParser::FileParser(const std::string &fileName, const std::string &key)
    : m_reader(fileName),
      m_buffer(bufferSize, key.size() - 1),
      m_key(key),
      m_posController(m_buffer, m_reader)
{}

void FileParser::changePath(const std::string &path) {

    m_buffer.renew();
    m_reader.fileInit(path);
}

ParsingResult FileParser::parse() {

    ParsingResult result;

    searchInText(result);

    return result;
}

template<typename F>
void FileParser::iterateInText(F textIterator) {

    do
    {
        m_reader.readNextChunkIntoBuffer(m_buffer);

        textIterator();

        m_buffer.initSwap();

        m_reader.iterator() += m_buffer.bufferSize();
    }while(!m_reader.isOnEnd());
}

void FileParser::searchInText(ParsingResult &result) {

    iterateInText([this, &result]()
    {
        processPositions(
                        SubStringFinder::find(m_buffer.begin(), m_buffer.end(), m_key),
                        result
                        );
    });

    std::cout << result;
}

void FileParser::processPositions(std::vector<size_t> pos, ParsingResult &result) {

    if(pos.empty())
        return;

    for(const auto &p : pos)
        result.push(
                m_posController.readPrefix(p, prefSize),
                m_posController.readSuffix(p, sufSize),
                m_posController.shiftPosition(p)
                );
}
