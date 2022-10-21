#include <iostream>
#include "Graph.h"
#include "TimeMeasure.h"

int main() {

    auto stopwatch = new TimeMeasure();

    std::cout << stopwatch->benchmarkBruteForce() << "ns";

    delete stopwatch;
    return 0;
}
