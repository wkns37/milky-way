MOD = 998244353


def task_05():
    # https://codeforces.com/problemset/problem/1569/C
    print("=== TASK 5 ===")
    t = int(input())
    for _ in range(t):
        n = int(input())
        read = input().split()
        a = [int(x) for x in read]
        mx = max(a)
        cmx = a.count(mx)
        k = a.count(mx - 1)
        ans = 1
        sub = 1
        for i in range(1, n + 1):
            ans = ans * i % MOD
            if i != k + 1:
                sub = sub * i % MOD
        if cmx == 1:
            ans = (ans - sub + MOD) % MOD
        print(ans)
