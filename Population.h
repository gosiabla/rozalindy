#pragma once

class MendelProbabilityCalculator {
private:
    int k; // liczba AA
    int m; // liczba Aa
    int n; // liczba aa

public:
    MendelProbabilityCalculator(int k_, int m_, int n_);
    float calculate_probability();
};