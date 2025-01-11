def find_duplicate(L, left = 0, right = None):
    if right == None: right = len(L) -1
    #calc mid point
    if len(L) > 1:
        mid = (left+right) // 2
    #check if midpoint is equivalent to mid + 1 point
        if (L[mid] == L[mid + 1]):
            return mid
    #do this reccourively on both sides of mid
        #count number of items and difference of first and last item in list
        lenleft = (mid-1) - left
        lenright = right - (mid+1)
        diffleft = L[mid-1] - L[left]
        diffright = L[right] - L[mid+1]

        if not(diffleft == lenleft - 1): 
            print("going left")
            find_duplicate(L, left, mid-1)
        if not(diffright == lenright - 1):
            print("going right") 
            find_duplicate(L, mid+1, right)
    #eventually in a 2 item list, the alg will return item
    #or if lucky will find it accidentally ahead of time
L = [1, 2, 2, 3, 4, 5, 6]
find_duplicate(L)
