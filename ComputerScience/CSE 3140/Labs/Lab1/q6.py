import GuardLogin5
import subprocess
import random
import hashlib
import os
import binascii
from base64 import b64encode
if __name__ == "__main__":
    leaked_file = open("LeakedPasswordsQ6","r")
    dictionary_file = open("dictionary","r")
    leaked = leaked_file.readlines()
    dictionary = dictionary_file.readlines()
    guess = 1
    for line in leaked:
        arr = line.split(",")
        user,hashed,salt = arr[0].strip(),arr[1].strip(),arr[2].strip()
        salt_val = binascii.unhexlify(salt[2:len(salt)-1])
        for word in dictionary:
            word = word.strip()
            hash1 = binascii.hexlify(hashlib.pbkdf2_hmac('sha256', bytes(word,'utf-8'), salt_val, 100))
            hash1 = str(hash1)
            if(hash1== hashed):
                print("user name: ",user)
                print("password: ",word)
                print("number of guesses: ",guess)

            guess += 1

