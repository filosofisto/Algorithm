#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <iostream>
#include <bitset>
#include <vector>
#include "chromosome.h"

template <size_t N>
class KnapsackGA
{
public:
    using Population = std::vector<Chromosome<N>>;
    
    KnapsackGA(size_t population_size): population_size{ population_size } 
    {
        generate_initial_population();
    }
    ~KnapsackGA() = default;
    
    void show_population(std::ostream& out)
    {
        for (const auto& chromosome: population) {
            out << chromosome << "\n";
        }
    }
    
private:
    void generate_initial_population()
    {
        for (size_t i = 0; i < population_size; ++i) {
            Chromosome<N> chromosome;
            chromosome.random_gene_creation();
            population.push_back(chromosome);
        }
    }
    
    size_t population_size;
    Population population;
};

#endif
