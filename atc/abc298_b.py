def fileext():
    try:
        open('atc/.in','r')
    except:
        return 0
    else:
        return 1
if fileext():
    print("文件输入")
    f = open('atc/.in','r')
    def input():
        return f.readline().strip()

n = int(input())

A = list(list(map(int,input().split())) for _ in range(n))
B = list(list(map(int,input().split())) for _ in range(n))

ans = 0
for _ in range(4):
    res = 1
    for i in range(n):
        for j in range(n):
            if B[i][j] == 0 and A[i][j] == 1:
                res = 0
    
    if res == 1:
        ans = 1
    
    A = [[A[n-1-j][i] for j in range(n)] for i in range(n)]
   
print("Yes") if ans == 1 else print("No")