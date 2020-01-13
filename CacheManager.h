//
// Created by noa on 13/01/2020.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H

template <class Solution, class Problem>
class CacheManager {
public:
    bool isSoulutaionExist(Problem p);
    Solution getSolution(Problem p);
    void saveSolution(Problem p);
};

#endif //EX4_CACHEMANAGER_H
