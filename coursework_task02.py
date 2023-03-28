def task_02():
    # https://codeforces.com/problemset/problem/582/E
    print("=== TASK 2 ===")
    task_02_main()


MOD = 1e9 + 7
N = 200 + 5
V = 4
S = 1 << V
M = 1 << S

s: list[str]
n = 0
d: list[list[int]] = [[0 for _ in range(M)] for _ in range(N)]

variables = 'ABCDabcd'
operations = '&|'

req: list[int] = [0 for _ in range(1 << V)]


def add(a: int, b: int) -> int:
    return a + b - MOD if a + b >= MOD else a + b


def sub(a: int, b: int) -> int:
    return a - b + MOD if a - b < 0 else a - b


def mul(a: int, b: int) -> int:
    return int((a * b) % MOD)


def mask_one(v: int) -> int:
    mask = 0
    for i in range(S):
        if (i >> v) & 1:
            mask |= 1 << i
    return mask


def negate(a: list[int]):
    a[0:M] = a[0:M][::-1]


def copy(a: list[int], b: list[int]):
    for i in range(M):
        b[i] = a[i]


def add1(a: list[int], b: list[int]):
    for i in range(M):
        b[i] = add(b[i], a[i])


def sum_sub(a: list[int], b: list[int], d: int):
    copy(a, b)
    for i in range(S):
        for mask in range(M):
            if not (mask & (1 << i)):
                if d == +1:
                    b[mask ^ (1 << i)] = add(b[mask ^ (1 << i)], b[mask])
                elif d == -1:
                    b[mask ^ (1 << i)] = sub(b[mask ^ (1 << i)], b[mask])
                else:
                    raise ValueError()


t1: list[int] = [0 for _ in range(M)]
t2: list[int] = [0 for _ in range(M)]
tops: list[list[int]] = [[0 for _ in range(M)] for _ in range(2)]


def door(l: list[int], r: list[int], v: list[int]):
    sum_sub(l, t1, +1)
    sum_sub(r, t2, +1)
    for i in range(M):
        t1[i] = mul(t1[i], t2[i])
    sum_sub(t1, v, -1)


def parse(pos: int) -> tuple[int, int]:
    global n
    if s[pos] != '(':
        v = variables.find(s[pos])
        pos += 1
        if v == -1:
            for i in range(V):
                d[n][mask_one(i)] = 1
                d[n][(M - 1) ^ mask_one(i)] = 1
        else:
            if v < V:
                d[n][mask_one(v)] = 1
            else:
                d[n][(M - 1) ^ mask_one(v - V)] = 1
        n += 1
        return pos, n - 1
    me = n
    n += 1
    pos += 1
    pos, l = parse(pos)
    assert s[pos] == ')'
    pos += 1
    v = operations.find(s[pos])
    pos += 2
    pos, r = parse(pos)
    assert s[pos] == ')'
    pos += 1

    door(d[l], d[r], tops[1])

    negate(d[l])
    negate(d[r])
    door(d[l], d[r], tops[0])
    negate(tops[0])
    negate(d[r])
    negate(d[l])

    if v == -1:
        for i in range(len(operations)):
            add1(tops[v], d[me])
    else:
        add1(tops[v], d[me])
    return pos, me


def task_02_main():
    global s, n, req
    read = input()
    s = [char for char in read]
    pos = 0
    pos, root = parse(pos)
    n = int(input())
    for i in range(S):
        req[i] = -1
    for i in range(n):
        mask = 0
        read = input().split()
        for j in range(V):
            a = int(read[j])
            mask |= (a << j)
        req[mask] = int(read[4])
    res = 0
    for i in range(M):
        good = True
        for j in range(S):
            good &= (req[j] == -1 or req[j] == ((i >> j) & 1))
        if good:
            res = add(res, d[root][i])
    print(res)


