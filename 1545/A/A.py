import sys

input = sys.stdin.readline

def main():
    t = int(input())
    for _ in range(t):
        solve()

def solve():
    n = int(input())
    a = [i for i in map(int,input().split())]
    base = process(a)
    a.sort()
    exp = process(a)
    print("YES" if base == exp else "NO")


def process(a):
    d = {}
    for i in range(len(a)):
        e = a[i]
        val = [0,0] if e not in d else d[e]
        val[i%2] += 1
        d[e] = val
    return d

main()
