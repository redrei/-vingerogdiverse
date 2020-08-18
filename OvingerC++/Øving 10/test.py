import numpy  as np
import random

def randArr(size):
    arrayout = np.empty((size,size))
    for i in range(size):
        column = []
        sum = 0
        for j in range(size):
            num = random.randint(0,9)
            column.append(num)
            sum += num
        
        for j in range(len(column)):
            arrayout[j][i] = column[j]/ sum
    return arrayout


def progress(arrayin,vector):
    outvector = []
    for i in arrayin:
        sum = 0
        for j in range(len(i)):
            sum += i[j]*vector[j]
        outvector.append(sum)
    return outvector

invector = [20,30,50]
invector2 = [40,50,10]
matrix = randArr(3)
print(matrix)
for i in range(100):
    invector = progress(matrix,invector)


print(invector)

for i in range(100):
    invector2 = progress(matrix,invector)


print(invector2)

def findsubset(set,subset):
    


