mydict = {}
for i in range(1, 101):
    mydict[i]=None

start = int(input())
while True:
    rawinput = input()
    if rawinput == '-1':
        break
    route = list(map(int, rawinput.split()))
    for entry in route[1:]:
        mydict[entry] = route[0]

finalroute = [start]

while mydict[start] != None:
    move = mydict[start]
    finalroute.append(move)
    start=move
print(*finalroute)
