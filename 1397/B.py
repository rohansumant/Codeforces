def calc(x, a):
    max_ans = 1e18
    curr_ans = 0
    num = 1
    for i in range(len(a)):
        curr_ans += abs(a[i] - num)
        num *= x
        if curr_ans > max_ans:
            return max_ans
    return curr_ans

def main():
    n = int(input())
    a = [i for i in map(int,input().split())]
    a.sort()
    #print(n,a)

    ans = 1e18
    if n <= 2:
        ans = a[-1]-1
    else:
        ballpark = int(pow(a[-1],1/(n-1)))
        for i in range(ballpark-15,ballpark+15):
            ans = min(ans,calc(i,a))

    print(ans)
#
#    l, r = 1, 1e7
#
#    max_ans = 1e18
#    while l < r-1:
#        m = (l+r)//2
#        curr_ans = calc(m,a)
#        print(l,m,r,curr_ans)
#        if curr_ans < max_ans:
#            l = m
#            max_ans = curr_ans
#        else:
#            r = m
#
#    print(calc(l,a))
#
main()
