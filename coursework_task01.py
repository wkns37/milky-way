import functools


def task_01():
    # https://codeforces.com/problemset/problem/1656/I
    print("=== TASK 1 ===")
    read = input()
    for _ in range(int(read)):
        input_graph = read_graph()
        ans: list[list[int]] = solve(input_graph)
        print_ans(ans)


class Graph:
    def __init__(self):
        self.n: int = 0
        self.m: int = 0
        self.al: list[list[int]] = []
        self.morphism: list[int] = []
        self.dfs_children: list[list[int]] = []
        self.dfs_parent: list[int] = []
        self.dfs_num: list[int] = []
        self.dfs_low: list[int] = []
        self.dfs_count: int = 0
        self.is_root_ac: bool = False
        self.bad_biccon: bool = False
        self.repr_edge: list[tuple[int, int]] = []

    def dt_dfs(self, v: int, par: int):
        self.dfs_parent[v] = par
        self.dfs_low[v] = self.dfs_count
        self.dfs_num[v] = self.dfs_count
        self.dfs_count += 1
        for u in self.al[v]:
            if u == par:
                pass
            elif self.dfs_num[u] == -1:
                self.dfs_children[v].append(u)
                self.dt_dfs(u, v)
                self.dfs_low[v] = min(self.dfs_low[v], self.dfs_low[u])
            else:
                self.dfs_low[v] = min(self.dfs_low[v], self.dfs_num[u])

    def min_repr_edge(self, a: tuple[int, int], b: tuple[int, int]) -> tuple[int, int]:
        if a[0] == -1:
            return b
        if b[0] == -1:
            return a
        if self.dfs_num[a[1]] < self.dfs_num[b[1]]:
            return a
        if self.dfs_num[a[1]] > self.dfs_num[b[1]]:
            return b
        if self.dfs_num[a[0]] < self.dfs_num[b[0]]:
            return a
        if self.dfs_num[a[0]] < self.dfs_num[b[0]]:
            return a
        return a

    def dt_dfs_hamil(self, v: int):
        self.repr_edge[v] = (-1, -1)
        for u in self.dfs_children[v]:
            self.dt_dfs_hamil(u)
            self.repr_edge[v] = self.min_repr_edge(self.repr_edge[v], self.repr_edge[u])

        for u in self.al[v]:
            if u == self.dfs_parent[v]:
                pass
            elif self.dfs_num[u] < self.dfs_num[v]:
                self.repr_edge[v] = self.min_repr_edge(self.repr_edge[v], (v, u))

        if self.dfs_parent[v] == -1:
            pass
        else:
            if len(self.dfs_children[v]) == 0:
                pass
            elif len(self.dfs_children[v]) == 1:
                if self.dfs_low[self.dfs_children[v][0]] != self.dfs_low[v] and self.dfs_low[self.dfs_children[v][0]] != \
                        self.dfs_num[self.dfs_parent[v]]:
                    self.bad_biccon = True
            elif len(self.dfs_children[v]) == 2:
                if self.dfs_parent[self.dfs_parent[v]] != -1:
                    if not ((self.dfs_low[self.dfs_children[v][0]] == self.dfs_num[self.dfs_parent[v]]) ^ (
                            self.dfs_low[self.dfs_children[v][1]] == self.dfs_num[self.dfs_parent[v]])):
                        self.bad_biccon = True
                    if self.dfs_low[v] < min(self.dfs_low[self.dfs_children[v][0]],
                                             self.dfs_low[self.dfs_children[v][1]]):
                        self.bad_biccon = True
            else:
                self.bad_biccon = True

    def dt_dfs_cedges(self, cedges: list[list[tuple[int, int]]], edge_stack: list[tuple[int, int]], v: int, par: int):
        self.dfs_parent[v] = par
        self.dfs_low[v] = self.dfs_count
        self.dfs_num[v] = self.dfs_count
        self.dfs_count += 1
        for u in self.al[v]:
            if u == par:
                pass
            elif self.dfs_num[u] == -1:
                self.dfs_children[v].append(u)
                edge_stack.append((v, u))
                self.dt_dfs_cedges(cedges, edge_stack, u, v)
                self.dfs_low[v] = min(self.dfs_low[v], self.dfs_low[u])
                if (par == -1 and self.is_root_ac) or (par != -1 and self.dfs_low[u] >= self.dfs_num[v]):
                    comp: list[tuple[int, int]] = []
                    while edge_stack[-1][0] != v or edge_stack[-1][1] != u:
                        comp.append(edge_stack[-1])
                        edge_stack.pop()
                    comp.append(edge_stack[-1])
                    edge_stack.pop()
                    cedges.append(comp)
            else:
                self.dfs_low[v] = min(self.dfs_low[v], self.dfs_num[u])
                if self.dfs_num[u] < self.dfs_num[v]:
                    edge_stack.append((v, u))

    def generate_dfs_tree(self, root: int):
        self.dfs_children = [[] for _ in range(self.n)]
        self.dfs_parent = [0 for _ in range(self.n)]
        self.dfs_count = 0
        self.dfs_num = [-1 for _ in range(self.n)]
        self.dfs_low = [-1 for _ in range(self.n)]
        self.dt_dfs(root, -1)

    def generate_edge_partition(self, cedges: list[list[tuple[int, int]]], edge_stack: list[tuple[int, int]],
                                root: int):
        self.generate_dfs_tree(root)
        self.is_root_ac = len(self.dfs_children[root]) > 1
        self.dfs_children = [[] for _ in range(self.n)]
        self.dfs_parent = [0 for _ in range(self.n)]
        self.dfs_count = 0
        self.dfs_num = [-1 for _ in range(self.n)]
        self.dfs_low = [-1 for _ in range(self.n)]
        self.dt_dfs_cedges(cedges, edge_stack, root, -1)
        if edge_stack:
            cedges.append(edge_stack)

    def generate_hamil_dfs_tree(self, root: int):
        self.generate_dfs_tree(root)
        self.repr_edge = [(0, 0) for _ in range(self.n)]
        self.dt_dfs_hamil(root)


