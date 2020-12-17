def Qkk(Q):
    return min(Q), -sum(Q)

def getCSV():
    source = []
    target = []
    weight = []
    with open("Plant_transfer_rate.csv") as csv:
        for l in csv.readlines()[1:]:
            l = l.split(',')
            source.append(l[0])
            target.append(l[1])
            weight.append(float(l[2].rstrip()))
    return source, target, weight


def probabilidad_603_604():
    auto = []
    Qkj = 0
    S,T,W = getCSV()
    for s,t,w in zip(S,T,W):
        if s=='b_603':
            auto.append(w)
            if t == 'b_604':
                Qkj = w
    return -Qkj/Qkk(auto)[1]


print(probabilidad_603_604())

