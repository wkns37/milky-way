class Stack:
    def __init__(self, initial=None):
        self.data = [] if not initial else initial

    def push(self, item):
        self.data.append(item)

    def pop(self):
        if self.size() < 1:
            return None
        return self.data.pop()

    def peek(self):
        if self.size() < 1:
            return None
        return self.data[-1]

    def size(self):
        return len(self.data)

    def empty(self):
        return self.size() == 0


class Deque:
    def __init__(self, initial=None):
        self.data = [] if not initial else initial

    def push(self, item):
        self.data.append(item)

    def push_left(self, item):
        self.data.insert(0, item)

    def peek(self):
        if self.size() < 1:
            return None
        return self.data[-1]

    def peek_left(self):
        if self.size() < 1:
            return None
        return self.data[0]

    def pop(self):
        if self.size() < 1:
            return None
        return self.data.pop()

    def pop_left(self):
        if len(self.data) < 1:
            return None
        return self.data.pop(0)

    def size(self):
        return len(self.data)

    def empty(self):
        return self.size() == 0


def task_01():
    # https://en.wikipedia.org/wiki/List_of_novels_considered_the_greatest
    print("=== TASK 1 ===")
    file = open('data/lab04_task01.txt')
    lines = file.readlines()

    d1 = Deque()
    d2 = Deque()
    current = d1
    foreign = d2
    for i in range(len(lines)):
        line = lines[i]
        if current.empty():
            current.push(line)
        elif line <= current.peek_left():
            current.push_left(line)
        elif line >= current.peek():
            current.push(line)
        else:
            while not current.empty():
                e = current.pop_left()
                if e < line:
                    foreign.push(e)
                else:
                    foreign.push(line)
                    foreign.push(e)
                    while not current.empty():
                        foreign.push(current.pop_left())
                    break

            current, foreign = foreign, current

    while not current.empty():
        print(f'{current.pop_left()}', end='')
    print()


def task_02():
    print("=== TASK 2 ===")
    file = open('data/lab04_task02.txt')
    encrypted = file.readline()
    d = Deque(list(encrypted))
    d.push_left(d.pop())
    d.push_left(d.pop())
    decrypted = ''.join(d.data)
    print(f'Encrypted: {encrypted}')
    print(f'Decrypted: {decrypted}')
    print()


def task_03():
    print("=== TASK 3 ===")

    def tower(n: int, source: tuple[Stack, str], destination: tuple[Stack, str], auxiliary: tuple[Stack, str]):
        if n == 1:
            destination[0].push(source[0].pop())
            print(f'Move {n} ring from \'{source[1]}\' to \'{destination[1]}\'')
            return

        tower(n - 1, source, auxiliary, destination)
        print(f'Move {n} ring from \'{source[1]}\' to \'{destination[1]}\'')
        destination[0].push(source[0].pop())
        tower(n - 1, auxiliary, destination, source)

    data = [3, 2, 1]
    a: tuple[Stack, str] = (Stack(data), 'A')
    b: tuple[Stack, str] = (Stack(), 'B')
    c: tuple[Stack, str] = (Stack(), 'C')
    tower(len(data), a, c, b)
    print()


def task_04():
    print("=== TASK 4 ===")
    file = open('data/lab04_task04.txt')
    s = file.readline()
    balanced = check_parens_balance(s)
    print(f'Input {s} is {"not " if not balanced else ""}balanced')
    print()


def check_parens_balance(s: str) -> bool:
    stack = Stack()
    for c in list(s):
        if c == '(':
            stack.push(1)
        elif c == ')':
            if stack.pop() is None:
                return False
    return stack.empty()


def task_05():
    print("=== TASK 5 ===")
    file = open('data/lab04_task05.txt')
    s = file.readline()
    balanced = check_brackets_balance(s)
    print(f'Input {s} is {"not " if not balanced else ""}balanced')
    print()


def check_brackets_balance(s: str) -> bool:
    stack = Stack()
    for c in list(s):
        if c == '[':
            stack.push(1)
        elif c == ']':
            if stack.pop() is None:
                return False
    return stack.empty()


def task_06():
    print("=== TASK 6 ===")
    file = open('data/lab04_task06.txt')
    result = extract_symbols(file.readline())
    while not result.empty():
        print(f'{result.pop()}')
    print()


def extract_symbols(s: str) -> Stack:
    s1 = Stack()  # Digits
    s2 = Stack()  # Alphas
    s3 = Stack()  # Etc.
    for c in list(s):
        c = str(c)
        if c.isdigit():
            s1.push(c)
        elif c.isalpha():
            s2.push(c)
        else:
            s3.push(c)

    result = Stack()
    while not s3.empty():
        result.push(s3.pop())
    while not s2.empty():
        result.push(s2.pop())
    while not s1.empty():
        result.push(s1.pop())

    return result


def task_07():
    print("=== TASK 7 ===")
    file = open('data/lab04_task07.txt')
    result = extract_numbers(file.readline())
    while not result.empty():
        print(f'{result.pop()}')
    print()


def extract_numbers(s: str) -> Stack:
    s1 = Stack()
    s2 = Stack()
    for x in s.split(' '):
        val = int(x)
        if val < 0:
            s1.push(val)
        else:
            s2.push(val)

    result = Stack()
    while not s2.empty():
        result.push(s2.pop())
    while not s1.empty():
        result.push(s1.pop())

    return result


def task_08():
    print("=== TASK 8 ===")
    file = open('data/lab04_task08.txt')
    s = Stack()
    for line in file.readlines():
        s.push(line)

    while not s.empty():
        print(f'{s.pop()}', end='')
    print()


def run():
    task_01()
    task_02()
    task_03()
    task_04()
    task_05()
    task_06()
    task_07()
    task_08()
