//#include "pch.h"
#include <vector>

class Stats
{
public:
    Stats() :average(0), min(0), max(0) {
    }

    double calculateAverage(const std::vector<double>& listOfNums);
    double findMax(const std::vector<double>& listOfNums);
    double findMin(const std::vector<double>& listOfNums);

    double average;
    double min;
    double max;
};

namespace Statistics {
    // define the Stats structure here. See the tests to infer its properties
    Stats ComputeStatistics(const std::initializer_list<double>);

}

    class IAlerter {

    };

    class StatsAlerter {
        double max_threshold;
        std::vector<IAlerter*> alerters;
    public:
        StatsAlerter() = default;
        StatsAlerter(const double threshold, const std::vector<IAlerter*> alerters):max_threshold(threshold),alerters(alerters) {
            //Constructor with two arguments
        }
        void checkAndAlert(const std::vector<double> alerterList);
    };

    class EmailAlert : public IAlerter {
    public:
        static bool emailSent;
    };

    class LEDAlert : public IAlerter {
    public:
        static bool ledGlows;
    };

