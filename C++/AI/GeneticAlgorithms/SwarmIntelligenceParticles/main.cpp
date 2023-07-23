#include <iostream>
#include "SwarmParticleAlgorithm.h"

using std::cout;
using std::endl;
using std::fixed;

int main() {
    cout << "---------------------------------------------------------\n";
    cout << "Swarm Particle Algorithm\n";
    cout << "---------------------------------------------------------\n";
    
    SwarmParticleAlgorithm alg{5000, -10, 10, false};
    alg.run(1000, cout);
    /*bool converged = false;
    
    while (!converged) {
        alg.run(0.01, 1000, cout);
        converged = alg.is_converged();
        
        cout << "Converged:     " << alg.is_converged() << "\n"
            << "Iteractions:   " << alg.get_iteractions() << "\n"
            << "Best Particle: " << *alg.best() 
            << endl;
    }*/

    return EXIT_SUCCESS;
}
