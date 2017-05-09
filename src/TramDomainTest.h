//
// Created by sergio on 03/05/17.
//

#ifndef SOFTENG_TRAMDOMAINTEST_H
#define SOFTENG_TRAMDOMAINTEST_H

#include <iostream>
#include <fstream>
#include <gtest/gtest.h>
#include <sys/stat.h>

#include "MetronetUtils.h"
#include "Tram.h"
#include "Passagier.h"
#include "Statistics.h"

/**
 * \brief MetronetDomainTest klasse die domein tests behandelt
 */
class TramDomainTest: public ::testing::Test {
protected:
    friend class Tram;

    virtual void SetUp() {};

    virtual void TearDown() {};

    StatisticsTram* statsA = new StatisticsTram(100);
    StatisticsTram* statsB = new StatisticsTram(100);
    Tram albatros = Tram(100, 60, 12, 1, "Albatros", "dummy", statsA);
    Tram pcc = Tram(100, 60, 12, 1, "PCC", "dummy", statsB);
    Passagier passagier;
};


#endif //SOFTENG_TRAMDOMAINTEST_H
