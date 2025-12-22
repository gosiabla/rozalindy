//
// Created by gosia on 16/12/2025.
//
#pragma once

// Plik: SequenceBase.h

#include <string>
#include <iostream>
#include <map>
// klasa fundament dla innych klas. klasa abstrakcyjna. uzywana tylko do klas pochodnych. nie moge jej

class SequenceBase {
protected: 
    std::string strand; 
    virtual void validate_sequence() = 0;
public:
    SequenceBase(const std::string& seq) : strand(seq) {
        for (int i = 0; i < strand.length(); ++i) {
            strand[i] = toupper(strand[i]);
        } 
    }

    virtual ~SequenceBase() = default; 

    virtual std::string Count_nucleotides() const = 0; 

    virtual int length() {
        return strand.length();
    } 
    virtual void print() { 
        std::cout << "Sequence: " << strand << std::endl;
    }


};
