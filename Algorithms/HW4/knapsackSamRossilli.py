# Knapsack Problem
# Samuel Rossilli

def knapsack(itemSizes,itemValues,cap):
    numItems = len(itemSizes)

    # Initialize array entries as zero
    a = [[0 for x in range(numItems)] for y in range(cap+1)] 

    for i in range(1,numItems):
        for c in range(0,cap+1):
            if itemSizes[i] > c:
                a[c][i] = a[c][i-1]
            else:
                a[c][i] = max(a[c][i-1], a[c-itemSizes[i]][i-1] + itemValues[i])
    return a

def reconstruct(a,itemValues,itemSizes,cap):
    n = len(itemValues)
    S = []
    c = cap
    for i in range(n-1,1,-1):
        if itemSizes[i]<= c and a[c-itemSizes[i]][i-1] + itemValues[i] >= a[c][i-1]:
            S.append(i)
            c = c-itemSizes[i]
    return S


values = [0,1,2,3,4,5]
sizes = [0,1,3,2,5,4]
C = 9

a = knapsack(sizes,values,C)
res = reconstruct(a,values,sizes,C)

#Show Result
print("RESULTING MATRIX:")
print("===============================")

#flip and print array
print('\n'.join([''.join(['{:4}'.format(item) for item in row]) 
      for row in a[::-1]]))
print("===============================")

print("MAX VALUE IS: " + str(a[C][len(values)-1]))
print("USING COINS: " + str(res))
