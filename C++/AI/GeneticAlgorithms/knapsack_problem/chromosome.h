#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <iostream>
#include <bitset>
#include <type_traits>
#include "item.h"

template <size_t N>
class Chromosome
{
public:
    using TItems = std::array<Item, N>;
    
    Chromosome() = default;
    ~Chromosome() = default;
    
    void random_gene_creation()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, 1);
    
        for (size_t i = 0; i < data.size(); ++i) {
            data.set(i, dist(gen) == 1);
        }
    }
    
    float calculate_fitness(const TItems& items, int capacity) const
    {
        int total_weight{ 0 };
        float total_value{ 0 };
        
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i]) {
                total_weight += items[i].weight;
                total_value += items[i].value;
            }
            if (total_weight > capacity) {
                return 0;
            }
        }
        
        return total_value;
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
