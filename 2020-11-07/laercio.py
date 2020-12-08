n = int(input())

for teste in range(n):
    m = int(input())
    lista = [int(x) for x in input().split()]
    impares = []
    for x in lista:
        if x%2 == 1:
            impares.append(x)
    impares.sort()
    laercio = []
    while len(impares) > 0:
        laercio.append(impares.pop())
        impares.reverse()
    print(*laercio)