def partition_biconnected(g: Graph) -> list[Graph]:
    cedges: list[list[tuple[int, int]]] = []
    edge_stack: list[tuple[int, int]] = []
    g.generate_edge_partition(cedges, edge_stack, 0)
    comp: list[Graph] = []
    for vec in cedges:
        h = Graph()
        h.n = 0
        h.m = len(vec)
        rmorph: dict[int, int] = {}
        for e in vec:
            if rmorph.get(e[0]) is None:
                rmorph[e[0]] = h.n
                h.n += 1
            if rmorph.get(e[1]) is None:
                rmorph[e[1]] = h.n
                h.n += 1
        h.morphism = [0 for _ in range(h.n)]
        h.al = [[] for _ in range(h.n)]
        for e in vec:
            u = rmorph[e[0]]
            v = rmorph[e[1]]
            h.morphism[u] = g.morphism[e[0]]
            h.morphism[v] = g.morphism[e[1]]
            h.al[u].append(v)
            h.al[v].append(u)
        comp.append(h)
    return comp


def upwards_path(g: Graph, hc: list[int], v: int, tar: int):
    if len(g.dfs_children[v]) == 2:
        u1: int = g.dfs_children[v][0]
        u2: int = g.dfs_children[v][1]
        if g.repr_edge[u1] == g.repr_edge[v]:
            u1, u2 = u2, u1
        hc.append(v)
        downwards_path(g, hc, u1, g.repr_edge[u1][0])
        if v != tar:
            upwards_path(g, hc, g.dfs_parent[v], tar)
    elif len(g.dfs_children[v]) == 1:
        u: int = g.dfs_children[v][0]
        hc.append(v)
        if g.repr_edge[u] != g.repr_edge[v]:
            downwards_path(g, hc, u, g.repr_edge[u][0])
        if v != tar:
            upwards_path(g, hc, g.dfs_parent[v], tar)
    else:
        hc.append(v)
        if v != tar:
            upwards_path(g, hc, g.dfs_parent[v], tar)


