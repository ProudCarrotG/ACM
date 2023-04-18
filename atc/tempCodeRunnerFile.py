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

n, k = map(int, input().split())
a = sorted(list(map(int,input().split())))

st = set()
for i in a:st.add(i)

for i in range(k-1):
    for j in a:
        st.add(sorted(list(st))[0]+j)
    st.remove(sorted(list(st))[0])
    # print(sorted(list(st)))

print(sorted(list(st))[0])