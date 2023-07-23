#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include "RandomUtility.h"

class Particle
{
public:
    static constexpr double COGNITIVE_CONST = 0.35f; // TODO: what value??
    static constexpr double SOCIAL_CONST = 0.45f; // TODO: what value??
    static constexpr double INERTIA_CONST = 0.2f; // TODO: what value??
    
    Particle(double x, double y);
    ~Particle() = default;
    
    void calculate_fitness();
    void update(double swarm_best_x, double swarm_best_y);
    
    double get_fitness() const;
    double get_x() const;
    double get_y() const;
    double get_best_x() const;
    double get_best_y() const;
    
    friend std::ostream& operator<<(std::ostream& out, const Particle& obj);
    
private:
    
    double calculate_inertia() const;
    double calculate_cognitive_acceleration() const;
    double calculate_social_acceleration() const;
    double calculate_distance(double from_x, double from_y) const;
    
    double calculate_cognitive(double distance) const;
    double calculate_social(double distance) const;
    
    double x;
    double y;
    double fitness;
    double best_x;
    double best_y;
    double best_fitness;
    double velocity;
};

#endif
