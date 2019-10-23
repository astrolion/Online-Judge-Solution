
t = int(input())

for tc in range(t):
    n, m = map(int, input().split(' '))

    v = map(int, input().split(' '))

    cnt = [0]*65

    for x in v:
        for i in range(60):
            if x & (1<<i):
                cnt[i]+=1


    base = 0

    for x in range(60):
        base += (1<<x) * min( cnt[x], n-cnt[x] )

    ans = 0

    for i in range(55,-1,-1):
        zeros = n - cnt[i]
        ones = cnt[i]

        did = (1<<i) * zeros
        did = base + did - min(zeros, ones) * (1<<i)

        if did <= m:
            base = did
            ans |= 1<<i
        else :
            did = (1<<i) * ones
            did = base + did - min(zeros, ones) * (1<<i)

            if did<= m:
                base = did
            else :
                ans = -1
                break


    print("Case #%d: %d" % (tc+1,ans))

