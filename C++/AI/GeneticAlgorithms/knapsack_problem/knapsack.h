#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <iostream>
#include <bitset>
#include <vector>
#include <array>
#include <unordered_map>
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
    using MapPopulation = std::unordered_map<std::string, Chromosome<N>>;
    using PopulationProbability = std::vector<float>;
    using TItems = std::array<Item, N>;

    KnapsackGA(size_t population_size, size_t capacity, size_t number_of_selections): 
        population_size{ population_size }, capacity{ capacity }, nextItemToInsertIndex{ 0 }, number_of_selections { number_of_selections } { }
    
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
    
    void show_probabilities_of_population(std::ostream& out)
    {
        for (int i = 0; i < population.size(); ++i) {
            out << population[i] 
                << ": probability[" << population_probability[i] 
                << "] value[" << items[i].value 
                << "] fitness[" << population[i].calculate_fitness(items, capacity) << "]\n";
        }
    }
    
    void run(size_t number_of_generation)
    {
        std::cout << "Searching for good solution using " << number_of_generation << " generations...\n" ;
        
        float current_best_fitness;
        best_global_fitness = 0;
        Population the_chosen, the_children;
        
        generate_initial_population();
        Population best_population;
        
        for (int i = 0; i < number_of_generation; ++i) {
            current_best_fitness = set_probabilities_of_population();
            
            if (current_best_fitness > best_global_fitness) {
                best_global_fitness = current_best_fitness;
                best_population = population;
            }
            
            std::cout << "Generation " << i << " - Fitness: " << current_best_fitness; 
            std::cout << " Best global fitness: " << best_global_fitness; 
            //show_probabilities_of_population(std::cout);
            
            the_chosen = roulette_wheel_selection();
            std::cout << " - Chosen qty: " << the_chosen.size();
            //std::cout << "The Chosen\n";
            //show_population(std::cout, the_chosen);
            
            the_children = reproduce_children(the_chosen);
            std::cout << " - Children qty: " << the_children.size();
            //std::cout << "The Children\n";
            //show_population(std::cout, the_children);
            
            mutate(the_children);
            //std::cout << "Children mutated\n";
            //show_population(std::cout, the_children);
            
            merge_populations(the_chosen, the_children);
            std::cout << " - New population size: " << population.size() << "\n";
        }
        
        population = best_population;
        std::cout << "Finished calculation" << std::endl;
    }
    
    void show_best_individual(std::ostream& out)
    {
        float max_fitness = 0;
        int pos_max = -1;
        int index = -1;
        
        for (auto& chromosome: population) {
            index++;
            float individual_fitness = chromosome.calculate_fitness(items, capacity);
            
            if (individual_fitness > max_fitness) {
                max_fitness = individual_fitness;
                pos_max = index;
            }
        }
        
        out << population[index] << " - fitness: " << max_fitness;
    }
    
    float get_best_global_fitness()
    {
        return best_global_fitness;
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
    
    Population reproduce_children(Population population) const
    {
        Population the_children;
        size_t i = 1;
        size_t xover_point = N/2;
        
        while (i < population.size()) {
            Chromosome<N> parent_a = population.at(i-1);
            Chromosome<N> parent_b = population.at(i);
            
            std::pair<Chromosome<N>, Chromosome<N>> children_pair = one_point_crossover(parent_a, parent_b, xover_point);
            
            the_children.push_back(children_pair.first);
            the_children.push_back(children_pair.second);
            
            //std::cout << "Added 2 children\n";
            
            i += 2;
        }
        
        return the_children;
    }
    
    void mutate(Population& the_population) const
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, N);
        
        for (auto& individual: the_population) {
            int index = dist(gen);
            individual.mutate(index);
        }
    }
    
    void merge_populations(Population population_a, Population population_b)
    {
        population.clear();
        
        for (auto individual: population_a) {
            population.push_back(individual);
        }
        for (auto individual: population_b) {
            population.push_back(individual);
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
            child_one.set(i, parent_a.get(i));
        }
        for (int i = xover_point; i < N; ++i) {
            child_one.set(i, parent_b.get(i));
        }
        // child_two
        for (int i = 0; i < xover_point; ++i) {
            child_two.set(i, parent_b.get(i));
        }
        for (int i = xover_point; i < N; ++i) {
            child_two.set(i, parent_a.get(i));
        }
        
        return std::make_pair(child_one, child_two);
    }
    
    float set_probabilities_of_population() 
    {
        //cout << "Set probabilities of population...";
        
        float total_fitness{ 0 };
        population_probability.clear();
        
        for (auto& chromosome: population) {
            float individual_fitness = chromosome.calculate_fitness(items, capacity);
            population_probability.push_back(individual_fitness);
            //std::cout << "individual_fitness: " << individual_fitness << "\n";
            total_fitness += individual_fitness;
        }
        //std::cout << "total_fitness: " << total_fitness << "\n";
        
        for (int i = 0; i < population_probability.size(); ++i) {
            //std::cout << "population_probability[" << i << "]: " << population_probability[i] << "/" << total_fitness << ": " << //(population_probability[i] / total_fitness) << "\n";
            population_probability[i] = population_probability[i] / total_fitness;
        }
        
        //cout << "ok" << endl;
        
        return total_fitness;
    }
    
    Population roulette_wheel_selection()
    {
        float total_fitness = set_probabilities_of_population();
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, total_fitness);
        
        MapPopulation selected_individuals;
        
        for (int i = 0; i < number_of_selections; ++i) {
            float random_number = dist(gen)/total_fitness;
            //std::cout << "random_number: " << random_number << "\n";
            float cumulative_fitness = 0;
            int j = 0;
            
            for (auto it = population_probability.begin(); it != population_probability.end(); ++j) {
                cumulative_fitness += *it;
                //std::cout << "Analizing " << population[j] << " - cumulative_fitness: " << cumulative_fitness 
                //        << " isZero: " << isZero(*it) << "\n";
                
                std::string individual_key = population[j].to_string();
                
                if (!isZero(*it) 
                    && selected_individuals.find(individual_key) == selected_individuals.end() 
                    && cumulative_fitness >= random_number) {
                    selected_individuals[individual_key] = population[j];
                    //std::cout << "Added\n";
                    break;
                } else {
                    ++it;
                }
            }
        }
        
        Population result;
        for (const auto& pair: selected_individuals) {
            result.push_back(pair.second);
        }
        
        return result;
    }
    
    void show_population(std::ostream& out, const Population& the_population)
    {
        for (const auto& chromosome: the_population) {
            out << chromosome << "\n";
        }
    }
    
    bool isZero(float value, float threshold = 1e-2)
    {
        return std::fabs(value) < threshold;
    }
    
    size_t population_size;
    size_t number_of_selections;
    size_t capacity;
    float best_global_fitness;
    Population population;
    TItems items;
    size_t nextItemToInsertIndex;
    PopulationProbability population_probability;
};

#endif
