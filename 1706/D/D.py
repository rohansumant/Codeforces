def solve():
    n, k = map(int, input().split())
    a = list(map(int,input().split()))
    M = max(a)
    d = [[] for i in range(M+1)]
    for i in range(n):
        el = a[i]
        for j in range(1,k+1):
            ix = el // j
            if (not d[ix]) or (d[ix][-1] != i):
                d[ix].append(i)

    def add(mp,x):
        if x not in mp:
            mp[x] = 1
        else:
            mp[x] += 1

    def remove(mp,x):
        if x in mp:
            if mp[x] == 1:
                mp.pop(x)
            else:
                mp[x] -= 1
            
    #print(d)
    ans = int(2e9)
    i, j = 0, 0
    mp = {}
    while i <= M:
        while j <= M and len(mp) < n:
            for x in d[j]:
                add(mp,x)
            j += 1
        #print(i,j)
        if len(mp) == n:
            ans = min(ans,j-i-1)
        for x in d[i]:
            remove(mp,x)
        i += 1

    print(ans)

t = int(input())
for _ in range(t):
    solve()
