#include "DNASequence.h"
#include <iostream>

DNASequence::DNASequence(const std::string& seq) : SequenceBase(seq) {
    validate_sequence();
}

void DNASequence::validate_sequence() {
    for (char c : strand) {
        if (c != 'A' && c != 'T' && c != 'C' && c != 'G') {
            std::cerr << "Invalid character '" << c << std::endl;
        }
    }
}

std::string DNASequence::Count_nucleotides() const {
    int countA = 0, countC = 0, countG = 0, countT = 0;
    for (char c : strand) {
        if (c == 'A') countA++;
        else if (c == 'C') countC++;
        else if (c == 'G') countG++;
        else if (c == 'T') countT++;
    }
    return "A:" + std::to_string(countA) +
           " T:" + std::to_string(countT) +
           " C:" + std::to_string(countC) +
           " G:" + std::to_string(countG);
}

int DNASequence::hamming_distance(const DNASequence& other) const {
    if (strand.length() != other.strand.length()) return -1;
    int dist = 0;
    for (size_t i = 0; i < strand.length(); i++) {
        if (strand[i] != other.strand[i]) dist++;
    }
    return dist;
}

std::string DNASequence::complementary() const {
    std::string complementary_strand;
    for (char c : strand) {
        if (c == 'A') complementary_strand += 'T';
        else if (c == 'C') complementary_strand += 'G';
        else if (c == 'G') complementary_strand += 'C';
        else if (c == 'T') complementary_strand += 'A';
    }
    return complementary_strand;
}
