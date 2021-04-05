#include "tools.cpp"
#include <bits/stdc++.h>

using namespace std;

double cost(sat3& sat){
    unsigned long long points = 0;

    for (auto cls: sat.statement){
        bool v1 = sat.value[cls.first.id] == cls.first.signal;
        bool v2 = sat.value[cls.second.id] == cls.second.signal;
        bool v3 = sat.value[cls.third.id] == cls.third.signal;
        points += (v1 | v2 | v3);
    }
    return points;
}

double prob(double t, double t0){
    return t/t0;
}

bool cmp(sat3& s, sat3& z){
    if(f_rand(0, 1) < 0.95){
        return cost(s) > cost(z);
    }else true; 
}

sat3 new_sat(sat3 sat, int seed = 0){
    srand(seed);
    for(auto& [key, v] : sat.value){
        v = rand() % 2;
    }
    return sat;
}

sat3 random_neighbor(sat3 sat, double prob = 0.35){
    bool flag = false;
    
    for(auto [key, v] : sat.value){
        if(f_rand(0, 1) < prob){
            sat.value[key] = !v;
            flag = true;
        }
    }
    
    if(!flag){
        int id = round(f_rand(1, sat.value.size()));
        sat.value[id] = !sat.value[id];
    }

    return sat;
}

sat3 simulated_annealing(sat3& initial_sat, int lim = 100000){
    double initial_temp = 100;
    int loops = 20;
    int n = lim/loops;
    // std::vector<std::function<double(int, double, double, int)>> funcs;

    double current_temp = initial_temp;

    sat3 current_sat = initial_sat;
    sat3 solution = current_sat;

    for(int i = 1; i <= n; ++i){
        current_sat = solution;
        for (int j = 0; j < loops; ++j){
            sat3 neighbor = random_neighbor(current_sat, current_temp/initial_temp);
            int cost_diff =  cost(neighbor) - cost(current_sat);
            if (cost_diff > 0){
                current_sat = neighbor;
                if (cost(neighbor) > cost(solution))
                    solution = current_sat;
            }else{
                if (f_rand(0, initial_temp) < prob(current_temp, initial_temp))
                    current_sat = neighbor;
            }
        }
        current_temp = temp_0(i, initial_temp, 0, n);
    }
    return solution;
}

sat3 random_search(sat3& initial_sat, int lim = 100000, int seed = 0){
    int loops = lim;
    sat3 solution = initial_sat;
    for (int i = 0; i < loops; ++i){
        sat3 neighbor = new_sat(solution, seed);
        int cost_diff =  cost(neighbor) - cost(solution);
        if (cost_diff > 0)
                solution = neighbor;
    }
    return solution;
}
