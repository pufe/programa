palavras = input().split()
consertadas = []

def conserta(p):
    if len(p) < 4:
        return p
    if p[0] == p[2] and p[1] == p[3]:
        return p[2:]
    else:
        return p

for p in palavras:
    consertadas.append(conserta(p))

print(" ".join(consertadas))
