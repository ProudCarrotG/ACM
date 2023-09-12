n = int(input())

list = []
min = 1e10
bj = -1
for i in range(n):
    list.append(input().split())
    if int(list[i][1]) < min:
        bj = i
        min = int(list[i][1])

for k in range(n):
    print(list[bj%n][0])
    bj+=1
