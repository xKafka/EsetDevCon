//
// Created by xkafka on 6/23/20.
//

#ifndef ESETDEVCON_ARGS_H
#define ESETDEVCON_ARGS_H

#include <string>

namespace Arguments {

    class Args {

        std::string m_key = {};
        std::string m_path = {};
        bool m_isParallel = false;

    public:
        Args() = default;
        Args(std::string &&key, std::string &&path, bool parallelize) : m_key(key), m_path(path), m_isParallel(parallelize) {}

        [[nodiscard]] std::string key() const { return m_key; }

        [[nodiscard]] std::string path() const { return m_path; }

        void goParallel() { m_isParallel = true; }

        [[nodiscard]] bool isParallel() const { return m_isParallel; }

        static Args parseArgs(int argc, const char *arg[]);

    };
}

#endif //ESETDEVCON_ARGS_H
