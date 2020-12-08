convidados = []

try:
    while True:
        nomes = input().split()
        abreviado = []
        if len(nomes) < 3:
            convidados.append(" ".join(nomes))
        else:
            abreviado.append(nomes[0])
            for nome in nomes[1:-1]:
                abreviado.append(nome[0] + ".")
            abreviado.append(nomes[-1])
            convidados.append(" ".join(abreviado))
except EOFError:
    pass

convidados.sort()

for convidado in convidados:
    print(convidado)
