import csv
import math


def safeCall(val, to_type, default=None):
    try:
        return to_type(val)
    except (ValueError, TypeError):
        return default


def readCSV(fname):
    grd = []
    try:
        with open(fname, 'rt') as f:
            data = csv.reader(f)
            for row in data:
                for i in range(0, len(row)):
                    if len(grd) <= i:
                        grd.append([])
                    grd[i].append(row[i])
    except:
        print("open faild")
        exit(0)
    return grd


def readCSVBis(fname):
    grd = []
    try:
        with open(fname, 'rt') as f:
            data = csv.reader(f)
            for row in data:
                grd.append(row)
    except:
        print("open faild")
        exit(0)
    return grd


def safeParseFlaot(l):
    nw = []
    for i in range(0, len(l)):
        if i == 0:
            nw.append(l[i])
        elif l[i] == "":
            nw.append(None)
        else:
            ep = safeCall(l[i], float)
            if ep == None:
                return None
            nw.append(ep)

    return nw


def mapFilterNuneric(grd):
    return list(
        filter(
            lambda x: x is not None,
            map(safeParseFlaot,
                grd
                )
        )
    )


def replaceNoneByMean(l):
    smNotNone = 0
    nbNotNone = 0
    for e in l:
        if e is None:
            continue
        smNotNone += e
        nbNotNone += 1
    mean = smNotNone / nbNotNone
    return list(map(lambda e: e if e is not None else mean, l))


def replaceNoneByKNN(lX):
    def valueByKNN(lX, X, k):
        score = 0
        deno = 0
        for i in range(0, len(lX)):
            if lX[i][k] is not None:
                d = 0
                for j in range(0, len(lX[i])):
                    if j != k and lX[i][j] is not None and X[j] is not None:
                        df = abs(X[j] - lX[i][j])
                        d += df * df
                d = math.sqrt(d)
                d = d * d * d
                if d == 0:
                    return lX[i][k]
                deno += (1 / d)
                score += lX[i][k] * (1 / d)
        return score / deno

    nw = []
    for i in range(0, len(lX)):
        if None in lX[i]:
            nl = []
            for j in range(0, len(lX[i])):
                if lX[i][j] is None:
                    nl.append(valueByKNN(lX, lX[i], j))
                else:
                    nl.append(lX[i][j])
            nw.append(nl)
        else:
            nw.append(lX[i])

    return nw


def grdReverse(grd):
    x = len(grd)
    y = len(grd[0])
    nw = []
    for i in range(0, y):
        nw.append([])
        for j in range(0, x):
            nw[i].append(grd[j][i])
    return nw
