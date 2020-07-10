//
// Created by xkafka on 7/9/20.
//

#ifndef ESETDEVCON_ADRESSQUEUE_H
#define ESETDEVCON_ADRESSQUEUE_H

#include <string>
#include <memory>
#include <utility>
#include <vector>
#include <iostream>
#include "File.h"

#include <ftw.h>

//could be made as a singleton

using fVector = std::vector<File>;

class AdressQueue
{
    fVector m_files;
    std::string m_rootPath;
    mutable size_t m_queueIterator;

public:
    AdressQueue() = default;
    explicit AdressQueue(const std::string &rootPath)   ///copies rootPath from Args, one copyfor every thread
        : m_rootPath(rootPath),
          m_queueIterator(0)
    {
    }
    AdressQueue(AdressQueue &) = delete;
    AdressQueue(AdressQueue &&) = delete;

    void push(const char *filePath, const size_t size)
    {
        m_files.emplace_back(filePath, size);
    }

    /// dangerous constructs, returns references to private variables

    [[nodiscard]] auto &files() const { return m_files; }
    [[nodiscard]] auto &rootPath() const { return m_rootPath; }

    auto begin() { return m_files.begin(); }
    auto end() { return m_files.end(); }

    auto getNext() const { return m_rootPath + m_files.at(m_queueIterator++).path();}
};


#endif //ESETDEVCON_ADRESSQUEUE_H
