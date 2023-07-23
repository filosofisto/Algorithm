#ifndef SWARM_PARTICLE_ALGORITHM_H
#define SWARM_PARTICLE_ALGORITHM_H

#include <cstddef>
#include <vector>
#include <random>
#include <memory>
#include <iostream>
#include "Particle.h"

class SwarmParticleAlgorithm
{
public:
    SwarmParticleAlgorithm(size_t number_of_particles, double min_xy, double max_xy, bool debug);
    ~SwarmParticleAlgorithm() = default;
    
    void run(size_t number_of_execution, std::ostream& out);
    void run(double precision, size_t max_iteractions, std::ostream& out);
    bool is_converged() const;
    size_t get_iteractions() const;
    std::unique_ptr<Particle> best();
private:
    
    void generate_swarm(std::ostream& out);
    
    size_t number_of_particles;
    double min_xy;
    double max_xy;
    std::vector<Particle> particles;
    bool debug;
    bool converged;
    size_t iteractions;
};

#endif
