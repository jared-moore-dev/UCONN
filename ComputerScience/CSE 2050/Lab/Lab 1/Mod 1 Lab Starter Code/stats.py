import sys
def compute_mean(the_list):
    total = 0
    for item in the_list:
        total = total + item
    if len(the_list) == 0:
        return 0
    else:
        return total / len(the_list)

def compute_median(the_list):
    l = len(the_list)
    s = sorted(the_list)
    index = int((l - 1) / 2)
    return float(s[index])

def compute_mode(the_list):
    a = set(the_list)
    if list(a) == the_list:
        return sorted(the_list)[0]
    else:
         return max(the_list, key = the_list.count)
         
if __name__ == '__main__':
    numbers = []
    for line in sys.stdin:     # iterate over input line by line
        if line == "done":
            break
        for n in line.split():
            try: # split the line at standard whitespace characters
                numbers.append(float(n))
            except ValueError:
                    pass
                  

    print(compute_mean(numbers))
    print(compute_median(numbers))
    print(compute_mode(numbers))