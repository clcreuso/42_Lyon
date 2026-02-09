import math
import sys

sys.path.append("..")
import random

from utils import *


### MATH

def borne01(f):
    def inner(*a, **kw):
        res = f(*a, **kw)
        if res >= 1:
            return 0.99999999
        if res <= 0:
            return 0.00000001
        return res

    return inner


@borne01
def sigmoide(z):
    return 1 / (1 + math.exp(-z))


def makePolynome(C):
    def calculPolynome(X):
        sm = 0
        for i in range(0, len(C)):
            sm += C[i] * X[i]
        return sm

    return calculPolynome


def makePredictFun(C):
    return lambda X: sigmoide(makePolynome(C)(X))


def makePartialDerivationJ(C):
    predictFun = makePredictFun(C)

    def calculDerivation(j, lX, ly):
        sm = 0
        for i in range(0, len(lX)):
            if None not in lX[i]:
                sm += (predictFun(lX[i]) - ly[i]) * lX[i][j]
        return sm / len(lX)

    return calculDerivation


def costFun(C, lX, ly):
    sm = 0
    predictFun = makePredictFun(C)
    for i in range(0, len(lX)):
        if None not in lX[i]:
            sm += ly[i] * math.log(predictFun(lX[i])) + (1 - ly[i]) * math.log(1 - predictFun(lX[i]))
    return - sm / len(lX)


###

def findC(lX, ly):
    lX = list(map(lambda X: X + [1], lX))

    lMax = [0 for _ in range(0, len(lX[0]))]

    for i in range(0, len(lX)):
        for j in range(0, len(lX[i])):
            if lX[i][j] is not None and lMax[j] < abs(lX[i][j]):
                lMax[j] = abs(lX[i][j])

    for i in range(0, len(lX)):
        for j in range(0, len(lX[i])):
            if lX[i][j] is not None:
                lX[i][j] = lX[i][j] / lMax[j]

    C = []
    for _ in range(0, len(lX[0])):
        C.append(0.5)

    for i in range(0, 250):
        dC = []
        partialDerivationJ = makePartialDerivationJ(C)
        for jC in range(0, len(C)):
            dC.append(partialDerivationJ(jC, lX, ly))
        for jC in range(0, len(C)):
            C[jC] -= dC[jC] * 1

    for i in range(0, len(C)):
        C[i] /= lMax[i]

    return C


def filterByIndex(l, ids):
    nw = []
    for i in ids:
        nw.append(l[i])
    return nw


def addValueByIndex(l, ids, mx):
    nw = []
    for i in range(0, mx):
        if i in ids:
            nw.append(l.pop(0))
        else:
            nw.append(0)
    return nw


def oneVSOneProportion(lX, ly):
    nwX = []
    nwy = []

    for i in range(0, len(lX)):
        if ly[i]:
            nwX.append(lX[i])
            nwy.append(ly[i])
            continue
        if len(nwX) >= len(lX) / 3:
            break
        nwX.append(lX[i])
        nwy.append(ly[i])

    return nwX, nwy


def findHouseC(lX, lHouse):
    SlytherinY = list(map(lambda e: 1 if e == "Slytherin" else 0, lHouse))
    SlytherinIndex = [1, 2, 3, 5, 6, 11]
    SlytherinlX = list(map(lambda l: filterByIndex(l, SlytherinIndex), lX))
    SlytherinlX, SlytherinY = oneVSOneProportion(SlytherinlX, SlytherinY)
    SlytherinC = findC(SlytherinlX, SlytherinY)
    SlytherinCBis = addValueByIndex(SlytherinC, SlytherinIndex, len(lX[0]))

    RavenclawY = list(map(lambda e: 1 if e == "Ravenclaw" else 0, lHouse))
    RavenclawIndex = [1, 2, 3, 4, 6]
    RavenclawlX = list(map(lambda l: filterByIndex(l, RavenclawIndex), lX))
    RavenclawlX, RavenclawY = oneVSOneProportion(RavenclawlX, RavenclawY)
    RavenclawC = findC(RavenclawlX, RavenclawY)
    RavenclawCBis = addValueByIndex(RavenclawC, RavenclawIndex, len(lX[0]))

    HufflepuffY = list(map(lambda e: 1 if e == "Hufflepuff" else 0, lHouse))
    HufflepuffIndex = [1, 2, 3, 6, 7, 8, 12]
    HufflepufflX = list(map(lambda l: filterByIndex(l, HufflepuffIndex), lX))
    HufflepufflX, HufflepuffY = oneVSOneProportion(HufflepufflX, HufflepuffY)
    HufflepuffC = findC(HufflepufflX, HufflepuffY)
    HufflepuffCBis = addValueByIndex(HufflepuffC, HufflepuffIndex, len(lX[0]))

    GryffindorY = list(map(lambda e: 1 if e == "Gryffindor" else 0, lHouse))
    GryffindorIndex = [1, 2, 3, 6, 11]
    GryffindorlX = list(map(lambda l: filterByIndex(l, GryffindorIndex), lX))
    GryffindorlX, GryffindorY = oneVSOneProportion(GryffindorlX, GryffindorY)
    GryffindorC = findC(GryffindorlX, GryffindorY)
    GryffindorCBis = addValueByIndex(GryffindorC, GryffindorIndex, len(lX[0]))

    return SlytherinCBis, RavenclawCBis, HufflepuffCBis, GryffindorCBis


