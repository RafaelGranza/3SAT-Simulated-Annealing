from  simulated_annealing import simulated_annealing
from  simulated_annealing import get_cost
from cnf import get_state


stt = get_state()
# print(stt.variables)
# print(len(stt.statements),  sep="\n")
final = simulated_annealing(stt)
# print(final.variables, sep="\n")
print(get_cost(final))
# print(*final.statements, sep="\n")