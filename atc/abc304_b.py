n = int(input())

if n < 1e3:
    print(n//1)
elif 1e3 <= n < 1e4:
    print(n//10*10)
elif 1e4 <= n < 1e5:
    print(n//100*100)
elif n < 1e6:
    print(n//1000*1000)
elif n < 1e7:
    print(n//10000 * 10000)
elif n < 1e8:
    print(n//100000* 100000)
elif n < 1e9:
    print(n//1000000*1000000)
