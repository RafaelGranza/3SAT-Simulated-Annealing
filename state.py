import random

class State:
    
    def __init__(self, cnf):
        self.variables = dict()
        self.statements = []
        for stt in cnf:
            self.statements.append(stt)
            for var in stt:
                if var[0] not in self.variables:
                    self.variables[var[0]] = round(random.uniform(0, 1))
