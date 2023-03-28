import time


def reconstruct(boxes):
    # print(boxes)
    output = []
    for j in range(3):
        for i in range(len(boxes[0])):
            hold = ""
            for k in range(3):
                hold += boxes[3 * j + k][i]
            output.append(hold)
    return output


def draw_fractal(depth, base):
    if depth == 0:
        return base
    else:
        output = []
        for i in range(9):
            if i == 4:
                output.append(draw_fractal(depth - 1, " "))
            else:
                output.append(draw_fractal(depth - 1, base))
    return reconstruct(output)


def main():
    def beauty_time(nanoseconds: int) -> str:
        return "{0:0.2f}".format(nanoseconds / (10 ** 6))

    n = 0
    should_print = True

    start = time.time_ns()
    fractal = draw_fractal(n, "■")
    end = time.time_ns()

    if should_print:
        output = ""
        for i in fractal:
            for j in i:
                output += "%s " % j
            output += "\n"
        print(output)

    print(f"Elapsed time: {beauty_time(end - start)} ms")


def run():
    main()
