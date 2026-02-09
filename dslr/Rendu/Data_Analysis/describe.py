#! /Users/cepalle/.brew/bin/python3

import sys
sys.path.append("..")

from utils import *

import math 
import time
from datetime import datetime
from utils import *

### MATH FUNCTIONS

def countDescribe(listNum):
    '''Retrun len of listNum'''
    return len(listNum)

def meanDescribe(listNum):
    '''Retrun mean of listNum'''
    if (len(listNum) == 0):
        return None

    sumList = float(0)

    for i in listNum:
        sumList += i

    return sumList / len(listNum)

def stdDescribe(listNum):
    '''Retrun std of listNum'''
    if (len(listNum) == 0):
        return None

    sumList = float(0)
    meanList = meanDescribe(listNum)

    for i in listNum:
        sumList += pow(i - meanList, 2)

    return math.sqrt(sumList / len(listNum))

def qt1Describe(listNum):
    '''Retrun first quartile of listNum. Return None if len < 0'''
    if (len(listNum) == 0):
        return None
    if (len(listNum) < 2):
        return listNum[0]

    copy = list(listNum)
    copy.sort()

    first = round(1 * countDescribe(copy) / 4)

    return float(copy[first])

def qt2Describe(listNum):
    '''Retrun median of listNum. Return None if len < 0'''
    if (len(listNum) == 0):
        return None
    if (len(listNum) < 2):
        return listNum[0]

    copy = list(listNum)
    copy.sort()

    median = round(2 * countDescribe(copy) / 4)
    
    return float(copy[median])

def qt3Describe(listNum):
    '''Retrun third quartile of listNum. Return None if len < 0'''
    if (len(listNum) == 0):
        return None
    if (len(listNum) < 2):
        return listNum[0]

    copy = list(listNum)
    copy.sort()

    third = round(3 * countDescribe(copy) / 4)
    return float(copy[third])

def minDescribe(listNum):
    '''Retrun min of listNum. Return None if len < 0'''
    if (len(listNum) == 0):
        return None

    copy = list(listNum)
    copy.sort()

    return float(copy[0])

def maxDescribe(listNum):
    '''Retrun max of listNum. Return None if len < 0'''
    if (len(listNum) == 0):
        return None

    copy = list(listNum)
    copy.sort()
    
    return float(copy[-1])

### PARSING

def safeParseFlaotDate(l):
    nw = []
    for i in range(0, len(l)):
        if i == 0:
            nw.append(l[i])
        elif l[i] == "":
            nw.append(None)
        else:
            ep = safeCall(l[i], float)
            if ep == None:
                ep = safeCall(l[i], lambda x: time.mktime(time.strptime(x, "%Y-%m-%d")))
            if ep == None:
                return None
            nw.append(ep)

    return nw

def mapFilterNunericAndDate(grd):
    return list(
        filter(
            lambda x: x is not None,
            map(safeParseFlaotDate,
                grd
            )
        )
    )

### DESCRIBE

def valueFormat(nb, isDate, isStd):
    if nb == None:
        return "None"
    if isStd and isDate:
        return str(int(nb / (30.5 * 3600 * 24))) + " months"
    if isDate:
        return str(datetime.fromtimestamp(nb)).split(sep=" ")[0]
    return "{:.4f}".format(nb)

def makeLineStat(l):
    isDate = (l[0] == "Birthday")
    firstPart = list(filter(
            lambda x: x is not None,
            l[1:]
        ))
    return [
        l[0],
        str(int(countDescribe(firstPart))),
        valueFormat(meanDescribe(firstPart), isDate, False),
        valueFormat(stdDescribe(firstPart), isDate, True),
        valueFormat(minDescribe(firstPart), isDate, False),
        valueFormat(qt1Describe(firstPart), isDate, False),
        valueFormat(qt2Describe(firstPart), isDate, False),
        valueFormat(qt3Describe(firstPart), isDate, False),
        valueFormat(maxDescribe(firstPart), isDate, False),
    ]

def displayDescribe(grd):
    grdInfo = list(map(makeLineStat, grd))
    Y = [
        "",
        "Count",
        "Mean",
        "Std",
        "Min",
        "25%",
        "50%",
        "75%",
        "Max",
    ]
    pad = []
    for i in range(0, len(grdInfo)):
        mx = 0
        for s in grdInfo[i]:
            if mx < len(s):
                mx = len(s)
        pad.append(mx + 3)

    for i in range(0, len(Y)):
        print(Y[i].rjust(5), end="")
        for j in range(0, len(grdInfo)):
           print(grdInfo[j][i].rjust(pad[j]), end="")
        print()

def main():
    if len(sys.argv) == 2:
        grd = readCSV(sys.argv[1])
        grd.pop(0) # del Index
        flt = mapFilterNunericAndDate(grd)
        displayDescribe(flt)
    else:
        print("Usage: ./describe.py <file.csv>")

if __name__ == "__main__":
    try:
        main()
    except:
        print("an error occurred")
