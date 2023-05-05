q = int(input())

s = "1"
ans = 1
first = 0
len = 0
p = 1

for _ in range(q):
    l = list(input().split())
    op = int(l[0])
    if op == 1:
        x = l[1]
        s += x
        ans = ans * 10 + int(x)
        p *= 10
    if op == 2:
        ans = ans - int(s[first]) * p
        first += 1
        p = p // 10

    if op == 3:
        print(ans % 998244353)

    # print(s, ans)
