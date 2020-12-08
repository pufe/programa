tabela = {
    "suco de laranja": 120,
    "morango fresco": 85,
    "mamao": 85,
    "goiaba vermelha": 70,
    "manga": 56,
    "laranja": 50,
    "brocolis": 34
}

while True:
    n = int(input())
    if n == 0:
        break
    total_c = 0
    for i in range(n):
        x, alimento = input().split(None, 1)
        total_c += int(x)*tabela[alimento]
    if total_c < 110:
        print("Mais %d mg" % (110-total_c))
    elif total_c > 130:
        print("Menos %d mg" % (total_c-130))
    else:
        print("%d mg" % total_c)
        
