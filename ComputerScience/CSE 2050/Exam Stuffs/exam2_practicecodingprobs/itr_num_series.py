def f(n):
    sum = 1
    for i in range(4, n+1):
        sum += (n-1) * (n-2) / 2
    return sum