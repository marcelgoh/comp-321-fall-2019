inputs = list(map(int, input().split()))
x = inputs[0]
y = inputs[1]
n = inputs[2]

for v in range(1,n+1):
    if (v % x ==0 and v % y ==0):
        print('FizzBuzz')
    elif v%x ==0:
        print('Fizz')
    elif v%y==0:
        print('Buzz')
    else:
        print(v)
