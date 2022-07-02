
def breakdown(x,m):
    cnt = 1
    while x%m == 0:
        cnt *= m
        x //= m
    return (x,cnt)

def process(arr,m):
    ans = []
    for i in range(len(arr)):
        (x,y) = breakdown(arr[i],m)
        if i == 0:
            ans.append((x,y))
        else:
            (p,q) = ans[-1]
            if x == p:
                ans[-1] = (x,q+y)
            else:
                ans.append((x,y))
    #print(ans)
    return ans

def solve():
    n, m = map(int,input().split())
    a = [int(i) for i in input().split()]
    k = int(input())
    b = [int(i) for i in input().split()]
    ans = 'YES' if (process(a,m) == process(b,m)) else 'NO'
    print(ans)

def main():
    tc = int(input())
    for _ in range(tc):
        solve()

main()
