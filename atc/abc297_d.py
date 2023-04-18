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

a,b = map(int,input().split())

ans = 0
while a != b:
    if a > b:
        ans += ((a - b) + (b - 1)) // b
        a = a - ((a - 1) // b * b)
    elif a < b:
        ans += ((b - a) + (a - 1)) // a
        b = b - ((b - 1) // a * a)
    # print(a,b )

print(ans)