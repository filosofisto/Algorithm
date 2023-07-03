#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <iostream>
#include <bitset>
#include <type_traits>
#include <string>
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
    
    float calculate_fitness(const TItems& items, int capacity)
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
        
        fitness = total_value;
        return total_value;
    }
    
    void mutate(int index)
    {
        data[index] = !data[index];
    }
    
    void flip_mutate()
    {
        data.flip();
    }
    
    float get_fitness() const
    {
        return fitness;
    }
    
    bool get(size_t index) const
    {
        return data[index];
    }
    
    void set(size_t index)
    {
        data.set(index);
    }
    
    void set(size_t index, bool value)
    {
        data.set(index, value);
    }
    
    void reset(size_t index)
    {
        data.reset(index);
    }
    
    std::string to_string() const
    {
        return data.to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Chromosome<N>& obj)
    {
        out << obj.data;
        
        return out;
    }
    
private:
    std::bitset<N> data;
    float fitness;
};

#endif
