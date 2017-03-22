//
// Created by jonathan on 16.03.17.
//

#include "MetronetOutputTest.h"

TEST_F(MetronetOutputTest, OutputLegalSystemsTxt) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    std::string filename;
    for (int i = 1; i <= TESTS_LEGAL; i++) {
        exp = new ExporterTXT();
        metronet = Metronet(exp);
        filename = "testInput/LegalSystemInput" + std::to_string(i) + ".xml";
        ASSERT_TRUE(FileExists(filename));
        ASSERT_TRUE(metronet.properlyInitialised());

        std::string outputName = "testOutput/LegalSystemOutput" + std::to_string(i) + ".txt";
        std::string expectedOutput = "testOutput/LegalSystemExpectedOutput" + std::to_string(i) + ".txt";
        std::ofstream output;
        output.open(outputName, std::ofstream::trunc);
        metronet.setup(filename, output);
        if (metronet.checkConsistent(output)){
            metronet.printMetronet(output);
            metronet.rondrijden(output);
        }
        output.close();
        ASSERT_TRUE(FileCompare(outputName, expectedOutput));
        metronet.reset();
        delete exp;
    }
}

TEST_F(MetronetOutputTest, OutputIllegalSystemsTxt) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    std::string filename;
    for (int i = 1; i <= TESTS_ILLEGAL; i++) {
        exp = new ExporterTXT();
        metronet = Metronet(exp);
        filename = "testInput/IllegalSystemInput" + std::to_string(i) + ".xml";
        ASSERT_TRUE(FileExists(filename));
        ASSERT_TRUE(metronet.properlyInitialised());

        std::string outputName = "testOutput/IllegalSystemOutput" + std::to_string(i) + ".txt";
        std::string expectedOutput = "testOutput/IllegalSystemExpectedOutput" + std::to_string(i) + ".txt";
        std::ofstream output;
        output.open(outputName, std::ofstream::trunc);
        metronet.setup(filename, output);
        if (metronet.checkConsistent(output)) {
            metronet.printMetronet(output);
            metronet.rondrijden(output);
        }
        output.close();
        ASSERT_TRUE(FileCompare(outputName, expectedOutput));
        metronet.reset();
        delete exp;
    }
}

TEST_F(MetronetOutputTest, OutputIncorrectSystemsTxt) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    std::string filename;
    for (int i = 1; i <= TESTS_INCORRECT; i++) {
        exp = new ExporterTXT();
        metronet = Metronet(exp);
        filename = "testInput/IncorrectSystemInput" + std::to_string(i) + ".xml";
        ASSERT_TRUE(FileExists(filename));
        ASSERT_TRUE(metronet.properlyInitialised());

        std::string outputName = "testOutput/IncorrectSystemOutput" + std::to_string(i) + ".txt";
        std::string expectedOutput = "testOutput/IncorrectSystemExpectedOutput" + std::to_string(i) + ".txt";
        std::ofstream output;
        output.open(outputName, std::ofstream::trunc);
        metronet.setup(filename, output);
        if (metronet.checkConsistent(output)) {
            metronet.printMetronet(output);
            metronet.rondrijden(output);
        }
        output.close();
        ASSERT_TRUE(FileCompare(outputName, expectedOutput));
        metronet.reset();
        delete exp;
    }
}

TEST_F(MetronetOutputTest, OutputSyntaxErrorSystemsTxt) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    std::string filename;
    for (int i = 1; i <= TESTS_SYNTAX; i++) {
        exp = new ExporterTXT();
        metronet = Metronet(exp);
        filename = "testInput/SyntaxErrorSystemInput" + std::to_string(i) + ".xml";
        ASSERT_TRUE(FileExists(filename));
        ASSERT_TRUE(metronet.properlyInitialised());

        std::string outputName = "testOutput/SyntaxErrorSystemOutput" + std::to_string(i) + ".txt";
        std::string expectedOutput = "testOutput/SyntaxErrorSystemExpectedOutput" + std::to_string(i) + ".txt";
        std::ofstream output;
        output.open(outputName, std::ofstream::trunc);
        if (metronet.setup(filename, output) != BadImport) {
            if (metronet.checkConsistent(output)) {
                metronet.printMetronet(output);
                metronet.rondrijden(output);
            }
        }
        output.close();
        ASSERT_TRUE(FileCompare(outputName, expectedOutput));
        metronet.reset();
        delete exp;
    }
}

