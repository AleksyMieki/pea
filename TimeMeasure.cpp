//
// Created by aleks on 20.10.22.
//

#include "TimeMeasure.h"

timedata TimeMeasure::benchmarkBruteForce() {

    auto graph = new Graph();

        benchmarkStart();

        graph->brute_force();

        benchmarkStop();

    delete graph;
    return getAvgElapsedNsec();
}
