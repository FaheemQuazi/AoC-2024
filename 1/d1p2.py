from scanf import scanf

distA = []
distB = []

# Load FIles
with open("input.txt") as f:
    for l in f.readlines():
        data = scanf("%d   %d", l)
        distA.append(data[0])
        distB.append(data[1])

sims = []
for i in range(0, len(distA)):
    sims.append(distA[i] * distB.count(distA[i]))

total = 0
for i in sims:
    total += i
print(total)