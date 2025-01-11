import random


def find_missing_1(L):
    n = len(L)
    for i in range(n+1):
        if i not in L:
            return i


def find_missing_2(L):
    if not L:
        return 0
    n = len(L)
    L.sort()
    for i in range(0,n):
        if L[i] != i:
            return i
    return n


def find_missing_3(L):
    n = len(L)
    lsum = sum(L)
    nsum = (n*(n+1))/2
    return nsum - lsum


def find_missing_4(L):
    S = set(L)
    n = len(L)
    for i in range(n+1):
        if i not in S:
            return i


if __name__ == '__main__':
    # Create a randomized permutation with one element missing
    N = 100
    my_list = list(range(N + 1))
    random.seed()
    random.shuffle(my_list)
    my_list.pop()

    # Print the output
    testlist = [0, 1, 2, 4]
    testlist0 = [0, 1, 2, 3]
    testlistnone = []
    print(find_missing_1(my_list))
    print(find_missing_2(my_list))
    print(find_missing_3(my_list))
    print(find_missing_4(my_list))
    print(find_missing_2(testlist))
    print(find_missing_2(testlist0))
    print(find_missing_2(testlistnone))

