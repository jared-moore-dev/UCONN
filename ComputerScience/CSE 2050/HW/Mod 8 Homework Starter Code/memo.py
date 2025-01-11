memocache = {}
def Fib(n):
    if n in memocache:
        return memocache[n]
    if n == 1:
        return 1
    elif n == 2:
        return 1
    elif n > 2:
        val = Fib(n-1) + Fib(n-2)
    memocache[n] = val
    return val

print(Fib(25))