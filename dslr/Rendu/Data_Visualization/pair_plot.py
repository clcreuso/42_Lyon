
import sys
sys.path.append("..")

from utils import *

import pandas as pd
from pandas.plotting import radviz
from pandas.plotting import scatter_matrix

import matplotlib.pyplot as plt
import seaborn as sns


def house_to_color(l):
    if l == "Gryffindor":
        return "red"
    elif l == "Ravenclaw":
        return "blue"
    elif l == "Slytherin":
        return "green"
    else:
        return "yellow"

def main():
    if len(sys.argv) == 2:
        grd = readCSV(sys.argv[1])
        grd.pop(0)
        flt = mapFilterNuneric(grd)

        names = list(map(lambda x: x[0], flt))
        data = list(map(lambda x: x[1:], flt))
        #data = list(map(replaceNoneByMean, data))
        data = grdReverse(data)
        data = replaceNoneByKNN(data)

        data = list(map(
            lambda l: list(map(
                lambda e: e if e is not None else 0,
                l
            )),
            data
        ))

        df = pd.DataFrame(data, columns=names)
        df['Hogwarts_House'] = grd[0][1:]

        sns.pairplot(df, hue='Hogwarts_House')
        plt.show()
    else:
        print("Usage: ./pair_plot.py <file.csv>")

if __name__ == "__main__":
    try:
        main()
    except:
        print("an error occurred")
