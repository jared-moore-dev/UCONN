def champaign_sort(L):
    n = len(L)
    #state var, True = Function ran, False = Sorted
    state = True
    right = n - 1
    left = 0
    
    while (state==True):
        #change state
        state = False
        #run bubble sort from outside in
        for i in range (left, right):
            if (L[i] > L[i+1]):
                #bubble pass through
                L[i], L[i+1] = L[i+1], L[i]
                #change state
                state = True
        #check state to see if list is sorted
        if (state==False):
            break
        #if bubble sort ran, change state
        state = False
        #decrement right, since rabbits pulled to right
        right = right - 1
        #pass right to left bubble 
        for i in range(right-1, left-1, -1):
            if (L[i] > L[i+1]):
                L[i], L[i+1] = L[i+1], L[i]
                #change state
                state = True
        # increment left since turtles brought back
        left = left + 1

# l = [10, 17, 9, 10, 11, 2, 1]
# champaign_sort(l)
# for i in range(len(l)):
#     print(l[i])

def insertion_sort(L):
    n = len(L)
    for j in range(n):
        for i in range(n-1-j, n-1):
            if L[i] > L[i+1]:
                L[i], L[i+1] = L[i+1], L[i]
            else: break

def binary_search(L, val, left, right):
    if right - left <= 1:
        if val < L[left]:
            return left -1
        else:
            return left
    mid = (left + right) // 2
    if L[mid] < val:
        return binary_search(L, val, mid, right)
    elif L[mid] > val:
        return binary_search(L, val, left, mid)
    else:
        return mid
    

    

def opt_insertion_sort(L):
    n = len(L)
    for i in range(1,n):
        temp = L[i]
        index = binary_search(L, temp, 0, i) + 1
        for j in range(i, index, -1):
            L[j] = L[j - 1]
        L[index] = temp

l2 = [4, 17, 21, 5, 3, 7, 9, 10, 14]
opt_insertion_sort(l2)
for i in range(len(l2)):
    print(l2[i])
