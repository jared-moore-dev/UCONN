import GuardLogin5
import subprocess
import random
import hashlib
import os
import binascii
        
if __name__ == "__main__":
    leaked_file = open("LeakedPasswordsQ5","r")
    dictionary_file = open("dictionary","r")
    leaked = leaked_file.readlines()
    dictionary = dictionary_file.readlines()
    # Creates a new file called HashedPasswordsQ5.txt containing usernames and hashes
    f = open("HashedPasswordsQ5.txt", "w+")
    hash_arr = []
    for line in dictionary:
        #hash each word
        m = hashlib.sha256()
        m.update(bytes(line.strip(), 'utf-8'))
        hashed = m.hexdigest()
        hash_arr.append((line.strip(),hashed.strip()))
    #exit()
    final = []
    for line in leaked:
        arr = line.split(",")
        user,hashed = arr[0].strip(),arr[1].strip()
        for tup in hash_arr:
            if hashed == tup[1]:
                password = tup[0]
                final.append((user,password))
    for item in final:
        f.write(item[0] + "," + item[1] + "\n")

    f.close()

