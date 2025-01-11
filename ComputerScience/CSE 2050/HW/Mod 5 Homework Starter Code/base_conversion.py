# Convert a number to a given base (integer less than 10)
# Return the answer as a string
# Recursive implementation required
def convert_to_base(number, base):
    #basecase
    if number == 0:
        return ""
    if number <= 1:
        return str(number)
    else:
        return str(convert_to_base((number // base), base)) + str(number % base)



if __name__ == '__main__':
    print(convert_to_base(15895, 7))
    assert(convert_to_base(15895, 7) == '64225')
    assert(convert_to_base(95736, 8) == '272770')
