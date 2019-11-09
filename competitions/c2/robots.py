while True:
    w, l = map(int,input().split())

    if w == 0 and l == 0:
        break

    ax = 0
    ay = 0
    tx = 0
    ty = 0

    n = int(input())

    for i in range(n):
        pair = input().split()
        c = pair[0][0]
        steps = int(pair[1])

        if c == 'r':
            ax += steps
            tx += steps
        elif c == 'l':
            ax -= steps
            tx -= steps
        elif c == 'u':
            ay += steps
            ty += steps
        elif c == 'd':
            ay -= steps
            ty -= steps

        if ax >= w:
            ax = w - 1
        if ax < 0:
            ax = 0
        if ay >= l:
            ay = l - 1
        if ay < 0:
            ay = 0
    print("Robot thinks {} {}".format(tx,ty))
    print("Actually at {} {}".format(ax,ay))

