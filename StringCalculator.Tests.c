#include <assert.h>
#include <stdio.h>
#include "StringCalculator.h"

void testExpectZeroForEmptyInput() {
    assert(add("") == 0);
}

void testExpectZeroForSingleZero() {
    assert(add("0") == 0);
}

void testExpectSumForTwoNumbers() {
    assert(add("1,2") == 3);
}

void testExpectExceptionForNegativeNumbers() {
    if (fork() == 0) {
        add("-1,2");
        exit(0);
    } else {
        int status;
        wait(&status);
        assert(WEXITSTATUS(status) == 1);
    }
}

void testExpectExceptionForNegativeNumbers2() {
    if (fork() == 0) {
        add("1,-2,-3");
        exit(0);
    } else {
        int status;
        wait(&status);
        assert(WEXITSTATUS(status) == 1);
    }
}

void testExpectSumWithNewlineDelimiter() {
    assert(add("1\n2,3") == 6);
}

void testIgnoreNumbersGreaterThan1000() {
    assert(add("1,1001") == 1);
}

void testExpectSumWithCustomDelimiter() {
    assert(add("//;\n1;2") == 3);
}

void testExpectSumWithCustomDelimiter2() {
    assert(add("//[***]\n1***2***3") == 6);
}

void testAll() {
    testExpectZeroForEmptyInput();
    testExpectZeroForSingleZero();
    testExpectSumForTwoNumbers();
    testExpectExceptionForNegativeNumbers();
    testExpectExceptionForNegativeNumbers2();
    testExpectSumWithNewlineDelimiter();
    testIgnoreNumbersGreaterThan1000();
    testExpectSumWithCustomDelimiter();
    testExpectSumWithCustomDelimiter2();
    printf("All tests passed!\n");
}

int main() {
    testAll();
    return 0;
}
