#include <limits>
#include <cmath>
#include <random>
#include <iostream>
#include "Particle.h"

using std::pow;
using std::sqrt;

Particle::Particle(double x, double y): 
    x{x}, y{y}, fitness{std::numeric_limits<double>::max()}, velocity{0}, best_x{x}, best_y{y}, 
    best_fitness{std::numeric_limits<double>::max()}
{ 

}
    
void Particle::calculate_fitness()
{
    fitness = pow(x+2 * y-7, 2) + pow(2*x + y-5, 2);
    
    if (fitness < best_fitness) {
        best_fitness = fitness;
        best_x = x;
        best_y = y;
    }
}

double Particle::get_x() const
{
    return x;
}

double Particle::get_y() const
{
    return y;
}
    
double Particle::get_best_x() const
{
    return best_x;
}

double Particle::get_best_y() const
{
    return best_y;
}

double Particle::get_fitness() const
{
    return fitness;
}

void Particle::update(double swarm_best_x, double swarm_best_y)
{
    auto distance_from_best = calculate_distance(best_x, best_y);
    auto inertia = calculate_inertia();
    auto cognitive = calculate_cognitive(distance_from_best);
    auto distance_from_best_swarm = calculate_distance(swarm_best_x, swarm_best_y);
    auto social = calculate_social(distance_from_best_swarm);
    
    velocity = inertia + cognitive + social;
    
    /*std::cout << "inertia:   " << inertia 
              << ", cognitive: " << cognitive
              << ", social: " << social
              << ", distance from best: " << distance_from_best
              << ", distance from best swarm particle: " << distance_from_best_swarm
              << ", velocity: " << velocity << "\n";*/
    
    x += velocity;
    y += velocity;
}

double Particle::calculate_inertia() const
{
    return Particle::INERTIA_CONST * velocity;
}

double Particle::calculate_cognitive_acceleration() const
{
    return Particle::COGNITIVE_CONST * RandomUtility::randomProbability();
}

double Particle::calculate_social_acceleration() const
{
    return Particle::SOCIAL_CONST * RandomUtility::randomProbability();
}

double Particle::calculate_distance(double from_x, double from_y) const
{
    return sqrt(pow(from_x - x, 2) + pow(from_y - y, 2));
}

double Particle::calculate_cognitive(double distance) const
{
    return calculate_cognitive_acceleration() * distance;
}

double Particle::calculate_social(double distance) const
{
    return calculate_social_acceleration() * distance;
}

std::ostream& operator<<(std::ostream& out, const Particle& obj)
{
    out << "(x=" << obj.x 
        << ", y=" << obj.y 
        << ", fitness=" << obj.fitness 
        << ", velocity=" << obj.velocity << ")";
    
    return out;
}
