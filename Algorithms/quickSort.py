import random
def swap(array,n,k):
    temp = array[n]
    array[n] = array[k]
    array[k] = temp

def sort(array):
    if(len(array) <=1):
        return array

    i = choosePivot(array)
    swap(array,0,i)
    j = partition(array)
    
    array[:] = sort(array[:j]) + sort(array[j:])
    return array

def partition(array):
    pivotValue = array[0]
    i = 1
    for j in range(1,len(array)):
        if array[j] <= pivotValue:
            swap(array,j,i)
            i+=1
    swap(array,0,i-1)
    return i-1


def choosePivot(array):
    return int(len(array)/2)

if __name__ == "__main__":
    a = [random.randrange(1, 1000000, 1) for i in range(500)] 
    a = sort(a)
    print('\n',a)
