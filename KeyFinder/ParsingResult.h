//
// Created by xkafka on 6/24/20.
//

#ifndef ESETDEVCON_PARSINGRESULT_H
#define ESETDEVCON_PARSINGRESULT_H

#include <string>
#include <iostream>
#include <tuple>
#include <queue>

using cString = const std::string;
using tpl = std::tuple<cString , cString, size_t>;

struct ParsingResult {

    ParsingResult() = default;
    ParsingResult(ParsingResult &) = default;
    ParsingResult(ParsingResult &&) = default;

    std::vector<tpl> m_data;

    void push(cString &pref, cString &suf, size_t pos);
    [[nodiscard]] bool isFound() const;
    auto &at(size_t atPos);

    static std::ostream &printWithWhiteChars(std::ostream &out, const std::string &src);
    friend std::ostream &operator<<(std::ostream &out, ParsingResult &result);
};


#endif //ESETDEVCON_PARSINGRESULT_H
