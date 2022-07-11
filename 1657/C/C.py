def solve():
    n = int(input())
    s = input()
    closers = []
    for i in range(n):
        if s[i] == ')':
            closers.append(i)
    closer_ix = 0
    ops, ix = 0, 0
    while ix < n:
        if s[ix] == '(':
            if ix < n-1:
                ops += 1
                ix += 2
            else:
                break
        else:
            while closer_ix < len(closers) and closers[closer_ix] <= ix:
                closer_ix += 1
            if closer_ix < len(closers):
                ops += 1
                ix = closers[closer_ix]+1
                closer_ix += 1
            else:
                break
    print(ops,n-ix)

t = int(input())
for _ in range(t):
    solve()

