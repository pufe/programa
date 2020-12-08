tests = int(input())

for t in range(tests):
    m, n = [ int(x) for x in input().split() ]
    d = dict()
    for i in range(m):
        japones = input().strip()
        portugues = input().strip()
        d[japones] = portugues
    for i in range(n):
        letra = input().strip().split()
        saida = []
        for palavra in letra:
            if d.get(palavra):
                saida.append(d[palavra])
            else:
                saida.append(palavra)
        print(" ".join(saida))
    print()
