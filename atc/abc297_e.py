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

import heapq

n, k = map(int, input().split())
a = list(map(int,input().split()))
q = [0]
st = set()

for i in range(k):
    x = heapq.heappop(q)
    for j in a:
        y = x + j
        if y not in st:
            st.add(y)
            heapq.heappush(q, y)

print(heapq.heappop(q))