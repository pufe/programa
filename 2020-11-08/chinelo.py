class Chinelo:
    def __init__(self, modelo, pe):
        self.modelo = modelo
        self.pe = pe
        self.pra_troca = 0
    def __lt__(self, other):
        if self.modelo != other.modelo:
            return self.modelo < other.modelo
        else:
            return self.pe > other.pe
    def __eq__(self, other):
        return ( self.modelo == other.modelo and
                 self.pe == other.pe )
    def __hash__(self):
        return hash(str(self.modelo) + self.pe)

def main():
    n = int(input())
    colecao = dict()
    repetidos = []
    for i in range(n):
        e, d = [int(x) for x in input().split()]
        e = Chinelo(e, "E")
        d = Chinelo(d, "D")
        if not colecao.get(e):
            colecao[e] = 1
        else:
            colecao[e] += 1
        if not colecao.get(d):
            colecao[d] = 1
        else:
            colecao[d] += 1
    for chinelo, qt in colecao.items():
        if qt > 1:
            chinelo.pra_troca = qt-1
            repetidos.append(chinelo)
    repetidos.sort()
    if len(repetidos) == 0:
        print("SEM TROCAS DESTA VEZ")
    for chinelo in repetidos:
        print(chinelo.modelo, chinelo.pe, chinelo.pra_troca)
main()
