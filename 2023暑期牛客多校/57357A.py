def str_2_bin(str):
    res = 0
    tmp = 0
    str = str[::-1]
    for i in range(len(str)):
        if str[i] == '1':
            res += 2**tmp
        tmp += 1
    return res


x = str_2_bin(input())
y = str_2_bin(input())

# print(x,y)

if x == y:
    print(0)
elif x == 0:
    print(-1)
else:
    print(abs(x-y))
