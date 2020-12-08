import re

palavra = input().strip()
vogais = re.sub(r"[^aeiou]", "", palavra)
if vogais == vogais[::-1]:
    print("S")
else:
    print("N")

