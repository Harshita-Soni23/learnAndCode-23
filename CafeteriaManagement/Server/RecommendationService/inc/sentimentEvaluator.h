#pragma once 

#include <unordered_set>
#include <vector>
#include <string>
#include "utility.h"
#include "menuItem.h"
#include "feedback.h"

class SentimentEvaluator {
public:
    SentimentEvaluator();

    double evaluateFoodItemSentiment(const std::vector<Feedback>& feedbacks, double& rating, std::string& sentimentsString);

private:
    std::unordered_set<std::string> positiveWords_;
    std::unordered_set<std::string> negativeWords_;
    std::unordered_set<std::string> negationWords_;

    double analyzeSentiment(const std::string& comment, std::vector<std::string>& foundSentiments);
    std::string getMostRepetitiveSentiments(const std::vector<std::string>& words);
};

