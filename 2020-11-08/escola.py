def find_modas(arr):
    idades = dict()
    for idade in arr:
        if not idades.get(idade):
            idades[idade] = 1
        else:
            idades[idade] += 1
    max_ocorrencias = max(idades.values())
    moda = []
    for idade, qt in idades.items():
        if qt == max_ocorrencias:
            moda.append(str(idade))
    return ",".join(moda)

def find_media(arr):
    return sum(arr) / len(arr)

def find_mediana(arr):
    arr.sort()
    meio_baixo = (len(arr)-1) // 2
    meio_cima = len(arr) // 2
    return (arr[meio_baixo]+arr[meio_cima])/2

try:
    while True:
        n = int(input())
        arr = []
        for i in range(n):
            arr.append(int(input()))
        print("MODA=%s" % find_modas(arr))
        print("MEDIA=%.2f" % find_media(arr))
        print("MEDIANA=%.2f" % find_mediana(arr))
except EOFError:
    pass
