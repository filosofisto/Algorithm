#include <random>
#include <limits>
#include <memory>
#include <cmath>
#include "SwarmParticleAlgorithm.h"
#include "RandomUtility.h"

using std::unique_ptr;
using std::isnan;

SwarmParticleAlgorithm::SwarmParticleAlgorithm(size_t number_of_particles, double min_xy, double max_xy, bool debug): 
    number_of_particles{number_of_particles}, min_xy{min_xy}, max_xy{max_xy}, debug{debug}, converged{false}, iteractions{0}
{ 
    
}

void SwarmParticleAlgorithm::run(size_t number_of_execution, std::ostream& out)
{
    generate_swarm(out);
    
    out << "\n";
    
    for (size_t i = 0; i < number_of_execution; ++i) {
        unique_ptr<Particle> the_current_best = best();
        
        for (auto& particle: particles) {
            particle.calculate_fitness();
            particle.update(the_current_best->get_x(), the_current_best->get_y());
            
            if (debug) out << "[" << i << "] - " << particle << "\n";
        }
        
        
        out << *the_current_best << "\n";
    }
}

void SwarmParticleAlgorithm::run(double precision, size_t max_iteractions, std::ostream& out)
{
    generate_swarm(out);
    
    out << "\n";
    
    double best_x = std::numeric_limits<double>::max();
    double best_y = std::numeric_limits<double>::max();
    
    iteractions = 0;
    
    for (;;) {
        iteractions++;
        
        if (iteractions >= max_iteractions) {
            converged = false;
            break;
        }
        
        unique_ptr<Particle> the_current_best = best();
        
        if (best_x - the_current_best->get_best_x() < precision
            && best_y - the_current_best->get_best_y() < precision) {
            converged = true;
            break;
        }
        
        if (isnan(the_current_best->get_x())
            || isnan(the_current_best->get_y())) {
            converged = false;
            break;
        }
        
        for (auto& particle: particles) {
            particle.calculate_fitness();
            particle.update(the_current_best->get_x(), the_current_best->get_y());
            
            if (debug) out << "[" << iteractions << "] - " << particle << "\n";
        }
        
        out << *the_current_best << "\n";
    }
}

size_t SwarmParticleAlgorithm::get_iteractions() const
{
    return iteractions;
}

bool SwarmParticleAlgorithm::is_converged() const
{
    return converged;
}

void SwarmParticleAlgorithm::generate_swarm(std::ostream& out)
{
    for (int i = 0; i < number_of_particles; ++i) {
        particles.push_back(Particle(
            RandomUtility::randomBetween(min_xy, max_xy), 
            RandomUtility::randomBetween(min_xy, max_xy)
        ));
    }
    
    out << "Initial Particles\n";
    
    for (auto& particle: particles) {
        out << particle << "\n";
    }
}

unique_ptr<Particle> SwarmParticleAlgorithm::best()
{
    if (particles.empty()) return nullptr;
    
    Particle* best_particle = &particles[0];
    best_particle->calculate_fitness();
    double best_fitness = best_particle->get_fitness();
    
    for (size_t i = 1; i < particles.size(); ++i) {
        particles[i].calculate_fitness();
        
        if (particles[i].get_fitness() < best_fitness) {
            best_fitness = particles[i].get_fitness();
            best_particle = &particles[i];
        }
    }
    
    return std::make_unique<Particle>(*best_particle);
}

