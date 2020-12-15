def perm(li):
    if (len(li)==0):
        return [[]]
    res = []
    for i in range(len(li)):
        nli = li[0:i]+li[i+1:]
        for p in perm(nli):
            res.append([li[i]] + p)
    return res
