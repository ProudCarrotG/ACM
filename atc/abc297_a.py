import sys


def openfile():
    try:
        open("atc/.in", 'r')
    except:
        return 0
    else:
        return 1


if openfile():
    f = open("atc/.in", "r")
    def input(): return f.readline()

n, d = map(int, input().split())
A = list(map(int, input().split()))

for i in range(1, len(A)):
    if A[i] - A[i-1] <= d:
        print(A[i])
        sys.exit()

print('-1')
