n = int(input())
casa = 0
escritorio = 0
c_c = 0
c_e = 0

for i in range(n):
    dia, noite = input().split()
    if dia == "chuva":
        if casa == 0:
            c_c += 1
        else:
            casa-=1
        escritorio+=1
    if noite == "chuva":
        if escritorio == 0:
            c_e += 1
        else:
            escritorio-=1
        casa+=1

print(c_c, c_e)
