def task_03():
    # https://codeforces.com/problemset/problem/468/C
    print("=== TASK 3 ===")
    m = int(input())
    x, t = 10 ** 100 - 1, m - 100 * 45 * 10 ** 99 % m
    print(t, t + x)
