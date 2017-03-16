/*
 * MetronetInputTests.cpp
 *
 *  Created on: 10 Mar 2017
 *      Author: Dawid
 */

#include "MetronetInputTest.h"

TEST_F(MetronetInputTest, InputHappyDay) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    ASSERT_TRUE(FileExists("testInput/HappyDayInput.xml"));
    ASSERT_TRUE(metronet.properlyInitialised());

    std::ostream dummy(0);
    Parser p(exp);
    p.setup(metronet, "testInput/HappyDayInput.xml", dummy);

    if (metronet.checkConsistent(exp, dummy)) endResult = Succes;
    else endResult = PartialImport;

    Station* A = metronet.getStations()["A"];
    if (A->getNaam() != "A") endResult = BadImport;
    if (A->getVolgende() != "B") endResult = BadImport;
    if (A->getVorige() != "C") endResult = BadImport;
    if (A->getSpoor() != 12) endResult = BadImport;
    if (A->getAfstappen() != 0) endResult = BadImport;
    if (A->getOpstappen() != 0) endResult = BadImport;

    Station* B = metronet.getStations()["B"];
    if (B->getNaam() != "B") endResult = BadImport;
    if (B->getVolgende() != "C") endResult = BadImport;
    if (B->getVorige() != "A") endResult = BadImport;
    if (B->getSpoor() != 12) endResult = BadImport;
    if (B->getAfstappen() != 0) endResult = BadImport;
    if (B->getOpstappen() != 0) endResult = BadImport;

    Station* C = metronet.getStations()["C"];
    if (C->getNaam() != "C") endResult = BadImport;
    if (C->getVolgende() != "A") endResult = BadImport;
    if (C->getVorige() != "B") endResult = BadImport;
    if (C->getSpoor() != 12) endResult = BadImport;
    if (C->getAfstappen() != 0) endResult = BadImport;
    if (C->getOpstappen() != 0) endResult = BadImport;

    Tram* t12 = metronet.getTrams()[12];
    if (t12->getSpoor() != 12) endResult = BadImport;
    if (t12->getZitplaatsen() != 32) endResult = BadImport;
    if (t12->getSnelheid() != 60) endResult = BadImport;
    if (t12->getBeginStation() != "A") endResult = BadImport;
    ASSERT_EQ(endResult, Succes);
}

TEST_F(MetronetInputTest, InputLegalSystems1) {
    ASSERT_TRUE(DirectoryExists("testInput"));

}

TEST_F(MetronetInputTest, InputLegalSystems2) {
    ASSERT_TRUE(DirectoryExists("testInput"));
}

TEST_F(MetronetInputTest, InputLegalSystems3) {
    ASSERT_TRUE(DirectoryExists("testInput"));
}

TEST_F(MetronetInputTest, InputIllegalSystems1) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    ASSERT_TRUE(FileExists("testInput/IllegalSystemInput1.xml"));
    ASSERT_TRUE(metronet.properlyInitialised());

    std::ostream dummy(0);
    Parser p(exp);
    p.setup(metronet, "testInput/IllegalSystemInput1.xml", dummy);
    ASSERT_FALSE(metronet.checkConsistent(exp, dummy));
}

TEST_F(MetronetInputTest, InputIllegalSystems2) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    ASSERT_TRUE(FileExists("testInput/IllegalSystemInput2.xml"));
    ASSERT_TRUE(metronet.properlyInitialised());

    std::ostream dummy(0);
    Parser p(exp);

    p.setup(metronet, "testInput/IllegalSystemInput2.xml", dummy);
    ASSERT_FALSE(metronet.checkConsistent(exp, dummy));
}

TEST_F(MetronetInputTest, InputIllegalSystems3) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    ASSERT_TRUE(FileExists("testInput/IllegalSystemInput3.xml"));
    ASSERT_TRUE(metronet.properlyInitialised());

    std::ostream dummy(0);
    Parser p(exp);

    p.setup(metronet, "testInput/IllegalSystemInput3.xml", dummy);
    ASSERT_FALSE(metronet.checkConsistent(exp, dummy));
}

TEST_F(MetronetInputTest, InputIncorrectSystems1) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    ASSERT_TRUE(FileExists("testInput/IncorrectSystemsInput1.xml"));
    ASSERT_TRUE(metronet.properlyInitialised());

    std::ostream dummy(0);
    Parser p(exp);

    ASSERT_FALSE(p.setup(metronet, "testInput/IncorrectSystemsInput1.xml", dummy));
}

TEST_F(MetronetInputTest, InputIncorrectSystems2) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    ASSERT_TRUE(FileExists("testInput/IncorrectSystemsInput2.xml"));
    ASSERT_TRUE(metronet.properlyInitialised());

    std::ostream dummy(0);
    Parser p(exp);

    ASSERT_FALSE(p.setup(metronet, "testInput/IncorrectSystemsInput2.xml", dummy));
}

TEST_F(MetronetInputTest, InputSyntaxErrorSystems1) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    ASSERT_TRUE(FileExists("testInput/SyntaxErrorSystemsInput1.xml"));
    ASSERT_TRUE(metronet.properlyInitialised());

    std::ostream dummy(0);
    Parser p(exp);

    ASSERT_FALSE(p.setup(metronet, "testInput/SyntaxErrorSystemsInput1.xml", dummy));
}

TEST_F(MetronetInputTest, InputSyntaxErrorSystems2) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    ASSERT_TRUE(FileExists("testInput/SyntaxErrorSystemsInput2.xml"));
    ASSERT_TRUE(metronet.properlyInitialised());

    std::ostream dummy(0);
    Parser p(exp);

    ASSERT_FALSE(p.setup(metronet, "testInput/SyntaxErrorSystemsInput2.xml", dummy));
}