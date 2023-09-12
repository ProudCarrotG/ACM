for n in range(101):
    ans = 1
    for i in range(1, n+1):
        for j in range(1, i+1):
            if (j % 2 == i % 2):
                ans *= j
    # print("n=", n, " ans=", ans)
    tot = 0
    while (ans):
        if (ans % 10) == 0:
            tot += 1
        else:
            break
        ans = ans // 10
        # print(ans)
    print("n=", n, "ans=", tot)
