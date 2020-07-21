//
// Created by xkafka on 7/11/20.
//

#ifndef ESETDEVCON_PARSINGSCHEDULER_H
#define ESETDEVCON_PARSINGSCHEDULER_H

#include "../FileSorter/AdressList.h"
#include "../KeyFinder/ParsingResult.h"

namespace ParsingScheduler {

    class ParsingScheduler {

    public:
        explicit ParsingScheduler(AdressList *fileQueue) noexcept;

        virtual ~ParsingScheduler() = default;

        virtual std::vector<ParsingResult> run() = 0;
        [[nodiscard]] virtual bool isFinished() const;

    protected:
        std::string nextFileName() const;

    private:
        AdressList *m_queue;
    };
}



#endif //ESETDEVCON_PARSINGSCHEDULER_H
