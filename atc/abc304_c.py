n,d = map(int,input().split())

person = []

for i in range(n):
    person.append(list(map(int,input().split())))
    person[i].append(0)

# print(person)

queue = []

def gd(a,b):
    return ((a[0]-b[0])**2 + (a[1]-b[1])**2)**0.5


queue.append(person[0])
person[0][2] = 1

while(len(queue)):
    now = queue[0]
    queue.pop(0)

    for i in range(n):
        if person[i][2] == 0:
            if gd(now,person[i]) <= d:
                queue.append(person[i])
                person[i][2] = 1

for i in range(n):
    if person[i][2] == 1:
        print("Yes")
    else:
        print("No")