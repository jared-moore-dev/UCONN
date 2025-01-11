#Variables

pi = 3.14
e = 2.72

# def sqrt(num):
#     try:
#         root = num ** .5
#         return root
#     except TypeError:
#         return('{} is not a number'.format(num))

def sqrt(num):
    if isinstance(num, int):
        return (num ** .5)
    elif isinstance(num, float):
        return (num ** .5)
    else: 
        return('{} is not a number'.format(num))

def floor(num):
    if isinstance(num, int):
        return ('{} is the floor'.format(num))
    elif isinstance(num, float):
        return num//1
    else:
        return ('{} is not a number'.format(num))
def ceil(num):
    if isinstance(num, int):
        return ('{} is the ceil'.format(num))
    elif isinstance(num, float):
        return -(-num//1)
    else:
        return ('{} is not a number'.format(num))


if __name__ == '__main__':
    print("CustomMath is being executed directly")
else:
    print("CustomMath has been imported")

