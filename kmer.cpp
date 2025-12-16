//
// Created by gosia on 16/12/2025.
//


//
// Created by gosia on 16/12/2025.
//

#include "kmer.h"
#include <iostream>

using namespace std;

Kmers::Kmers(const std::string &seq, int k_val)
    :
      sekwencja(seq),
      k(k_val) {}

void Kmers::znajdzkmery() {
    for (size_t i = 0; i <= sekwencja.length() - (k + 1); i++) {
        string from = sekwencja.substr(i, k);
        string to   = sekwencja.substr(i + 1, k);
        kmery[from].push_back(to);
    }
}

void Kmers::wyswietlkmery() const {
    for (const auto &p : kmery) {
        for (const auto &v : p.second) {
            cout << "(" << p.first << ", " << v << ")" << endl;
        }
    }
}


const map<string, vector<string>>& Kmers::pobierzKmery() const {
    return kmery;
}

