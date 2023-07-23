//#include "pch.h"
#include "stats.h"

#include "gtest/gtest.h"
#include <cmath>

TEST(Statistics, ReportsAverageMinMax) {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    double epsilon = static_cast<double>(0.001);
    EXPECT_LT(std::abs(computedStats.average - 4.525), epsilon);
    EXPECT_LT(std::abs(computedStats.max - 8.9), epsilon);
    EXPECT_LT(std::abs(computedStats.min - 1.5), epsilon);
}

TEST(Statistics, AverageNaNForEmpty) {
    auto computedStats = Statistics::ComputeStatistics({});
    EXPECT_EQ(std::isnan(0.0), false);
    EXPECT_EQ(std::isnan(std::sqrt(-1)), true);
}

TEST(Alert, AlertsWhenMaxExceeds) {
    EmailAlert emailAlert;
    LEDAlert ledAlert;
    std::vector<IAlerter*> alerters = {&emailAlert, &ledAlert};
    
    const double maxThreshold = static_cast<double>(10.2);
    StatsAlerter statsAlerter(maxThreshold, alerters);
    statsAlerter.checkAndAlert({99.8, 34.2, 4.5, 6.7});

    EXPECT_TRUE(emailAlert.emailSent);
    EXPECT_TRUE(ledAlert.ledGlows);
}
