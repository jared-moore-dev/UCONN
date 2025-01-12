import GuardLogin2
import subprocess
f = open("dictionary","r")

data = f.readlines()
#
guess = 0
for word in data:
    word = word.strip()
    p = subprocess.Popen(["python3","GuardLogin2.pyc","Al",word],stdout=subprocess.PIPE,universal_newlines=True)
    out = p.communicate()
    guess += 1
    if(out[0].strip() == "Incorrect Login!"):
        pass
    else:
        print(out[0].strip())
        print("password: ", word)
        print("number of guesses: ",guess)
        break;


