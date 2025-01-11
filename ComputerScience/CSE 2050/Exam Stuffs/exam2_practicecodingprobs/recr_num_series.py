def f(n):
    if n == 3: return 1
    return f(n-1) + (n-1)*(n-2)/2