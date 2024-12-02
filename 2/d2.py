from scanf import scanf
import numpy

floors = []

# Load Files
with open("input.txt") as f:
    for l in f.readlines():
        data = []
        for digit in l.split(" "):
            data.append(scanf("%d", digit)[0])
        floors.append(data)

safe = []

for floor in floors:
    lastLevel = -99
    count = 0
    direction = 0
    checkfailed = False
    for currentLevel in floor:
        if count == 0:
            lastLevel = currentLevel
            count = count + 1
        else:
            if currentLevel == lastLevel:
                checkfailed = True
                break
            if direction == 0:
                if currentLevel > lastLevel:
                    direction = 1
                else:
                    direction = -1
            else:
                if currentLevel > lastLevel and direction == -1:
                    checkfailed = True
                    break
                elif currentLevel < lastLevel and direction == 1:
                    checkfailed = True
                    break
            if direction == 1:
                diff = currentLevel - lastLevel
                if diff >=1 and diff <=3:
                    lastLevel = currentLevel
                else:
                    checkfailed = True
                    break
            elif direction == -1:
                diff = lastLevel - currentLevel
                if diff >=1 and diff <=3:
                    lastLevel = currentLevel
                else:
                    checkfailed = True
                    break
            count = count + 1
            pass
        pass
    safe.append(not(checkfailed))

print(safe.count(True))
                