def predict(SlytherinC, RavenclawC, HufflepuffC, GryffindorC, lX):
    SlytherinFun = makePredictFun(SlytherinC)
    RavenclawFun = makePredictFun(RavenclawC)
    HufflepuffFun = makePredictFun(HufflepuffC)
    GryffindorFun = makePredictFun(GryffindorC)

    lSlytherinRes = []
    lRavenclawRes = []
    lHufflepuffRes = []
    lGryffindorRes = []
    for i in range(0, len(lX)):
        if None in lX[i]:
            lSlytherinRes.append(None)
            lRavenclawRes.append(None)
            lHufflepuffRes.append(None)
            lGryffindorRes.append(None)
            continue
        lSlytherinRes.append(SlytherinFun(lX[i] + [1]))
        lRavenclawRes.append(RavenclawFun(lX[i] + [1]))
        lHufflepuffRes.append(HufflepuffFun(lX[i] + [1]))
        lGryffindorRes.append(GryffindorFun(lX[i] + [1]))

    housePredict = []
    for i in range(0, len(lX)):
        if None in [lSlytherinRes[i], lRavenclawRes[i], lHufflepuffRes[i], lGryffindorRes[i]]:
            housePredict.append(None)
            continue
        mx = max(lSlytherinRes[i], lRavenclawRes[i], lHufflepuffRes[i], lGryffindorRes[i])
        if mx == lSlytherinRes[i]:
            housePredict.append("Slytherin")
        elif mx == lRavenclawRes[i]:
            housePredict.append("Ravenclaw")
        elif mx == lHufflepuffRes[i]:
            housePredict.append("Hufflepuff")
        else:
            housePredict.append("Gryffindor")
    return housePredict


def test(SlytherinC, RavenclawC, HufflepuffC, GryffindorC, lX, houses):
    housePredict = predict(SlytherinC, RavenclawC, HufflepuffC, GryffindorC, lX)
    nbGood = 0
    nbNotNone = 0
    for i in range(0, len(houses)):
        if houses[i] == housePredict[i]:
            nbGood += 1
        if housePredict[i] is not None:
            nbNotNone += 1

    print(nbGood, len(houses))
    print(nbGood / len(houses))


def splitDataHouse(data, houses):
    nbSlytherin = 0
    nbRavenclaw = 0
    nbHufflepuff = 0
    nbGryffindor = 0
    dataTrain = []
    dataTest = []
    houseTrain = []
    houseTest = []

    nbTakeHouse = 80

    for i in range(0, len(data)):
        if ((houses[i] == "Slytherin" and nbSlytherin < nbTakeHouse) or
                (houses[i] == "Ravenclaw" and nbRavenclaw < nbTakeHouse) or
                (houses[i] == "Hufflepuff" and nbHufflepuff < nbTakeHouse) or
                (houses[i] == "Gryffindor" and nbGryffindor < nbTakeHouse)):
            dataTest.append(data[i])
            houseTest.append(houses[i])
            if houses[i] == "Slytherin":
                nbSlytherin += 1
            if houses[i] == "Ravenclaw":
                nbRavenclaw += 1
            if houses[i] == "Hufflepuff":
                nbHufflepuff += 1
            if houses[i] == "Gryffindor":
                nbGryffindor += 1
        else:
            dataTrain.append(data[i])
            houseTrain.append(houses[i])

    return dataTrain, dataTest, houseTrain, houseTest


def main():
    if len(sys.argv) == 2:
        grd = readCSV(sys.argv[1])
        grd.pop(0)  # del Index
        flt = mapFilterNuneric(grd)
        data = list(map(lambda x: x[1:], flt))
        data = replaceNoneByKNN(data)
        data = grdReverse(data)
        houses = grd[0][1:]

        rdSeed = 7
        random.Random(rdSeed).shuffle(data)
        random.Random(rdSeed).shuffle(houses)

        dataTrain, dataTest, houseTrain, houseTest = splitDataHouse(data, houses)

        SlytherinC, RavenclawC, HufflepuffC, GryffindorC = findHouseC(dataTrain, houseTrain)

        weights = [
            ["Slytherin"] + SlytherinC,
            ["Ravenclaw"] + RavenclawC,
            ["Hufflepuff"] + HufflepuffC,
            ["Gryffindor"] + GryffindorC
        ]

        with open("weights.csv", "w+") as f:
            for i in range(0, len(weights)):
                st = ""
                for j in range(0, len(weights[i])):
                    if j != 0:
                        st += ","
                    st += str(weights[i][j])
                st += "\n"
                f.write(st)

        test(SlytherinC, RavenclawC, HufflepuffC, GryffindorC, dataTest, houseTest)

    else:
        print("Usage: ./logreg_train.py <file.csv>")


if __name__ == "__main__":
    try:
        main()
    except:
        print("an error occurred")
