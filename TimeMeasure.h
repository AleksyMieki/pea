//
// Created by aleks on 20.10.22.
//

#ifndef PEA_1_TIMEMEASURE_H
#define PEA_1_TIMEMEASURE_H
#include <chrono>
#include <iostream>
#include <random>
#include <algorithm>
#include "Graph.h"
typedef unsigned long long timedata;

class TimeMeasure {

private:

    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<double> elapsed = std::chrono::duration<double>::zero();
    std::size_t times = 0;

    void benchmarkStart()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    void benchmarkStop()
    {
        end = std::chrono::high_resolution_clock::now();

        elapsed += end - start;
        times++;
    }
    timedata getAvgElapsedNsec()
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count() / times;
    }
public:

    timedata benchmarkBruteForce();
};


#endif //PEA_1_TIMEMEASURE_H
