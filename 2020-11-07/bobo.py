n = int(input())
votos = []

for i in range(n):
    x = int(input())
    votos.append(x)

if votos[0] >= max(votos):
    print("S")
else:
    print("N")
