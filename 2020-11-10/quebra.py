all_str = []

def generate(prefix, digits, signs, needs_digit):
    global all_str
    if digits == 9:
        all_str.append(prefix)
        return
    remaining_digits = 9 - digits
    remaining_signs = 3 - signs
    if remaining_digits > remaining_signs:
        generate(prefix + str(digits+1), digits+1, signs, False)
    if not needs_digit and remaining_signs > 0:
        generate(prefix + '-', digits, signs+1, True)
        generate(prefix + '+', digits, signs+1, True)

generate("", 0, 0, True)
print(len(all_str))
all_str.sort()
solutions = dict()
for expr in all_str:
    solutions[eval(expr)] = expr
print(len(solutions))
n = int(input())
for i in range(n):
    x = int(input())
    print("%s = %d" % (solutions.get(x), x))
