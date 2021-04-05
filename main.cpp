#include "src/simulated_annealing.h"
#include <chrono> 

using namespace std;
using namespace chrono; 

int main(int argc, char const *argv[])
{
    if(argc != 3) return 0;
    int n = strtol(argv[2], NULL, 10);
    string file = "test_files/uf";
    file += argv[1];
    file += "-01.cnf"; 
    sat3 sat(file);

    // testar a melhor prob do random
    // testar o melhor comparador do sa
    // teste de convergência
    // comparar vários n do sa e rand (tempo e resultado)

    auto start = high_resolution_clock::now(); 


    cout << "Initial Fitness: " << cost(sat) << endl;
    sat3 random_sat = random_search(sat, n); 
    cout << "Random Search: " << cost(random_sat) << endl;
    sat3 sa_sat = simulated_annealing(sat, n); 
    cout << "Simulated Annealing: " << cost(sa_sat) << endl;


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Duration (ms): " << duration.count() << endl;


    return 0;
}
