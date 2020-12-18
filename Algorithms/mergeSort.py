import random
import numpy
import matplotlib.pyplot as plt

def merge(a,b):
    # O(min(len(a),len(b)))
    # O(n)
    new = []
    inA = 0
    inB = 0

    while(inA<len(a) and inB<len(b)):
        if a[inA] < b[inB]:
            new.append(a[inA])
            inA+=1
        else:
            new.append(b[inB])
            inB+=1
    while(inA<len(a)):
        new.append(a[inA])
        inA+=1
    while(inB<len(b)):
        new.append(b[inB])
        inB+=1
    return new

def sort(array):
    print(array)
    if len(array)<2:
        return array
    elif len(array) <= 2:
        if array[0] > array[1]:
            tmp = array[0]
            array[0]=array[1]
            array[1] = tmp
        return array
    elif len(array) > 2:
        srt = merge(sort(array[0:int(len(array)/2)]),sort(array[int(len(array)/2):]))
        return srt


     
if __name__ == "__main__":
    a = [random.randrange(1, 10000, 1) for i in range(15)] 
    a = sort(a)
    print('\n',a)