TEST_F(MetronetOutputTest, OutputLegalSystemsHtml) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    std::string filename;
    for (int i = 1; i <= TESTS_LEGAL; i++) {
        exp = new ExporterHTML();
        metronet = Metronet(exp);
        filename = "testInput/LegalSystemInput" + std::to_string(i) + ".xml";
        ASSERT_TRUE(FileExists(filename));
        ASSERT_TRUE(metronet.properlyInitialised());

        std::string outputName = "testOutput/LegalSystemOutput" + std::to_string(i) + ".html";
        std::string expectedOutput = "testOutput/LegalSystemExpectedOutput" + std::to_string(i) + ".html";
        std::ofstream output;
        output.open(outputName, std::ofstream::trunc);
        metronet.setup(filename, output);
        if (metronet.checkConsistent(output)){
            metronet.printMetronet(output);
            metronet.rondrijden(output);
        }
        output.close();
        ASSERT_TRUE(FileCompare(outputName, expectedOutput));
        metronet.reset();
        delete exp;
    }
}

TEST_F(MetronetOutputTest, OutputIllegalSystemsHtml) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    std::string filename;
    for (int i = 1; i <= TESTS_ILLEGAL; i++) {
        exp = new ExporterHTML();
        metronet = Metronet(exp);
        filename = "testInput/IllegalSystemInput" + std::to_string(i) + ".xml";
        ASSERT_TRUE(FileExists(filename));
        ASSERT_TRUE(metronet.properlyInitialised());

        std::string outputName = "testOutput/IllegalSystemOutput" + std::to_string(i) + ".html";
        std::string expectedOutput = "testOutput/IllegalSystemExpectedOutput" + std::to_string(i) + ".html";
        std::ofstream output;
        output.open(outputName, std::ofstream::trunc);
        metronet.setup(filename, output);
        if (metronet.checkConsistent(output)) {
            metronet.printMetronet(output);
            metronet.rondrijden(output);
        }
        output.close();
        ASSERT_TRUE(FileCompare(outputName, expectedOutput));
        metronet.reset();
        delete exp;
    }
}

TEST_F(MetronetOutputTest, OutputIncorrectSystemsHtml) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    std::string filename;
    for (int i = 1; i <= TESTS_INCORRECT; i++) {
        exp = new ExporterHTML();
        metronet = Metronet(exp);
        filename = "testInput/IncorrectSystemInput" + std::to_string(i) + ".xml";
        ASSERT_TRUE(FileExists(filename));
        ASSERT_TRUE(metronet.properlyInitialised());

        std::string outputName = "testOutput/IncorrectSystemOutput" + std::to_string(i) + ".html";
        std::string expectedOutput = "testOutput/IncorrectSystemExpectedOutput" + std::to_string(i) + ".html";
        std::ofstream output;
        output.open(outputName, std::ofstream::trunc);
        metronet.setup(filename, output);
        if (metronet.checkConsistent(output)) {
            metronet.printMetronet(output);
            metronet.rondrijden(output);
        }
        output.close();
        ASSERT_TRUE(FileCompare(outputName, expectedOutput));
        metronet.reset();
        delete exp;
    }
}

TEST_F(MetronetOutputTest, OutputSyntaxErrorSystemsHtml) {
    ASSERT_TRUE(DirectoryExists("testInput"));
    std::string filename;
    for (int i = 1; i <= TESTS_SYNTAX; i++) {
        exp = new ExporterHTML();
        metronet = Metronet(exp);
        filename = "testInput/SyntaxErrorSystemInput" + std::to_string(i) + ".xml";
        ASSERT_TRUE(FileExists(filename));
        ASSERT_TRUE(metronet.properlyInitialised());

        std::string outputName = "testOutput/SyntaxErrorSystemOutput" + std::to_string(i) + ".html";
        std::string expectedOutput = "testOutput/SyntaxErrorSystemExpectedOutput" + std::to_string(i) + ".html";
        std::ofstream output;
        output.open(outputName, std::ofstream::trunc);
        if (metronet.setup(filename, output) != BadImport) {
            if (metronet.checkConsistent(output)) {
                metronet.printMetronet(output);
                metronet.rondrijden(output);
            }
        }
        output.close();
        ASSERT_TRUE(FileCompare(outputName, expectedOutput));
        metronet.reset();
        delete exp;
    }
}
