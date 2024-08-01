#include <gtest/gtest.h>
#include "StringCalculator.h"

TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expectedresult = 0;
    std::string input = "";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
    int expectedresult = 0;
    std::string input = "0";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
    int expectedresult = 3;
    std::string input = "1,2";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectExceptionForNegativeNumbers) {
    ASSERT_THROW({
        std::string input = "-1,2";
        StringCalculator objUnderTest;
       objUnderTest.add(input);
        }, std::runtime_error);
}

TEST(StringCalculatorAddTests, ExpectExceptionForNegativeNumbers2) {
    ASSERT_THROW({
        std::string input = "1,-2,-3";
        StringCalculator objUnderTest;
       objUnderTest.add(input);
        }, std::runtime_error);
}

TEST(StringCalculatorAddTests, ExpectExceptionForNegativeNumbers3) {
    ASSERT_THROW({
        std::string input = "1,-2";
        StringCalculator objUnderTest;
       objUnderTest.add(input);
        }, std::runtime_error);
}

TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
    int expectedresult = 6;
    std::string input = "1\n2,3";
     StringCalculator objUnderTest;
    int result =objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    int expectedresult = 1;
    std::string input = "1,1001";
    StringCalculator objUnderTest;
    int result =objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan10002) {
    int expectedresult = 2;
    std::string input = "2,1001";
    StringCalculator objUnderTest;
    int result =objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
    int expectedresult = 3;
    std::string input = "//;\n1;2";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter2) {
    int expectedresult = 6;
    std::string input = "//[***]\n1***2***3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter3) {
    int expectedresult = 6;
    std::string input = "1\n2\n3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter4) {
    int expectedresult = 6;
    std::string input = "1\n2,3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter5) {
    int expectedresult = 1;
    std::string input = "//[*][%]\n1*2%3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter6) {
    int expectedresult = 1;
    std::string input = "1]2[3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter7) {
    int expectedresult = 1;
    std::string input = "//[***][%%%]\n1***2%%%3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter8) {
    int expectedresult = 2;
    std::string input = "//;\n2;1001";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}


TEST(StringCalculatorAddTests, ExpectSumForoneNumber1) {
    int expectedresult = 1;
    std::string input = "1";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumForfiveNumber1) {
    int expectedresult = 15;
    std::string input = "1,2,3,4,5";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}
