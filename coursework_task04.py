def task_04():
    # https://codeforces.com/problemset/problem/961/D
    print("=== TASK 4 ===")
    task_04_main()


N = 200 * 1000 + 555
n = 0
p: list[tuple[int, int]] = [(0, 0) for _ in range(N)]
used: list[bool] = [False for _ in range(N)]


def sub(a: tuple[int, int], b: tuple[int, int]) -> tuple[int, int]:
    return a[0] - b[0], a[1] - b[1]


def cross(a: tuple[int, int], b: tuple[int, int]) -> int:
    return a[0] * b[1] - a[1] * b[0]


def check() -> bool:
    i1, i2 = -1, -1
    for i in range(n):
        if used[i]:
            continue
        if i1 == -1:
            i1 = i
        elif i2 == -1:
            i2 = i
    if i2 == -1:
        return True
    for i in range(n):
        if used[i]:
            continue
        if cross(sub(p[i2], p[i1]), sub(p[i], p[i1])) != 0:
            return False
    return True


def check2(a: tuple[int, int], b: tuple[int, int]) -> bool:
    global used
    used = [False for _ in range(N)]
    for i in range(n):
        if cross(sub(b, a), sub(p[i], a)) == 0:
            used[i] = True
    return check()


def task_04_main():
    global n
    n = int(input())
    for i in range(n):
        read = input().split()
        p[i] = (int(read[0]), int(read[1]))
    if n <= 2:
        print('YES')
        return
    if check2(p[0], p[1]) or check2(p[0], p[2]) or check2(p[1], p[2]):
        print('YES')
    else:
        print('NO')
