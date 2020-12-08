inf = 1000
class Composer:
    def __init__(self, name):
        self.name = name
        self.distance = inf
        self.partners = []
    def __lt__(self, other):
        if self.distance != other.distance:
            return self.distance < other.distance
        else:
            return self.name < other.name
def bfs(x):
    x.distance = 0
    next_composers = [x]
    while len(next_composers) > 0:
        current_composers = next_composers
        next_composers = []
        for composer in current_composers:
            for partner in composer.partners:
                if partner.distance > composer.distance + 1:
                    partner.distance = composer.distance + 1
                    next_composers.append(partner)
def main():
    n = int(input())
    composers = dict()
    for i in range(n):
        a, c, b = input().split()
        if not composers.get(a):
            composers[a] = Composer(a)
        if not composers.get(b):
            composers[b] = Composer(b)
        composers[a].partners.append(composers[b])
        composers[b].partners.append(composers[a])
    bfs(composers["Saracura"])
    names = list(composers.values())
    names.sort()
    for name in names[1:]:
        if name.distance == inf:
            print("%s: infinito" % name.name)
        else:
            print("%s: %d" % (name.name, name.distance))

main()
