import random
import math
import copy 
from state import State


def simulated_annealing(initial_state):
    """Peforms simulated annealing to find a solution"""
    initial_temp = 10
    final_temp = .1
    loops = 100

    current_temp = initial_temp

    current_state = initial_state
    solution = current_state

    while current_temp > final_temp:
        for i in range(loops):
            neighbor = get_random_neighbor(current_state, current_temp)
            cost_diff = get_cost(current_state) - get_cost(neighbor)
            if cost_diff > 0:
                solution = neighbor
            else:
                if random.uniform(0, 1) < get_prob(cost_diff, current_temp):
                    solution = neighbor
            current_state = solution

        current_temp = get_new_temperature(current_temp)
        print(get_cost(solution), current_temp)

    return solution

def get_prob(cost, temp):
    """Generate probability"""
    return math.exp(-cost/temp)

def get_new_temperature(temp):
    """Decrement the temperature"""
    return temp - 0.01

def get_cost(state):
    """Calculates cost of the argument state for your solution."""
    points = len(state.statements)

    for stt in state.statements:
        v = True
        for var in stt:
            if var[1]:
                v &= state.variables[var[0]]
            else:
                v &= not state.variables[var[0]]
        points -= v
    return points

def get_random_neighbor(state_a, temp):
    """Returns neighbors of the argument state for your solution."""
    flag = False
    state = copy.deepcopy(state_a)
    
    for key, v in state.variables.items():
        if random.uniform(0, 1) < temp/100:
            state.variables[key] = not v
            flag = True
    
    if not flag:
        id = round(random.uniform(1, len(state.variables)))
        state.variables[id] =  not state.variables[id]

    return state
    
