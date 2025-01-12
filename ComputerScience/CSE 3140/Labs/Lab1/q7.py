import sys
import random
import hashlib
import os
import binascii
import math
from math import floor
def hash_it(passwd):
    m = hashlib.sha256()
    m.update(bytes(passwd, 'utf-8'))
    hash = m.hexdigest()
    return hash
def make_word(word):
    numberset = ['0','1','2','3','4','5','6','7','8','9']
    symbolset=['&', '=', '!', '?', '.', '~', '*', '^', '#', '$']
    l = []
    n = len(word)
    for i in range(n+1):
        for number in numberset:
            new = word[:i] + number + word[i:]
            s = len(new)
            for j in range(s+1):
                for symbol in symbolset:
                    final = new[:j] + symbol + new[j:]
                    l.append(final)
                    
    return l

if __name__ == "__main__":
    f = open("hash_to_crack2","r")
    dictionary_file = open("dictionary","r")
    dictionary = dictionary_file.readlines()
    hashed = f.readlines()[0].strip()
    guess = 1
    for word in dictionary:
        word = word.strip()
        l = make_word(word)
        for new in l:
            if hash_it(new) == hashed:
                print("guesses: ", guess)
                print("password: ",new)
            guess += 1

