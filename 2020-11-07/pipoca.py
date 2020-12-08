n, c, t = [int(x) for x in input().split()]
sacos = [int(x) for x in input().split()]

def possivel(x):
    total = x*t
    competidor = 0
    pessoas = 1
    for i in range(n):
        if sacos[i] > total:
            return False
        elif competidor+sacos[i] > total:
            pessoas += 1
            competidor = sacos[i]
        else:
            competidor += sacos[i]
    return pessoas <= c

def busca(inf, sup):
    if inf >= sup-1:
        return sup
    mid = (inf+sup) // 2
    if possivel(mid):
        return busca(inf, mid)
    else:
        return busca(mid, sup)

print(busca(0, 1000000000))
