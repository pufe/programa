try:
    while True:
        cipo = input().split("x")
        maior = max(len(cipo[0]), len(cipo[-1]))
        for segmento in cipo:
            if len(segmento) // 2 > maior:
                maior = len(segmento) // 2
        print(maior)
except EOFError:
    pass
