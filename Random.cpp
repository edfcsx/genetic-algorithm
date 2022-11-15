#include <random>
#include <vector>
#include "Random.h"

using namespace std;

random_device rd;
mt19937 mt(rd());

struct SafeRandomInterval {
    uint min;
    uint max;
};

SafeRandomInterval makeSafeRandomInterval(uint minNum, uint maxNum);

uint Random::randomUINT(uint minNum, uint maxNum)
{
    SafeRandomInterval interval = makeSafeRandomInterval(minNum, maxNum);

    uniform_int_distribution<uint> var(interval.min, interval.max);
    return var(mt);
}

std::vector<uint> Random::randomBatchUINT(uint minNum, uint maxNum, uint batchLength)
{
    SafeRandomInterval interval = makeSafeRandomInterval(minNum, maxNum);
    std::vector<uint> v = {};

    if (interval.max == interval.min) {
        v.push_back(interval.max);
        return v;
    }
    else if ((interval.max - interval.min) <= batchLength) {
        for (int i = (int)interval.min; i <= (int)interval.max; i++) {
            v.push_back(i);
        }

        return v;
    }

    uniform_int_distribution<uint> var(interval.min, interval.max);

    while (v.size() < batchLength) {
        uint num = var(mt);

        if (find(v.begin(), v.end(), num) == v.end())
            v.push_back(num);
    }

    return v;
}

SafeRandomInterval makeSafeRandomInterval(uint minNum, uint maxNum)
{
    SafeRandomInterval interval = {};

    if (maxNum > minNum) {
        interval.min = minNum;
        interval.max = maxNum;

        return interval;
    }

    interval.max = minNum;
    interval.min = maxNum;

    return interval;
}
