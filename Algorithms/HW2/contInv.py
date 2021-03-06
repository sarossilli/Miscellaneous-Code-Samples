
#Samuel Rossilli
#CS 4720:003
#Homework 2
#Count inversions is an implementaion on the countInv methods in the book
#Displays the number of inversions in an array to be sorted
#Using Python 3

import random #using for building test cases

def countInvBruteForce(array):
    n = len(array)
    numInv = 0
    for i in range(n):
        for j in range(i+1,n):
            if array[i] > array[j]:
                numInv+=1
    return numInv

def countInv(array):
    n = len(array)
    if n == 0 or n ==1:
        return array,0
    else:
        c,left = countInv(array[:int(n/2)])
        d,right = countInv(array[int(n/2):])
        b, split = countSplit(c,d)
        return b, left+right+split

def countSplit(c,d):
    # Using a for loop with k cuased an index out of bounds error, since i would often reach len(c) and c[i] woud result in an error
    # This algorithm works the same as the one in the book (3.2) except using while loops to prevent index errors
    # The while loop acts as the for loop in the book
    splitInv=0
    b = []
    i = 0
    j = 0

    while( i < len(c) and j < len(d)): #Check to see if within bounds
        if c[i] <= d[j]:
            b.append(c[i])
            i+=1
        else:
            b.append(d[j])
            j+=1
            splitInv = splitInv + (len(c) - (i))

    while(i<len(c)): #Check if there are still elements in c
        b.append(c[i])
        i+=1

    while(j<len(d)): #Check for elements still in d
        b.append(d[j])
        j+=1
        splitInv = splitInv + (len(c) - i) #add remaining elements in d to inversion count

    return b,splitInv


# Function to test numTest number of n elemet arrays.
# Compares the value of brute force and high level algorithms to detect any errors
# Should print error of zero
def testLots(n,numTest):
    diff = 0
    for k in range(numTest):
        a = [random.randint(0,n*n) for k in range(n)] #Build random array
        diff += abs(countInv(a[:])[1] - countInvBruteForce(a[:]))
    print("Error of:",diff)

#Function to test one dataset array
def testOne(file):
    f = open(file,'r')
    a = [int(a) for a in f]
    f.close()
    # Both functions should output the same number
    print("\nTesting algorithm on set array of size:", len(a),"\n----------------------------------------------")
    print("First 10 elements: ", a[:10])
    print(f"High-Level Method Returned {countInv(a)[1]} Inversions",)

def testBruteForce(file):
    f = open(file,'r')
    a = [int(a) for a in f]
    f.close()
    print("\nTesting algorithm on set array of size:", len(a),"\n----------------------------------------------")
    print(f"Brute Force Method Returned {countInvBruteForce(a)} Inversions",)



#Put your own test file here:
print("Testing on test set from website")
file = "/home/sarossilli/Dev/Algos/HW2/test2.txt"
testOne(file)

#Put your own test file here:
print("\nTesting on test challenge from website")
file = "/home/sarossilli/Dev/Algos/HW2/test.txt"
testOne(file)