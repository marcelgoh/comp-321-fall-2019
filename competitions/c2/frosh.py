useless = list(map(int, input().split()))
tasks = list(map(int, input().split())) 
quiet = list(map(int, input().split())) 

tasks.sort(reverse=True)
quiet.sort(reverse=True)
i = 0
j = 0
count = 0
while(i < useless[0] and j < useless[1]):
    if tasks[i] <= quiet[j]:
        i += 1
        j += 1
        count += 1
    else:
        i += 1

print(count)