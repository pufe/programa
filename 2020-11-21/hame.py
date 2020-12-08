n = int(input())
for i in range(n):
    a, b, *resto = input().split("me")
    print("k%s" % ("a"*(len(a)-1)*(len(b)-1)))
