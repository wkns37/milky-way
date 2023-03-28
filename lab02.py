import random
import time


def task_01():
    print("=== TASK 1 ===")
    arr = make_array(10, -100, 100)
    print('Binary search')
    ask_user_to_play_with_us(arr, binary_search, verbose=True, ask_to_add=True, ask_to_remove=False)
    print('\nBinary tree search')
    ask_user_to_play_with_us(arr, tree_search, verbose=True)
    print('\nStandard search')
    ask_user_to_play_with_us(arr, list.index, verbose=True)


def make_array(m: int = 50, min_limit: int = -250, max_limit: int = 1017) -> list[int]:
    return [random.randint(min_limit, max_limit) for _ in range(m)]


def beauty_time(nanoseconds: int) -> str:
    return "{0:0.2f} ms".format(nanoseconds / (10 ** 6))


def ask_user_to_play_with_us(arr: list[int], find_func, ask_to_add: bool = False, ask_to_remove: bool = False,
                             verbose: bool = False):
    arr.sort()
    if verbose:
        print(f'Current array values: {arr}')

    if ask_to_add:
        answer = input('Do you want to add another value? (y/n) ')
        if answer == 'y':
            number = input('Enter the value: ')
            arr.append(int(number))
            arr.sort()
            if verbose:
                print(f'Current array values: {arr}')

    if ask_to_remove:
        answer = input('Do you want to remove existing value? (y/n) ')
        if answer == 'y':
            number = input('Enter the value: ')
            try:
                arr.remove(int(number))
                arr.sort()
                if verbose:
                    print(f'Current array values: {arr}')
            except ValueError:
                print('Oops! Unable to remove a value that does not exist')

    answer = input('Do you want to find value? (y/n) ')
    if answer == 'y':
        number = input('Enter the value: ')
        try:
            start_time = time.time_ns()
            index = find_func(arr, int(number))
            end_time = time.time_ns()
            print(f'Your value at {index} index (elapsed time {beauty_time(end_time - start_time)})')
        except ValueError:
            print('Oops! Unable to find a value that does not exist')


def binary_search(arr: list[int], number: int) -> int:
    low = 0
    high = len(arr)
    while low < high:
        middle = int((low + high) / 2)
        if number < arr[middle]:
            high = middle
        elif number > arr[middle]:
            low = middle + 1
        else:
            return middle
    raise ValueError()


class Node:
    def __init__(self, value, index):
        self.l_child = None
        self.r_child = None
        self.value = value
        self.index = index


def tree_insert(root, node):
    if root.value > node.value:
        if root.l_child is None:
            root.l_child = node
        else:
            tree_insert(root.l_child, node)
    else:
        if root.r_child is None:
            root.r_child = node
        else:
            tree_insert(root.r_child, node)


def tree_find(root, value) -> int:
    if root is None:
        raise ValueError()

    if value > root.value:
        return tree_find(root.r_child, value)
    elif value < root.value:
        return tree_find(root.l_child, value)
    else:
        return root.index


def tree_search(arr: list[int], number: int) -> int:
    if not arr:
        raise ValueError()

    root = Node(arr[0], 0)
    for i in range(1, len(arr)):
        tree_insert(root, Node(arr[i], i))
    return tree_find(root, number)


def fibonacci_search(arr: list[int], number: int) -> int:
    fib_first = 0
    fib_second = 1
    fib = fib_second + fib_first
    while fib < len(arr):
        fib_first = fib_second
        fib_second = fib
        fib = fib_second + fib_first
    index = -1
    while fib > 1:
        i = min(index + fib_first, len(arr) - 1)
        if arr[i] < number:
            fib = fib_second
            fib_second = fib_first
            fib_first = fib - fib_second
            index = i
        elif arr[i] > number:
            fib = fib_first
            fib_second = fib_second - fib_first
            fib_first = fib - fib_second
        else:
            return i
    if fib_second and index < (len(arr) - 1) and arr[index + 1] == number:
        return index + 1
    raise ValueError()


def interpolation_search(arr: list[int], number: int) -> int:
    left = 0
    right = len(arr) - 1
    while arr[left] < number < arr[right]:
        mid = int(left + (number - arr[left]) * (right - left) / (arr[right] - arr[left]))
        if arr[mid] < number:
            left = mid + 1
        elif arr[mid] > number:
            right = mid - 1
        else:
            return mid

    if arr[left] == number:
        return left
    elif arr[right] == number:
        return right
    raise ValueError()


def task_02():
    print("=== TASK 2 ===")
    print('Hast table')
    table = HashTable()
    table.insert(1, 'Apple')
    table.insert(2, 'Banana')
    table.insert(3, 'Kiwi')
    table.insert(4, 'Orange')
    table.insert(5, 'Avocado')
    table.insert(6, 'Lemon')
    table.print()
    answer = input('Do you want to find value by key? (y/n) ')
    if answer == 'y':
        key = input('Enter the key: ')
        start_time = time.time_ns()
        value = table.search(int(key))
        end_time = time.time_ns()
        if value:
            print(f'Value is: {value} (elapsed time {beauty_time(end_time - start_time)})')
        else:
            print('Oops! Unable to find a value that does not exist')

    print('\nChain map')
    chain = ChainMap({'key1': 'value1', 'key2': 'value2'}, {'key3': 'value3', 'key4': 'value4'})
    chain.print()
    answer = input('Do you want to find value by key? (y/n) ')
    if answer == 'y':
        key = input('Enter the key: ')
        start_time = time.time_ns()
        value = chain.get(key)
        end_time = time.time_ns()
        if value:
            print(f'Value is: {value} (elapsed time {beauty_time(end_time - start_time)})')
        else:
            print('Oops! Unable to find a value that does not exist')


class HashTable:
    def __init__(self):
        self.hash_table = [[] for _ in range(10)]

    def insert(self, key, value):
        hash_key = hash(key) % len(self.hash_table)
        bucket = self.hash_table[hash_key]
        key_exists = False
        i = 0
        for i, key_value in enumerate(bucket):
            k, v = key_value
            if key == k:
                key_exists = True
                break
        if key_exists:
            bucket[i] = (key, value)
        else:
            bucket.append((key, value))

    def print(self):
        print(self.hash_table)

    def search(self, key):
        hash_key = hash(key) % len(self.hash_table)
        bucket = self.hash_table[hash_key]
        for key_value in bucket:
            k, v = key_value
            if k == key:
                return v


class ChainMap:
    def __init__(self, *maps):
        self.maps = list(maps) or [{}]

    def get(self, key):
        for m in self.maps:
            if key in m:
                return m[key]
        return None

    def print(self):
        print(self.maps)

    def new_child(self, new_map):
        return ChainMap(new_map, *self.maps)


def task_03():
    print("=== TASK 3 ===")
    solve_queen_problem()


def solve_queen_problem():
    columns = set()
    positive_diagonal = set()
    negative_diagonal = set()
    result = []
    board = [['. '] * 8 for _ in range(8)]

    def backtrack(row: int):
        if row == 8:
            copy = [''.join(row) for row in board]
            result.append(copy)
            return

        for column in range(8):
            if column in columns or (row + column) in positive_diagonal or (row - column) in negative_diagonal:
                continue

            columns.add(column)
            positive_diagonal.add(row + column)
            negative_diagonal.add(row - column)
            board[row][column] = 'Q '

            backtrack(row + 1)

            columns.remove(column)
            positive_diagonal.remove(row + column)
            negative_diagonal.remove(row - column)
            board[row][column] = '. '

    backtrack(0)
    for x in result:
        for y in x:
            print(y)
        print()


def run():
    task_01()
    task_02()
    task_03()
