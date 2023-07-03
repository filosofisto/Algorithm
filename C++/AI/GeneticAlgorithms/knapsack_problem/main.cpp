#include <iostream>
#include <bitset>
#include <iomanip>
//#include <locale>
#include "knapsack.h"

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
//using std::locale;


int main() {
    cout << fixed << setprecision(2);
    //cout.imbue(locale("en_US.UTF-8"));
    
    cout << "---------------------------------------------------------\n";
    cout << "Knapsack Problem\n";
    cout << "---------------------------------------------------------\n";
    
    KnapsackGA<26> knapsackGA{ 20, 6404180, 10 };
    knapsackGA.addItem("Axe",               32252,  68674);
    knapsackGA.addItem("Bronze coin",       225790, 47101);
    knapsackGA.addItem("Crown",             468164, 94462);
    knapsackGA.addItem("Diamond statue",    489494, 962094);
    knapsackGA.addItem("Emerald belt",      35384,  78344);
    knapsackGA.addItem("Fossil",            265590, 579152);
    knapsackGA.addItem("Gold coin",         497911, 902698);
    knapsackGA.addItem("Helmet",            800493, 1686515);
    knapsackGA.addItem("Ink",               823576, 1688691);
    knapsackGA.addItem("Jewel box",         552202, 1056157);
    knapsackGA.addItem("Knife",             552202, 1056157);
    knapsackGA.addItem("Long sword",        382846, 833132);
    knapsackGA.addItem("Mask",              44676,  99192);
    knapsackGA.addItem("Necklace",          169738, 376418);
    knapsackGA.addItem("Opal badge",        610876, 1253986);
    knapsackGA.addItem("Pearls",            854190, 1853562);
    knapsackGA.addItem("Quiver",            671123, 1320297);
    knapsackGA.addItem("Ruby ring",         698180, 1301637);
    knapsackGA.addItem("Silver bracelet",   446517, 859835);
    knapsackGA.addItem("Timepiece",         909620, 1677534);
    knapsackGA.addItem("Uniform",           904818, 1910501);
    knapsackGA.addItem("Venom potion",      730061, 1528646);
    knapsackGA.addItem("Wool scarf",        931932, 1827477);
    knapsackGA.addItem("Crossbow",          952360, 2068204);
    knapsackGA.addItem("Yesteryear book",   926023, 1746556);
    knapsackGA.addItem("Zinc cup",          978724, 2100851);
    
    cout << "Initial Population\n";
    
    knapsackGA.run(100000);
    cout << "Solution\n";
    knapsackGA.show_best_individual(cout);
    cout << endl;

    return EXIT_SUCCESS;
}
