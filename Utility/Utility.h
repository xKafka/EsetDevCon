//
// Created by xkafka on 7/8/20.
//

#ifndef ESETDEVCON_UTILITY_H
#define ESETDEVCON_UTILITY_H


namespace Utility {

    template<typename T> T &push_back_vec(T &to, T &from) {
        to.insert(to.end(), from.begin(), from.end());

        return to;
    }

};


#endif //ESETDEVCON_UTILITY_H
