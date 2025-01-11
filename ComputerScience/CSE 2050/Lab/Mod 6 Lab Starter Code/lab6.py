

    # iterator through the list
    # for every item, check if [item-1] > or <
    # if item is greater, return item - 1
    # if item is less keep going


# def help_find_min(L, m=1, left=0, right=None):
#     if right is None:
#         right = len(L)
#     if right - left == 0:
#         return "failed out"
#     if right - left == 1:
#         return L[left]
#     median = (right + left) // 2
#     if L[median - 1 - m] > L[median] and L[median + m] > L[median]:
#         return help_find_min(L, m-1, median - 1 - m, median + m)
#     if L[median - 1 - m] > L[median + m]:
#         return help_find_min(L, m, median, right)
#     if L[median - 1 - m] < L[median + m]:
#         return help_find_min(L, m, left, median)


# l1 = [10, 8, 4, 4, 3, 5]
# l2 = [17, 14, 13, 12, 8, 7, 9, 10, 15, 16]

# def bs(L, item):
#     left, right = 0, len(L)
#     while right - left > 1:
#         median = (right + left) // 2
#         if item < L[median]:
#             right = median
#         else:
#             left = median
#     return right > left and L[left] == item

def find_min(L, m = 1):
    left, right = 0, len(L)
    s = m
    while right - left > 1:
        median = (right+left) // 2
        if L[median - s] < L[median]:
            right = median
        else:
            left = median
    if right > left:
        return L[left]
    else:
        return L[right]

# def find_min(L, m=1):
#     left = 0
#     right = len(L)

#     if len(L) <= m+4: return min(L)
#     s = 2 + m + (m%2)
#     while right - left > s + 4:
#         r = (right+left+s) // 2
#         l = (right+left-s) // 2
#         fm = min(L[l:r])
#         if fm == L[l]: right = r
#         else: left = L
#     return min(L[left:right])


# min(l2, 1)

# help_find_min(l2, 2)
# def min(L):
#     left, right = 0
#     while left < right:
#         mid = (left+right) // 2
#         if a[mid + m] < a[mid + m + 1]:
#             right = mid
#         else:
#             left = mid + m + 1
#         return left


# min(tl)


