import GuardLogin3
import subprocess
def make_word(s, symbols):
    n = len(s)
    final = []


    for symbol in symbols: # for each symbol
        for i in range(n+1): # iterate through the string
            word = ""
            temp = [char for char in s]
            temp.insert(i,symbol)
            for char in temp:
                word += char
            final.append(word)

    return final
if __name__ == "__main__":
    f = open("dictionary","r")
    data = f.readlines()
    symbols = ['!','@','#']
    guess = 0
    for word in data:
        word = word.strip()
        arr = make_word(word,symbols)
        for i in range(len(arr)):
            p = subprocess.Popen(["python3","GuardLogin3.pyc","Al",arr[i]],stdout=subprocess.PIPE,universal_newlines=True)
            out = p.communicate()
            guess += 1
            if(out[0].strip() == "Incorrect Login!"):
                pass
            else:
                print("number of guesses",guess)
                print(out[0].strip())
                print("password: ", arr[i])
                exit()


