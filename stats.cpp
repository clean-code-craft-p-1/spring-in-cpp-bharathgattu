//#include "pch.h"

#include "stats.h"
#include<memory>
#include<iostream>

bool EmailAlert::emailSent = 0;
bool LEDAlert::ledGlows = 0;

//Calculates average of numbers
double calculateAverage(const std::vector<double>& listOfNums)
{
    double sum = 0;
    int count = 0;

    for (auto v : listOfNums)
    {
        sum += v;
        count += 1;
    }

    std::cout << "sum=" << sum << "count=" << count << std::endl;
    
    return sum /static_cast<double>(count);
}

//Find max number in the list
double findMax(const std::vector<double>& listOfNums)
{
    if (!listOfNums.empty())
    {
        double max = listOfNums[0];
        for (auto v : listOfNums)
        {
            max = std::max(v, max);
        }

        std::cout << "max=" << max << std::endl;
        return max;
    }
    std::cout << "empty list" << std::endl;
    return 0;
}

//Find min number in the list
double findMin(const std::vector<double>& listOfNums)
{
    if (!listOfNums.empty())
    {
        double min = listOfNums[0];
        for (auto v : listOfNums)
        {
            min = std::min(v, min);
        }

        std::cout << "min=" << min << std::endl;
        return min;
    }
    std::cout << "empty list" << std::endl;
    return 0;
}

Stats Statistics::ComputeStatistics(const std::initializer_list<double> listOfNums) {
    //Implement statistics here
    std::unique_ptr<Stats> statsPtr = std::make_unique<Stats>();

    statsPtr->average = calculateAverage(listOfNums);
    statsPtr->max = findMax(listOfNums);
    statsPtr->min = findMin(listOfNums);

    return *statsPtr;
}

void StatsAlerter::checkAndAlert(const std::vector<double> listOfNums) {
    EmailAlert::emailSent = false;
    LEDAlert::ledGlows = false;
    for (auto v : listOfNums) {
        if (v > max_threshold) {
            EmailAlert::emailSent = true;
            LEDAlert::ledGlows = true;
        }
    }
}
