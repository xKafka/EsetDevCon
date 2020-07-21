//
// Created by xkafka on 7/13/20.
//

#ifndef ESETDEVCON_ADRESSHOLDER_H
#define ESETDEVCON_ADRESSHOLDER_H

#include "../../FileSorter/AdressList.h"

class AdressHolder {

    std::vector<File*> m_data{};
    const std::string *m_rootPath{};

    size_t m_holdingSize{};

public:
    AdressHolder() = default;

    AdressHolder(File *pFile, const std::string *rootPath)
        : m_data(),
          m_rootPath(rootPath)
    {
        m_data.emplace_back(pFile);
        m_holdingSize += pFile->size();
    }

    void push(File *pFile)
    {
        m_data.emplace_back(pFile);

        m_holdingSize += pFile->size();
    }

    [[nodiscard]] auto &files() const { return m_data; }

};


#endif //ESETDEVCON_ADRESSHOLDER_H
