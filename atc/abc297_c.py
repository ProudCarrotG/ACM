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



def sol():
    s = input().replace('TT','PC')
    print(s)

tt,x = map(int, input().split())
while tt:
    sol()
    tt-=1