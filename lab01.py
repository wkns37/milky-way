import random
import time


def task_01():
    print("=== TASK 1 ===")
    print("Hello, World!\n")


def task_02():
    print("=== TASK 2 ===")
    width = 600
    height = 400
    verbose = False  # enable if want to see the matrices themselves

    # Selection sort
    matrix = make_matrix(m=width, n=height, min_limit=100, max_limit=999)
    print("Selection sort")
    if verbose:
        print("Before:")
        for x in range(4):
            print(f'  {matrix[x]}')
    selection_sort_time = sort_matrix_selection_sort(matrix)
    if verbose:
        print("After:")
        for x in range(4):
            print(f'  {matrix[x]}')
        print('\n')

    # Insertion sort
    matrix = make_matrix(m=width, n=height, min_limit=100, max_limit=999)
    print("Insertion sort")
    if verbose:
        print("Before:")
        for x in range(4):
            print(f'  {matrix[x]}')
    insertion_sort_time = sort_matrix_insertion_sort(matrix)
    if verbose:
        print("After:")
        for x in range(4):
            print(f'  {matrix[x]}')
        print('\n')

    # Bubble sort
    matrix = make_matrix(m=width, n=height, min_limit=100, max_limit=999)
    print("Bubble sort")
    if verbose:
        print("Before:")
        for x in range(4):
            print(f'  {matrix[x]}')
    bubble_sort_time = sort_matrix_bubble_sort(matrix)
    if verbose:
        print("After:")
        for x in range(4):
            print(f'  {matrix[x]}')
        print('\n')

    # Shell sort
    matrix = make_matrix(m=width, n=height, min_limit=100, max_limit=999)
    print("Shell sort")
    if verbose:
        print("Before:")
        for x in range(4):
            print(f'  {matrix[x]}')
    shell_sort_time = sort_matrix_shell_sort(matrix)
    if verbose:
        print("After:")
        for x in range(4):
            print(f'  {matrix[x]}')
        print('\n')

    # Heap sort
    matrix = make_matrix(m=width, n=height, min_limit=100, max_limit=999)
    print("Heap sort")
    if verbose:
        print("Before:")
        for x in range(4):
            print(f'  {matrix[x]}')
    heap_sort_time = sort_matrix_heap_sort(matrix)
    if verbose:
        print("After:")
        for x in range(4):
            print(f'  {matrix[x]}')
        print('\n')

    # Quick sort
    matrix = make_matrix(m=width, n=height, min_limit=100, max_limit=999)
    print("Quick sort")
    if verbose:
        print("Before:")
        for x in range(4):
            print(f'  {matrix[x]}')
    quick_sort_time = sort_matrix_quick_sort(matrix)
    if verbose:
        print("After:")
        for x in range(4):
            print(f'  {matrix[x]}')
        print('\n')

    # Standard sort
    matrix = make_matrix(m=width, n=height, min_limit=100, max_limit=999)
    print("Standard sort")
    if verbose:
        print("Before:")
        for x in range(4):
            print(f'  {matrix[x]}')
    std_sort_time = sort_matrix_std_sort(matrix)
    if verbose:
        print("After:")
        for x in range(4):
            print(f'  {matrix[x]}')
        print('\n')

    def beauty_time(nanoseconds: int) -> str:
        return "{0:0.2f}".format(nanoseconds / (10 ** 6))

    # Results
    print("\nElapsed time:")
    print(f'  Selection sort: {beauty_time(selection_sort_time)} ms')
    print(f'  Insertion sort: {beauty_time(insertion_sort_time)} ms')
    print(f'  Bubble sort:    {beauty_time(bubble_sort_time)} ms')
    print(f'  Shell sort:     {beauty_time(shell_sort_time)} ms')
    print(f'  Heap sort:      {beauty_time(heap_sort_time)} ms')
    print(f'  Quick sort:     {beauty_time(quick_sort_time)} ms')
    print(f'  Standard sort:  {beauty_time(std_sort_time)} ms')


def make_matrix(m: int = 50, n: int = 50, min_limit: int = -250, max_limit: int = 1017) -> list[list[int]]:
    return [[random.randint(min_limit, max_limit) for _ in range(m)] for _ in range(n)]


def sort_matrix_selection_sort(matrix: list[list[int]]) -> int:
    start = time.time_ns()
    for linear in matrix:
        for i in range(len(linear) - 1):
            min_index = i
            for j in range(i + 1, len(linear)):
                if linear[j] < linear[min_index]:
                    min_index = j
            linear[i], linear[min_index] = linear[min_index], linear[i]
    end = time.time_ns()

    return end - start


def sort_matrix_insertion_sort(matrix: list[list[int]]) -> int:
    start = time.time_ns()
    for linear in matrix:
        for i in range(1, len(linear)):
            for j in range(i, 0, -1):
                if linear[j - 1] > linear[j]:
                    linear[j - 1], linear[j] = linear[j], linear[j - 1]
                else:
                    break
    end = time.time_ns()

    return end - start


def sort_matrix_bubble_sort(matrix: list[list[int]]) -> int:
    start = time.time_ns()
    for linear in matrix:
        for i in range(len(linear)):
            for j in range(len(linear) - 1, i, -1):
                if linear[j - 1] > linear[j]:
                    linear[j - 1], linear[j] = linear[j], linear[j - 1]
    end = time.time_ns()

    return end - start


def sort_matrix_shell_sort(matrix: list[list[int]]) -> int:
    start = time.time_ns()
    for array in matrix:
        middle = len(array) // 2
        while middle > 0:
            for i in range(middle, len(array)):
                temp = array[i]
                j = i
                while j >= middle and array[j - middle] > temp:
                    array[j] = array[j - middle]
                    j -= middle

                array[j] = temp
            middle //= 2
    end = time.time_ns()

    return end - start


def sort_matrix_heap_sort(matrix: list[list[int]]) -> int:
    start = time.time_ns()
    for array in matrix:
        def foo(parent, limit):
            item = array[parent]
            while True:
                child = (parent * 2) + 1
                if child >= limit:
                    break
                if child + 1 < limit and array[child] < array[child + 1]:  # !
                    child += 1
                if item < array[child]:  # !
                    array[parent] = array[child]
                    parent = child
                else:
                    break
            array[parent] = item

        length = len(array)
        for i in range((length // 2) - 1, -1, -1):
            foo(i, length)
        for i in range(length - 1, 0, -1):
            array[0], array[i] = array[i], array[0]
            foo(0, i)
    end = time.time_ns()

    return end - start


def sort_matrix_quick_sort(matrix: list[list[int]]) -> int:
    def partition(arr, low, high):
        i = low - 1
        pivot = arr[high]
        for j in range(low, high):
            if arr[j] <= pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]

        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1

    def quick_sort(arr, low, high):
        if len(arr) == 1:
            return arr
        if low < high:
            pi = partition(arr, low, high)
            quick_sort(arr, low, pi - 1)
            quick_sort(arr, pi + 1, high)

    start = time.time_ns()
    for array in matrix:
        quick_sort(array, 0, len(array) - 1)
    end = time.time_ns()

    return end - start


def sort_matrix_std_sort(matrix: list[list[int]]) -> int:
    start = time.time_ns()
    for array in matrix:
        array.sort()
    end = time.time_ns()

    return end - start


def run():
    task_01()
    task_02()
