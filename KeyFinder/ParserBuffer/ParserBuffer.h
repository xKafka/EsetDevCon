//
// Created by xkafka on 7/1/20.
//

#ifndef ESETDEVCON_PARSERBUFFER_H
#define ESETDEVCON_PARSERBUFFER_H

#include <cstddef>
#include <string>

#include <ostream>

class Buffer
{
    std::string m_data;
    size_t m_swapSize;
    size_t m_bufferSize;
    size_t m_tBufferSize;

public:
    Buffer(const size_t bufferSize, const size_t swapSize)
        : m_bufferSize(bufferSize),
          m_swapSize(swapSize),
          m_data(),
          m_tBufferSize(m_bufferSize)
    {
        construct();
    }

    Buffer(Buffer &) = delete;
    Buffer(Buffer &&) = delete;

    inline void construct() { m_data.resize(m_bufferSize + m_swapSize); }

    [[nodiscard]] inline size_t swapSize() const { return m_swapSize; }
    [[nodiscard]] inline size_t bufferSize() const { return m_bufferSize; }

    inline void renew() { m_bufferSize = m_tBufferSize; m_data.resize(m_bufferSize); }

    auto *buffer() { return &m_data.at(m_swapSize); }
    auto *swap() { return &m_data.front(); }
    auto *data() { return swap(); }

    inline auto sBegin() { return swap(); }
    inline auto sEnd() { return swap() + m_swapSize; }
    inline auto bBegin() { return buffer(); }
    inline auto bEnd() { return buffer() + m_bufferSize; }

    [[nodiscard]] inline auto begin() -> char* { return swap(); }
    [[nodiscard]] inline auto end() -> const char* { return bEnd(); }

    [[nodiscard]] inline auto size() const { return m_data.size(); }

    inline void resize(size_t size) { m_bufferSize = size; }

    inline auto &atB(size_t pos) { return *(bBegin() + pos); }
    inline auto &atS(size_t pos) { return *(sBegin() + pos); }
    inline auto &at(size_t pos) { return *(m_data.data() + pos); }

    void initSwap() { std::copy(bEnd() - swapSize(), bEnd(), sBegin()); }

    friend std::ostream &operator<<(std::ostream &out, Buffer &buffer)
    {
        auto buffItr = buffer.bBegin();
        auto swapItr = buffer.sBegin();

        out << "Swap:   " << buffer.sEnd() - buffer.sBegin() << '\n';

        while(swapItr++ != buffer.sEnd())
            out << *swapItr;

        out << "Buffer:   " << buffer.bEnd() - buffer.bBegin() << '\n';
        while(buffItr++ != buffer.bEnd())
            out << *buffItr;

        out << '\n';

        return out;
    }
};

#endif //ESETDEVCON_PARSERBUFFER_H
