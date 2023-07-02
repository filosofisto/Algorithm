#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <iostream>
#include <bitset>
#include <vector>
#include <array>
#include <string>
#include <random>
#include <algorithm>
#include <utility>
#include "chromosome.h"
#include "item.h"

template <size_t N>
class KnapsackGA
{
public:
    using Population = std::vector<Chromosome<N>>;
    using PopulationProbability = std::vector<float>;
    using TItems = std::array<Item, N>;
    
    KnapsackGA(size_t population_size, unsigned int capacity): 
        population_size{ population_size }, capacity{ capacity }, nextItemToInsertIndex{ 0 } 
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
    
    void addItem(const std::string& name, unsigned int weight, float value)
    {
        Item item { weight, value, name };
        items[nextItemToInsertIndex++] = item;
    }
    
    float set_probabilities_of_population() 
    {
        float total_fitness = 0;
        population_probability.clear();
        
        for (const auto& chromosome: population) {
            float individual_fitness = chromosome.calculate_fitness(items, capacity);
            population_probability.push_back(individual_fitness);
            total_fitness += individual_fitness;
        }
        for (int i = 0; i < population_probability.size(); ++i) {
            population_probability[i] = population_probability[i] / total_fitness;
        }
        
        return total_fitness;
    }
    
    void show_probabilities_of_population(std::ostream& out)
    {
        for (int i = 0; i < population.size(); ++i) {
            out << population[i] << ": " << population_probability[i] << "\n";
        }
    }
    
    void roulette_wheel_selection(int number_of_selections)
    {
        float total_fitness = set_probabilities_of_population();
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, total_fitness-1);
        
        Population selected_individuals;
        
        for (int i = 0; i < number_of_selections; ++i) {
            float random_number = dist(gen)/total_fitness;
            float cumulative_fitness = 0;
            
            //std::cout << "random_number: " << random_number << "\n";
            
            int j = 0;
            bool found = false;
            
            for (auto it = population_probability.begin(); it != population_probability.end(); ++j) {
                cumulative_fitness += *it;
                //std::cout << "cumulative_fitness: " << cumulative_fitness << "\n";
                    
                if (random_number < cumulative_fitness) {
                    //std::cout << "Selected [" << j << "] - " << population[j] << "\n";
                    selected_individuals.push_back(population[j]);
                    it = population_probability.erase(it);
                    found = true;
                    break;
                } else {
                    ++it;
                }
            }
            
            if (!found) {
                // no one item found under the probability, so get the biggest
                auto max = std::max_element(population_probability.begin(), population_probability.end());
                if (max != population_probability.end()) {
                    selected_individuals.push_back(population[std::distance(population_probability.begin(), max)]);
                    population_probability.erase(max);
                }
            }
        }
        
        population.clear();
        for (const auto& chromosome: selected_individuals) {
            population.push_back(chromosome);
        }
    }
    
    std::pair<Chromosome<N>, Chromosome<N>> one_point_crossover(
        const Chromosome<N>& parent_a, 
        const Chromosome<N>& parent_b, 
        size_t xover_point) const
    {
        Chromosome<N> child_one;
        Chromosome<N> child_two;
        
        // child_one
        for (int i = 0; i < xover_point; ++i) {
            child_one[i] = parent_a[i];
        }
        for (int i = xover_point; i < parent_b.size(); ++i) {
            child_one[i] = parent_b[i];
        }
        // child_two
        for (int i = 0; i < xover_point; ++i) {
            child_two[i] = parent_b[i];
        }
        for (int i = xover_point; i < parent_b.size(); ++i) {
            child_two[i] = parent_a[i];
        }
        
        return std::make_pair(child_one, child_two);
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
    unsigned int capacity;
    Population population;
    TItems items;
    size_t nextItemToInsertIndex;
    PopulationProbability population_probability;
};

#endif
