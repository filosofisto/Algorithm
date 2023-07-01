#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <iostream>
#include <bitset>
#include <type_traits>
#include "random_utility.h"

template <size_t N>
class Chromosome
{
public:
    Chromosome() = default;
    ~Chromosome() = default;
    
    void random_gene_creation()
    {
        for (size_t i = 0; i < data.size(); ++i) {
            data.set(i, zeroOrOne() == 1);
        }
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Chromosome<N>& obj)
    {
        out << obj.data;
        
        return out;
    }
private:
    std::bitset<N> data;
};

#endif
