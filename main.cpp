//
// Created by gosia on 16/12/2025.
//

#include <iostream>
#include "DNASequence.h"
#include "kmer.h"
#include "RNASequence.h"
#include "Population.h"
#include "kolejne_populacje.h"
using namespace std;

int main() {
    // dna
    DNASequence dna1("ATCGATACGTACGCAACT");
    DNASequence dna2("ATGGATGACTGACTTACG");
    DNASequence dna("GDATCGATACGTACGCAACB");  //celowa pomylka w sekwencji

    cout << "DNA1 - dlugosc: " << dna1.length() << endl;
    cout << "DNA2 - dlugosc: " << dna2.length() << endl;

    cout << "DNA1 policzone nukleotydy: " << dna1.Count_nucleotides() << endl;
    cout << "DNA2 policzone nukleotydy: " << dna2.Count_nucleotides() << endl;

    cout << "Dystans hamminga miedzy dna1,dna2 "
              << dna1.hamming_distance(dna2) << endl;
    cout << "DNA1 komplementarne: " << dna1.Count_nucleotides() << endl;


    //rna

    RNASequence rna("AUCGAUACGUACGCAACU");
    cout << "RNA1 - dlugosc: " << rna.length() << endl;
    cout<< "RNA1 - policzone nukleotydy" << rna.Count_nucleotides() << endl;
    cout << "Zamiana na bialko: " << rna.convert_to_protein() << endl;

    //populacja krolikow
    RabbitPopulationModel kroliki(2);

    //mendel
    MendelProbabilityCalculator mendel(4,3,2);

    //kmery
    Kmers kmery("TCAGTACGACTCGATCGATCGATCG",4);
}
