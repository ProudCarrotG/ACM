if a > b:
    ans += (a - b) + (b - 1) // b
    a = a - ((a - b) + (b - 1) // b) * b
elif a < b:
    ans += (b - a) + (a - 1) // a
    b = b - ((b - a) + (a - 1) // a) * a
# print(a,b)
