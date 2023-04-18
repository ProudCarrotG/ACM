def fileext():
    try:
        open("atc/.in","r")
    except:
        return 0
    else:
        return 1

if fileext():
    f = open("atc/.in",'r')
    def input():
        return f.readline()
# from sys import exit

s = input()

def f(x):
    return [i for i in range(len(s)) if s[i] == x]

B, R, K = f('B'), f('R'), f('K')
if B[0] % 2 != B[1] % 2 and R[0] < K[0] < R[1]:
    print("Yes")
    exit()

print('No')