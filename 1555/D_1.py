import sys

input = sys.stdin.readline

n,q = map(int,input().split())
a = input()

pref_sum = [None]*n
lookup = {'a':0, 'b':1, 'c':2}

for i in range(n):
    if i == 0:
        arr_2d = [[0,0,0] for _ in range(3)]
    else: 
        arr_2d = [row[:] for row in pref_sum[i-1]]
    arr_2d[lookup[a[i]]][i%3] += 1
    pref_sum[i] = arr_2d

#print(pref_sum)


for _ in range(q):
    l,r = map(int,input().split())
    l -= 1
    r -= 1
    arr_2d = [row[:] for row in pref_sum[r]]
    if l > 0:
        for i in range(3):
            for j in range(3):
                arr_2d[i][j] -= pref_sum[l-1][i][j]
    #print(arr_2d)
    sum = 0
    for row in [[0,1,2],[0,2,1],
            [1,0,2],[1,2,0],
            [2,0,1],[2,1,0]]:
        curr_sum = 0
        for ix in range(3):
            curr_sum += arr_2d[ix][row[ix]]
        sum = max(sum,curr_sum)

    ans = (r-l+1) - sum
    print(ans)