def downwards_path(g: Graph, hc: list[int], v: int, tar: int):
    if len(g.dfs_children[v]) == 2:
        u1: int = g.dfs_children[v][0]
        u2: int = g.dfs_children[v][1]
        if g.repr_edge[u1] == g.repr_edge[v]:
            u1, u2 = u2, u1
        upwards_path(g, hc, g.repr_edge[u1][0], u1)
        hc.append(v)
        downwards_path(g, hc, u2, tar)
    elif len(g.dfs_children[v]) == 1:
        u: int = g.dfs_children[v][0]
        if v == tar:
            upwards_path(g, hc, g.repr_edge[u][0], u)
            hc.append(v)
        else:
            hc.append(v)
            downwards_path(g, hc, u, tar)
    else:
        hc.append(v)


def hamiltonian_cycle(g: Graph) -> list[int]:
    g.generate_hamil_dfs_tree(0)
    if g.bad_biccon:
        return []
    hc: list[int] = []
    downwards_path(g, hc, 0, g.repr_edge[0][0])
    assert len(hc) == g.n
    return hc


comp_index = 0


def cyclic_comparator(a: int, b: int) -> bool:
    if a < comp_index:
        a += 1e7
    if b < comp_index:
        b += 1e7
    return a < b


def sort_graph(g: Graph, hc: list[int]) -> Graph:
    h = Graph()
    h.n = g.n
    h.m = g.m
    h.morphism = [0 for _ in range(g.n)]
    h.al = [[] for _ in range(g.n)]
    rgc: list[int] = [0 for _ in range(g.n)]
    for i in range(g.n):
        h.morphism[i] = g.morphism[hc[i]]
        rgc[hc[i]] = i
    for i in range(g.n):
        for j in g.al[hc[i]]:
            h.al[i].append(rgc[j])
        h.al[i].sort(key=functools.cmp_to_key(cyclic_comparator))
    return h


def has_crossing(g: Graph) -> bool:
    bad_stack: list[tuple[int, int]] = []
    for i in range(g.n):
        global comp_index
        comp_index = i
        while bad_stack and bad_stack[-1][0] == i:
            bad_stack.pop()
        j = len(g.al[i]) - 2
        while j:
            u = g.al[i][j]
            if bad_stack and cyclic_comparator(bad_stack[-1][0], u) and cyclic_comparator(u, bad_stack[-1][1]):
                return True
            if u > i and (not bad_stack or u != bad_stack[-1][0]):
                bad_stack.append((u, i))
            j -= 1
    return False


def merge_ans(g: Graph, ans: list[list[int]]):
    for i in range(g.n):
        for j in g.al[i]:
            ans[g.morphism[i]].append(g.morphism[j])


def merge_single_edge_ans(g: Graph, ans: list[list[int]]):
    u = g.morphism[0]
    v = g.morphism[1]
    ans[u].append(v)
    ans[v].append(u)


def solve(input_graph: Graph) -> list[list[int]]:
    ans: list[list[int]] = [[] for _ in range(input_graph.n)]
    components: list[Graph] = partition_biconnected(input_graph)
    for g in components:
        if g.n == 1:
            pass
        elif g.n == 2:
            merge_single_edge_ans(g, ans)
        else:
            hc: list[int] = hamiltonian_cycle(g)
            if not hc:
                return []
            g2: Graph = sort_graph(g, hc)
            if has_crossing(g2):
                return []
            merge_ans(g2, ans)
    return ans


def read_graph() -> Graph:
    read = input().split()
    n = int(read[0])
    m = int(read[1])
    g = Graph()
    g.n = n
    g.m = m
    g.al = [[] for _ in range(n)]
    g.morphism = [0 for _ in range(n)]
    for i in range(n):
        g.morphism[i] = i
    for i in range(m):
        read = input().split()
        u = int(read[0])
        v = int(read[1])
        g.al[u].append(v)
        g.al[v].append(u)
    return g


def print_ans(ans: list[list[int]]):
    n = len(ans)
    if n == 0:
        print('NO')
    else:
        print('YES')
        for i in range(n):
            for x in ans[i]:
                print(f'{x} ', end='')
            print()
