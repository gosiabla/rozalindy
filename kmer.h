#pragma once
//
// Created by gosia on 16/12/2025.
//



#include <string>
#include <vector>
#include <map>

class Kmers{
private:
    std::string sekwencja;
    int k;
    std::map<std::string, std::vector<std::string>> kmery;

public:

    Kmers(const std::string &seq, int k_val);

    void znajdzkmery();

    void wyswietlkmery() const;

    const std::map<std::string, std::vector<std::string>>& pobierzKmery() const;
};
