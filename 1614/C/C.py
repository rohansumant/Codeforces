import sys 

input = sys.stdin.readline
MOD = int(1e9+7)

def fastpow(a,b):
    if b == 0:
        return 1
    ans = fastpow(a,b//2)
    ans = (ans * ans) % MOD
    if b%2 == 0:
        return ans
    else:
        return (ans * a) % MOD


def solve():
    n, m = map(int,input().split())
    all = 0
    for _ in range(m):
        _, _, x = map(int,input().split())
        all |= x
    ans = (all * fastpow(2,n-1)) % MOD
    print(ans)

def main():
    for _ in range(int(input())):
        solve()

main()

