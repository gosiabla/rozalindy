//
// Created by gosia on 16/12/2025.
//

#pragma once
#include "Sequencebase.h"
#include <string>
#include <map>

class RNASequence : public SequenceBase {
private:
    static const std::map<std::string, char> CODON_MAP;

    void validate_sequence() override;

public:
    RNASequence(const std::string& seq);

    std::string Count_nucleotides() const override;
    std::string convert_to_protein() const;
};
