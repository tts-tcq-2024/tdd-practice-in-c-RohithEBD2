#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "StringCalculator.h"
void processCustomDelimiter(const std::string& numbers, std::vector<std::string>& delimiters, std::string& numStr);
std::vector<std::string> parseDelimiters(const std::string& delimiter_spec);
std::vector<int> splitAndParse(const std::string& str, const std::vector<std::string>& delimiters);
size_t findFirstDelimiter(const std::string& str, size_t start, const std::vector<std::string>& delimiters);
size_t findDelimiterIndex(const std::string& str, size_t pos, const std::vector<std::string>& delimiters);
void addNumber(const std::string& token, std::vector<int>& nums);
void checkForNegatives(const std::vector<int>& nums);
void throwNegativeException(const std::vector<int>& negatives);
int calculateSum(const std::vector<int>& nums);
void checknegutils(std::vector<int> negatives);
void whiledelim(size_t end,std::vector<std::string> delimiters, const std::string& delimiter_spec,size_t start);


    int StringCalculator::add(const std::string& numbers) {
        if (numbers.empty()) {
            return 0;
        }

        std::vector<std::string> delimiters = { ",", "\n" };
        std::string numStr = numbers;

        if (numbers.substr(0, 2) == "//") {
            processCustomDelimiter(numbers, delimiters, numStr);
        }

        std::vector<int> nums = splitAndParse(numStr, delimiters);
        checkForNegatives(nums);

        return calculateSum(nums);
    }


    void processCustomDelimiter(const std::string& numbers, std::vector<std::string>& delimiters, std::string& numStr) {
        size_t delimiter_end = numbers.find("\n");
        std::string delimiter_spec = numbers.substr(2, delimiter_end - 2);
        delimiters = parseDelimiters(delimiter_spec);
        numStr = numbers.substr(delimiter_end + 1);
    }

void whiledelim(size_t end,std::vector<std::string> delimiters, const std::string& delimiter_spec,size_t start){
while (end != std::string::npos) {
                delimiters.push_back(delimiter_spec.substr(start + 1, end - start - 1));
                start = end + 1;
                end = delimiter_spec.find("][", start);
            }
}

    std::vector<std::string> parseDelimiters(const std::string& delimiter_spec) {
        std::vector<std::string> delimiters;
        if (delimiter_spec.front() == '[' && delimiter_spec.back() == ']') {
            size_t start = 0;
            size_t end = delimiter_spec.find("][", start);
            whiledelim(end,delimiters,delimiter_spec,start);
            delimiters.push_back(delimiter_spec.substr(start + 1, delimiter_spec.length() - start - 2));
        } else {
            delimiters.push_back(delimiter_spec);
        }
        return delimiters;
    }

    std::vector<int> splitAndParse(const std::string& str, const std::vector<std::string>& delimiters) {
        std::vector<int> nums;
        size_t start = 0;
        size_t end = findFirstDelimiter(str, start, delimiters);
        while (end != std::string::npos) {
            addNumber(str.substr(start, end - start), nums);
            start = end + delimiters[findDelimiterIndex(str, end, delimiters)].length();
            end = findFirstDelimiter(str, start, delimiters);
        }
        if (start < str.size()) {
            addNumber(str.substr(start), nums);
        }
        return nums;
    }

    size_t findFirstDelimiter(const std::string& str, size_t start, const std::vector<std::string>& delimiters) {
        size_t min_pos = std::string::npos;
        for (const std::string& delimiter : delimiters) {
            size_t pos = str.find(delimiter, start);
            if (pos < min_pos) {
                min_pos = pos;
            }
        }
        return min_pos;
    }

    size_t findDelimiterIndex(const std::string& str, size_t pos, const std::vector<std::string>& delimiters) {
        for (size_t i = 0; i < delimiters.size(); ++i) {
            if (str.substr(pos, delimiters[i].length()) == delimiters[i]) {
                return i;
            }
        }
        return std::string::npos;
    }

    void addNumber(const std::string& token, std::vector<int>& nums) {
        if (!token.empty()) {
            nums.push_back(std::stoi(token));
        }
    }

   void checknegutils(std::vector<int> negatives){
    if (!negatives.empty()) {
            throwNegativeException(negatives);
        }
    }

    void checkForNegatives(const std::vector<int>& nums) {
        std::vector<int> negatives;
        for (int num : nums) {
            if (num < 0) {
                negatives.push_back(num);
            }
        }

        checknegutils(negatives);
        
    }

    void throwNegativeException(const std::vector<int>& negatives) {
        std::ostringstream oss;
        oss << "negatives not allowed: ";
        for (size_t i = 0; i < negatives.size(); ++i) {
            if (i > 0) {
                oss << ", ";
            }
            oss << negatives[i];
        }
        throw std::runtime_error(oss.str());
    }

    int calculateSum(const std::vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            if (num <= 1000) {
                sum += num;
            }
        }
        return sum;
    }


