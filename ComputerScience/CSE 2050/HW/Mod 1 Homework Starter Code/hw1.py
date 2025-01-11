import CustomMath as cmth 
import math as mth 

def f_dif(f1, f2, v=0.0):
    dif = f1(v)-f2(v)
    return dif

f_dif(mth.floor, cmth.floor, 16.75)