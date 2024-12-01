from scanf import scanf
import numpy

distA = []
distB = []

# Load FIles
with open("input.txt") as f:
    for l in f.readlines():
        data = scanf("%d   %d", l)
        distA.append(data[0])
        distB.append(data[1])

sA = numpy.sort(distA)
sB = numpy.sort(distB)

print(min(distA), sA.shape)
print(min(distB), sB.shape)

dists = []
for i in range(0, sA.shape[0]):
    dists.append(max(sA[i], sB[i]) - min(sA[i], sB[i]))

total = 0
for i in dists:
    total += i
print(total)