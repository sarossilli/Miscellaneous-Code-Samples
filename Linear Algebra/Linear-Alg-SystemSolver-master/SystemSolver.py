# Sam Rossilli
# CS 2300:001
# Assigment 3
# Due 3/20/20
# 1. Reads in a matrix A and vector B from files
# 2. Finds an inverse of A (if possible)
# 3. Finds a solution by inverse method for the system
#       -If no inverse was found, determines if there are infinity or no solutions.
# 4. Repeats 5 times, once for each system provided
import math


def readMatrix(fileName):
    # Function to read in matrix values
    with open(fileName) as file:
            # Read in whole file and split into array
        variables = file.read().split()
        dim = int(math.sqrt(len(variables)))
        matrix = [[float(variables[col*dim + row])
                   for row in range(dim)] for col in range(dim)]
    return matrix


def readVector(fileName):
    # Function to read in vector (b) values
    with open(fileName) as file:
            # Read in whole file and split into array
        variables = file.read().split()
        dim = len(variables)
        vector = [[float(variables[row])] for row in range(dim)]
    return vector


def inverseMatrix(matrix):
    # Function to invert a 2x2 matrix
    matrixInverse = [[]]
    determ = det(matrix)
    if(determ != 0):
        multFactor = 1/determ
        matrixInverse = [[multFactor*matrix[1][1], -multFactor*matrix[0]
                          [1]], [-multFactor*matrix[1][0], multFactor*matrix[0][0]]]
    return matrixInverse


def det(matrix):
    # Function to find the determitate of a matrix
    dim = len(matrix)-1
    diag1 = 1
    diag2 = 1
    for i in range(0, dim+1):
        diag1 *= matrix[i][i]
        diag2 *= matrix[i][dim-i]
    determ = diag1-diag2
    return round(determ, 3)


def solve(inverse, b):
    # Function to solve a system with a given inverse matrix and b

    if inverse != [[]]:
        solution = [(inverse[rows][0] * b[0][0]) +
                    (inverse[rows][1] * b[1][0]) for rows in range(2)]
    else:
        # If no inverse found:
        solution = ""
    return solution


def appendB(a, b, col):
    # Fucntion that replaces col with b vector
    aprime = a.copy()
    aprime[0][col] = b[0][0]
    aprime[1][col] = b[1][0]
    return aprime


print("Sam Rossilli Assignment 3")
for i in range(5):
    b = readVector('b' + str(i+1) + '.txt')
    a = readMatrix('A' + str(i+1) + '.txt')

    solution = solve(inverseMatrix(a), b)
    print("\n\nSOLUTION TO FILE " + str(i+1) +
          "\n----------------------------------")

    # If no solution found
    if solution == "":
        # Check if b is on both A lines
        if (det(appendB(a, b, 0)) == 0) and (det(appendB(a, b, 1)) == 0):
            print("Infinity solutions")
            a = readMatrix('A' + str(i+1) + '.txt')
            x2 = (b[0][0]-a[0][0])/(a[0][1])
            print("x = [1," + str(x2) + "]")
        else:
            print("Zero Solutions")
    else:
        print(solution)
