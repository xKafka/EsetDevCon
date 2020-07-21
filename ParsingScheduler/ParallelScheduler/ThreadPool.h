//
// Created by xkafka on 7/14/20.
//

#ifndef ESETDEVCON_THREADPOOL_H
#define ESETDEVCON_THREADPOOL_H


#include <vector>
#include <thread>

class ThreadPool {

public:
    explicit ThreadPool(int threadCount, const std::string &key);

    bool isFinished() noexcept;
    void stopThreads() noexcept;



};


#endif //ESETDEVCON_THREADPOOL_H
