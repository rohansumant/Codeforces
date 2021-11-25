import functools, itertools, sys

input = sys.stdin.readline

n,q = map(int,input().split())
a = input()

options = []
perms = itertools.permutations('abc')

for p in perms:
    parity = [1 if x != y else 0 for (x,y) in zip(a,itertools.cycle(p))]
    # cc = [(x,y) for (x,y) in zip(a,itertools.cycle(p))]
    # print(p, parity, cc)
    options.append([i for i in itertools.accumulate(parity,lambda x,y:x+y)])

#print(options)

for _ in range(q):
    (l,r) = map(int,input().split())
    l -= 1
    r -= 1
    cost = n
    for o in options:
        curr_cost = o[r] if l == 0 else o[r]-o[l-1]
        cost = min(cost, curr_cost)
    print(cost)
