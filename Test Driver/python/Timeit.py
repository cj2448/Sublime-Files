def f1():
    for n in range(100):
        pass


def f2():
    n = 0
    while n < 100:
        n += 1


if __name__ == "__main__":
    from timeit import timeit
    print(timeit(f1))  # timeit.timeit(f1, number = 10000) default is 1000000
    print(timeit(f2))  # timeit.timeit(f1, number = 10000)
