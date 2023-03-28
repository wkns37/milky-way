def task_06():
    # https://codeforces.com/problemset/problem/1260/A
    print("=== TASK 6 ===")
    n = int(input())
    for _ in range(n):
        read = input().split()
        c, summary = int(read[0]), int(read[1])
        d = summary // c
        rem = summary % c
        result = rem * (d + 1) * (d + 1) + (c - rem) * d * d
        print(result)
