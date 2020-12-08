n = int(input())

for i in range(n):
    frase = input()
    letras = dict()
    for c in frase:
        if c >= 'a' and c <= 'z':
            letras[c] = True
    if len(letras) == 26:
        print("frase completa")
    elif len(letras) >= 13:
        print("frase quase completa")
    else:
        print("frase mal elaborada")
