//
// Created by gosia on 16/12/2025.
//
#pragma once

// Plik: SequenceBase.h

#include <string>
#include <iostream>
#include <map>
// klasa fundament dla innych klas. klasa abstrakcyjna. uzywana tylko do klas pochodnych. nie moge jej
//samej zimplementowac
class SequenceBase {
protected: // klasy dziedziczace beda mialy dostep do zmiennej strand
    std::string strand; // ale z zewnatrz nie bedzie do niej dostepu
    virtual void validate_sequence() = 0;
public:
    SequenceBase(const std::string& seq) : strand(seq) { //konstruktur ustawiajacy nasza nic
        for (int i = 0; i < strand.length(); ++i) {
            strand[i] = toupper(strand[i]);
        } // od razu zamiana na wielkie litery - piszemy sekwencje duzymi literami
    }

    virtual ~SequenceBase() = default;  //destruktor, ktory usunie i wartosci z klasy pochodnej, jak
    //i bazowej

    virtual std::string Count_nucleotides() const = 0;  //rowniez wirtualna metoda nie zaimplementowana
    // poniewaz w RNA mamy U a w DNA T.

    virtual int length() {
        return strand.length();
    } // tutaj jest uniwersalnie - wiec juz jest zaimplementowana.

    virtual void print() { // do wyswietlania - tez uniwersalnie
        std::cout << "Sequence: " << strand << std::endl;
    }


};
