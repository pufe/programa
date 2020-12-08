try:
    while True:
        palavras = input().split()
        numeros = []
        for palavra in palavras:
            numeros.append(float(palavra))
        numeros.sort()
        print("%.1f" % sum(numeros[1:4]))
except EOFError:
    pass
