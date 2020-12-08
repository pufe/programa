class Task:
    def __init__(self):
        self.chegada = 0
        self.duracao = 0
        self.inicio = 0
    def __lt__(self, other):
        return self.chegada < other.chegada

def main():
    n = int(input())
    tasks = []
    for i in range(n):
        task = Task()
        c, d = [int(x) for x in input().split()]
        task.chegada = c
        task.duracao = d
        tasks.append(task)
    tasks.sort()
    current_time = 0
    for task in tasks:
        if task.chegada > current_time:
            task.inicio = task.chegada
            current_time = task.inicio + task.duracao
        else:
            task.inicio = current_time
            current_time += task.duracao
    tme = 0
    tmt = 0
    for task in tasks:
        tme += task.inicio - task.chegada
        tmt += task.inicio + task.duracao - task.chegada
    tme /= n
    tmt /= n
    print("TME:%.1f" % tme)
    print("TMT:%.1f" % tmt)

main()
