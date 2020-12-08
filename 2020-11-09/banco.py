class Cliente:
    def __init__(self, nome, senha):
        self.nome = nome
        self.senha = senha
        self.bloqueado = False
        self.tentativas = 0
keys = dict()
clientes = dict()
for i in range(12):
    numero, *letras = input().split(";")
    for letra in letras:
        keys[letra] = numero
def converte(str):
    return [keys[c] for c in str]
while True:
    nome, senha = input().split(";")
    if nome == 'fim' and senha == 'fim':
        break
    clientes[nome] = Cliente(nome, converte(senha))
try:
    while True:
        nome, *senha = input().split(";")
        if not clientes.get(nome):
            print("%s: usuario inexistente" % nome)
        else:
            c = clientes[nome]
            if c.bloqueado:
                print("%s: usuario bloqueado" % nome)
            elif c.senha == senha:
                c.tentativas = 0
                print("%s: acesso concedido" % nome)
            else:
                c.tentativas += 1
                if c.tentativas >= 3:
                    c.bloqueado = True
                    print("%s: usuario bloqueado" % nome)
                else:
                    print("%s: acesso negado" % nome)
                
except EOFError:
    pass
