def fileext():
    try:
        open('atc/.in','r')
    except:
        return 0
    else:
        return 1
if fileext():
    f = open('atc/.in','r')
    def input():
        return f.readline().strip()


n = input()
q = int(input())

box = {}
car = {}

for _ in range(q):
    L = list(map(int,input().split()))

    if L[0] == 1:
        i = L[1]
        j = L[2]
        if j not in box.keys():
            box[j] = []
        box[j].append(i)

        if i not in car.keys():
            car[i] = set()
        car[i].add(j)

    if L[0] == 2:
        print(*sorted(box[L[1]]))
    
    if L[0] == 3:
        print(*sorted(car[L[1]]))