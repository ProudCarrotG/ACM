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

n, k = map(int, input().split())
a = sorted(list(map(int,input().split())))

print(n,k)
print(a)