//
// Created by xkafka on 6/24/20.
//

#include "ParsingResult.h"
#include <algorithm>

std::ostream &ParsingResult::printWithWhiteChars(std::ostream &out, const std::string &src)
{
    for(const char &c : src)
    {
        switch(c)
        {
            case '\n': out << "\\n";
                break;
            case '\t': out << "\\t";
                break;
            case ' ' : out << "\\s";
                break;
            default:
                out << c;
        }
    }

    return out;
}

// ceknut regex ale na tomto velmi nezalezi

std::ostream &operator<<(std::ostream &out, ParsingResult &result)
{
    std::cout << "Result: " << result.m_data.size() << '\n';

    for(const auto&[pref, suf, pos] : result.m_data)
    {
        out <<  "Position:\n" << pos <<
                "\nPrefix:\n";
        ParsingResult::printWithWhiteChars(out, pref);
        out <<  "\nSuffix:\n";
        ParsingResult::printWithWhiteChars(out, suf);
        out << '\n';
    }

    return out;
}

void ParsingResult::push(cString &pref, cString &suf, size_t pos) {
    m_data.emplace_back(pref, suf, pos);
}

bool ParsingResult::isFound() const {
    return !m_data.empty();
}

auto &ParsingResult::at(size_t atPos) {
    return m_data.at(atPos);
}

void ParsingResult::print() {
    std::cout << "Result: " << m_data.size() << '\n';

    for(const auto&[pref, suf, pos] : m_data)
    {
        std::cout <<  "Position:\n" << pos <<
            "\nPrefix:\n";
        ParsingResult::printWithWhiteChars(std::cout, pref);
        std::cout <<  "\nSuffix:\n";
        ParsingResult::printWithWhiteChars(std::cout, suf);
        std::cout << '\n';
    }
}
