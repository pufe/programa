import re

def is_word(symbol):
    return re.match(r"^[a-zA-Z]+\.?$", symbol)

try:
    while True:
        line = input().split()
        words = 0
        word_letters = 0
        for symbol in line:
            if is_word(symbol):
                words+=1
                if symbol[-1] == '.':
                    word_letters += len(symbol)-1
                else:
                    word_letters += len(symbol)
        if words == 0:
            print(250)
        elif word_letters // words <= 3:
            print(250)
        elif word_letters // words <= 5:
            print(500)
        else:
            print(1000)
except EOFError:
    pass
    
