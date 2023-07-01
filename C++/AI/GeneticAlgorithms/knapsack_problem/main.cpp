#include <iostream>
#include <bitset>
#include "knapsack.h"

using std::cout;
using std::endl;


int main() {
    cout << "---------------------------------------------------------\n";
    cout << "Knapsack Problem\n";
    cout << "---------------------------------------------------------\n";
    
    KnapsackGA<23> knapsackGA{10};
    knapsackGA.show_population(cout);

    return EXIT_SUCCESS;
}
