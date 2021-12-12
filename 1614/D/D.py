#upsolved https://codeforces.com/blog/entry/97283

import sys

input = sys.stdin.readline

def main():
    n = int(input())
    a = list(map(int,input().split()))
    N = max(a)
    div = [0]*(N+1)
    for i in a:
        div[i] += 1
    dp = [0]*(N+1)
    #print(div)
    ans = n

    for i in range(1,N+1):
        for j in range(i+i,N+1,i):
            div[i] += div[j]

    for i in range(N,0,-1):
        dp[i] = max(dp[i],i*div[i])
        for j in range(i+i,N+1,i):
            dp[i] = max(dp[i], dp[j]+(div[i]-div[j])*i)
            ans = max(ans,dp[i])



    print(ans)


main()
