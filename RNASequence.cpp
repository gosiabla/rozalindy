//
// Created by gosia on 16/12/2025.
//

#include "RNASequence.h"
#include <iostream>
#include <string>

using namespace std;

void RNASequence::validate_sequence() {
    for (char c : strand) {
        if (c != 'A' && c != 'U' && c != 'C' && c != 'G') {
            cerr << "Invalid character " << c << endl;
        }
    }
}

RNASequence::RNASequence(const std::string& seq) : SequenceBase(seq) {
    validate_sequence();
}

std::string RNASequence::Count_nucleotides() const {
    int countA = 0, countU = 0, countC = 0, countG = 0;

    for (char c : strand) {
        if (c == 'A') countA++;
        else if (c == 'U') countU++;
        else if (c == 'C') countC++;
        else if (c == 'G') countG++;
    }

    return "A:" + to_string(countA) +
           " U:" + to_string(countU) +
           " C:" + to_string(countC) +
           " G:" + to_string(countG);
}

std::string RNASequence::convert_to_protein() const {
    if (strand.length() % 3 != 0) {
        cerr << "Invalid length" << endl;
        return "";
    }

    std::string protein_sequence;
    for (size_t i = 0; i + 2 < strand.length(); i += 3) {
        std::string codon = strand.substr(i, 3);
        auto it = CODON_MAP.find(codon);
        if (it->second == '|') {
            break;
        }
        protein_sequence += it->second;
    }
    return protein_sequence;
}

const std::map<std::string, char> RNASequence::CODON_MAP = {
    {"UUU", 'F'}, {"UUC", 'F'},
    {"UUA", 'L'}, {"UUG", 'L'}, {"CUU", 'L'}, {"CUC", 'L'}, {"CUA", 'L'}, {"CUG", 'L'},
    {"AUU", 'I'}, {"AUC", 'I'}, {"AUA", 'I'},
    {"AUG", 'M'},
    {"GUU", 'V'}, {"GUC", 'V'}, {"GUA", 'V'}, {"GUG", 'V'},
    {"UCU", 'S'}, {"UCC", 'S'}, {"UCA", 'S'}, {"UCG", 'S'},
    {"CCU", 'P'}, {"CCC", 'P'}, {"CCA", 'P'}, {"CCG", 'P'},
    {"ACU", 'T'}, {"ACC", 'T'}, {"ACA", 'T'}, {"ACG", 'T'},
    {"GCU", 'A'}, {"GCC", 'A'}, {"GCA", 'A'}, {"GCG", 'A'},
    {"UAU", 'Y'}, {"UAC", 'Y'},
    {"CAU", 'H'}, {"CAC", 'H'},
    {"CAA", 'Q'}, {"CAG", 'Q'},
    {"AAU", 'N'}, {"AAC", 'N'},
    {"AAA", 'K'}, {"AAG", 'K'},
    {"GAU", 'D'}, {"GAC", 'D'},
    {"GAA", 'E'}, {"GAG", 'E'},
    {"UGU", 'C'}, {"UGC", 'C'},
    {"UGG", 'W'},
    {"CGU", 'R'}, {"CGC", 'R'}, {"CGA", 'R'}, {"CGG", 'R'},
    {"AGU", 'S'}, {"AGC", 'S'},
    {"AGA", 'R'}, {"AGG", 'R'},
    {"GGU", 'G'}, {"GGC", 'G'}, {"GGA", 'G'}, {"GGG", 'G'},
    {"UAA", '|'}, {"UAG", '|'}, {"UGA", '|'}
};
