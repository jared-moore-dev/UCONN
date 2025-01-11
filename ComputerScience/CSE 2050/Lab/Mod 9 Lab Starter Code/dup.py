

def find_duplicate(L):
    left, right = 0, len(L) -1
    if right - left < 2:
	    return L[left]

    median = (left + right) // 2
	
    if median - left != L[median] - L[left]: 
        return find_duplicate(L[:median])
    if right - median != L[right] - L[median]: 
        return find_duplicate(L[median:])
    return None

assert find_duplicate([1, 2, 2, 3, 4, 5]) == 2