#include "StringCalculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void processCustomDelimiter(const char *numbers, char **numStr, char delimiters[10][10], int *delimiterCount);
int isDelimiter(char c, char delimiters[10][10], int delimiterCount);
int splitAndParse(const char *str, char delimiters[10][10], int delimiterCount, int *nums);
void checkForNegatives(int *nums, int count);
int calculateSum(int *nums, int count);

int add(const char *numbers) {
    if (numbers == NULL || strlen(numbers) == 0) {
        return 0;
    }

    char delimiters[10][10] = { ",", "\n" };
    int delimiterCount = 2;
    char *numStr = strdup(numbers);

    if (strncmp(numbers, "//", 2) == 0) {
        processCustomDelimiter(numbers, &numStr, delimiters, &delimiterCount);
    }

    int nums[1000];
    int count = splitAndParse(numStr, delimiters, delimiterCount, nums);
    checkForNegatives(nums, count);

    free(numStr);
    return calculateSum(nums, count);
}

void processCustomDelimiter(const char *numbers, char **numStr, char delimiters[10][10], int *delimiterCount) {
    const char *delimiter_end = strstr(numbers, "\n");
    if (delimiter_end) {
        strncpy(*numStr, delimiter_end + 1, strlen(delimiter_end));
        char delimiter_spec[100] = { 0 };
        strncpy(delimiter_spec, numbers + 2, delimiter_end - numbers - 2);

        if (delimiter_spec[0] == '[') {
            const char *start = delimiter_spec;
            const char *end;
            while ((end = strstr(start, "][")) != NULL) {
                strncpy(delimiters[(*delimiterCount)++], start + 1, end - start - 1);
                start = end + 1;
            }
            strncpy(delimiters[(*delimiterCount)++], start + 1, strchr(start, ']') - start - 1);
        } else {
            strncpy(delimiters[(*delimiterCount)++], delimiter_spec, strlen(delimiter_spec));
        }
    }
}

int isDelimiter(char c, char delimiters[10][10], int delimiterCount) {
    for (int i = 0; i < delimiterCount; i++) {
        if (strchr(delimiters[i], c) != NULL) {
            return 1;
        }
    }
    return 0;
}

int splitAndParse(const char *str, char delimiters[10][10], int delimiterCount, int *nums) {
    int count = 0;
    const char *start = str;
    const char *end = str;

    while (*end) {
        if (isDelimiter(*end, delimiters, delimiterCount)) {
            if (start != end) {
                nums[count++] = atoi(start);
            }
            start = end + 1;
        }
        end++;
    }

    if (start != end) {
        nums[count++] = atoi(start);
    }

    return count;
}

void checkForNegatives(int *nums, int count) {
    int negatives[1000];
    int negCount = 0;

    for (int i = 0; i < count; i++) {
        if (nums[i] < 0) {
            negatives[negCount++] = nums[i];
        }
    }

    if (negCount > 0) {
        printf("negatives not allowed: ");
        for (int i = 0; i < negCount; i++) {
            printf("%d ", negatives[i]);
        }
        printf("\n");
        exit(1);
    }
}

int calculateSum(int *nums, int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        if (nums[i] <= 1000) {
            sum += nums[i];
        }
    }
    return sum;
}
