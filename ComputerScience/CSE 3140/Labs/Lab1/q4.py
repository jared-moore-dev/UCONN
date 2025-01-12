import GuardLogin4
import subprocess
if __name__ == "__main__":
    f = open("LeakedPasswordsQ4","r")
    data = f.readlines()
    guess = 0
    for word in data:
        arr = word.split(",")
        user,password = arr[0].strip(),arr[1].strip()
        names = ["Charles","Ted","Tom","Bonnie","Andrew","Tim"]
        for name in names:
            if name in user or name.lower() in user:
                p = subprocess.Popen(["python3","GuardLogin4.pyc",user,password],stdout=subprocess.PIPE,universal_newlines=True)
                out = p.communicate()
                guess += 1
                if(out[0].strip() == "Incorrect Login!"):
                    pass
                else:
                    print("number of guesses",guess)
                    print(out[0].strip())
                    print("password: ", password)
                    exit()

