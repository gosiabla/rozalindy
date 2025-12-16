#pragma once
#include "Sequencebase.h"
#include <string>

class DNASequence : public SequenceBase {
public:
    DNASequence(const std::string& seq);

    std::string Count_nucleotides() const override;
    int hamming_distance(const DNASequence& other) const;
    std::string complementary() const;

private:
    void validate_sequence() override;
};
