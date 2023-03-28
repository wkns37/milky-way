import time
from collections import deque

import networkx as nx
from matplotlib import pyplot as plt


def make_matrix(m: int, n: int) -> list[list[int]]:
    return [[0 for _ in range(m)] for _ in range(n)]


def boom(G: nx.DiGraph) -> tuple[list[int], list[list[int]]]:
    nodes = [int(x) for x in G.nodes]
    weights = make_matrix(len(G.nodes), len(G.nodes))
    for (u, v, wt) in G.edges.data('weight'):
        # noinspection PyTypeChecker
        weights[int(u)][int(v)] = float(wt)
    return nodes, weights


def find_shortest_paths(nodes: list[int], weights: list[list[int]]) -> list[tuple[int, int, float, list[int]]]:
    result = []
    for x in range(len(nodes)):
        for y in range(len(nodes)):
            result.append(find_shortest_path(source=x, destination=y, nodes=nodes, weights=weights))
    return result


def find_shortest_path(source: int, destination: int, nodes: list[int], weights: list[list[int]]) -> \
        tuple[int, int, float, list[int]]:
    if source == destination:
        return source, destination, float(0), [source]

    inf = float('inf')

    d = [0.0 if v == source else inf for v in nodes]
    visited = [False for _ in nodes]
    q = deque()
    q.append(source)
    p = [-1 for _ in nodes]

    while q:
        v: int = q.popleft()
        visited[v] = True
        for n in nodes:
            if n != v and n != source and weights[v][n] != 0:
                distance: float = d[v] + weights[v][n]
                if d[n] > distance:
                    d[n] = distance
                    if not visited[n]:
                        q.append(n)
                    else:
                        q.appendleft(n)
                    p[n] = v
                    visited[n] = True

    if p[destination] == -1:
        return source, destination, float(-1), []

    path = []
    v = destination
    while v != -1:
        path.append(v)
        v = p[v]
    path.reverse()
    return source, destination, d[destination], path


def main():
    def beauty_time(nanoseconds: int) -> str:
        return "{0:0.2f}".format(nanoseconds / (10 ** 6))

    G: nx.DiGraph = nx.read_weighted_edgelist('data/lab05_task01.txt', create_using=nx.DiGraph)
    nodes, weights = boom(G)

    source = input('Enter the source node number: ')
    if len(source) == 0:
        print('The source node cannot be empty')
        return
    destination = input('Enter the destination node number: ')
    if len(destination) == 0:
        print('The destination node cannot be empty')
        return

    start = time.time_ns()
    paths = find_shortest_paths(nodes=nodes, weights=weights)
    end = time.time_ns()

    selected_path = None
    print('Source | Destination | Length | Path')
    print('-------+-------------+--------+-------------')
    for path in paths:
        if path[0] == int(source) and path[1] == int(destination) and path[2] != -1:
            selected_path = path
        print(f'{path[0]: 6} | {path[1]: 11} | ', end='')
        if path[2] != -1:
            print(f'{path[2]: 6.3} | ', end='')
        else:
            print('  None | ', end='')

        if path[3]:
            for i in range(len(path[3])):
                if i == 0:
                    print(f"{path[3][i]}", end='')
                else:
                    print(f" -> {path[3][i]}", end='')
        else:
            print('None', end='')
        print()
    print()

    pos = nx.planar_layout(G)

    if selected_path is None:
        print('Did not found the path that you specified')
        nx.draw_networkx(G, pos)
    else:
        print('The path that you specified is shown on the plot.')
        sequences = []
        for i in range(len(selected_path[3]) - 1):
            sequences.append((str(selected_path[3][i]), str(selected_path[3][i + 1])))
        colors = ['r' if sequences.__contains__(edge) else 'b' for edge in G.edges]
        nx.draw_networkx(G, pos, edge_color=colors)

    labels = nx.get_edge_attributes(G, 'weight')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
    print(f"Elapsed time: {beauty_time(end - start)} ms")
    plt.show()


def run():
    main()
