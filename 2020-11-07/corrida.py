v, n = [int(x) for x in input().split()]
total = v*n
for i in range(1, 10):
    if i>=2:
        print(" ", end="")
    print((total*i+9)// 10, end="")
print()
