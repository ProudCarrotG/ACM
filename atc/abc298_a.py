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

n = map(int,input().split())
s = input()

if 'x' not in s and 'o' in s:
    print("Yes")
else:
    print("No")