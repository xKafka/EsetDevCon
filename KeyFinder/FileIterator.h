//
// Created by xkafka on 7/6/20.
//

#ifndef ESETDEVCON_FILEITERATOR_H
#define ESETDEVCON_FILEITERATOR_H

#include <cstddef>

///object of this class is position iterator from the begining of the file

class FileIterator {

    size_t m_position;

public:
    FileIterator() : m_position(0) {}
    FileIterator(FileIterator &) = delete;
    FileIterator(FileIterator &&) = delete;

    inline void clr() { m_position = 0; }

    [[nodiscard]] inline auto base() const { return m_position; }

    FileIterator &operator++() { ++m_position; return *this; }
    FileIterator &operator--() { --m_position; return *this; }
    FileIterator &operator+=(size_t toJmp) { m_position += toJmp; return *this; }
    FileIterator &operator-=(size_t toJmp) { m_position -= toJmp; return *this; }
};


#endif //ESETDEVCON_FILEITERATOR_H
