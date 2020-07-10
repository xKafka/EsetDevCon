//
// Created by xkafka on 7/8/20.
//

#ifndef ESETDEVCON_FILE_H
#define ESETDEVCON_FILE_H

#include <string>

class File {

    std::string m_path;
    size_t m_size;

public:
    File() = delete;
    File(const char *path, size_t size)
        : m_path(path),
          m_size(size)
    { }

    [[nodiscard]] auto &path() const { return m_path; }
    [[nodiscard]] auto &size() const { return m_size; }
};

#endif //ESETDEVCON_FILE_H
