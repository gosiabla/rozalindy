//
// Created by gosia on 16/12/2025.
//

#include "Population.h"

#include <iostream>


MendelProbabilityCalculator::MendelProbabilityCalculator(int k_, int m_, int n_)
        : k(k_), m(m_), n(n_) {}

float calculate_probability(int k,int m,int n)  {
    int total = k + m + n;
    float prob = 0.0;

        //total * total-1 - wszystkie mozliwe pary

        // AA x AA
    prob += (float)(k * (k - 1)) / (total * (total - 1)) * 1.0;
        // AA x Aa
    prob += (float)(k * m * 2) / (total * (total - 1)) * 1.0;
        // AA x aa
    prob += (float)(k * n * 2) / (total * (total - 1)) * 1.0;
        // Aa x Aa
    prob += (float)(m * (m - 1)) / (total * (total - 1)) * 0.75;
        // Aa x aa
    prob += (float)(m * n * 2) / (total * (total - 1)) * 0.5;
        // aa x aa
    prob += 0;
    return prob;
    }


