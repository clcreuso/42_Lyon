
import sys
sys.path.append("..")

from utils import *

import pandas as pd
import matplotlib.pyplot as plt

def main():
    if len(sys.argv) == 2:
        grd = readCSV(sys.argv[1])
        flt = mapFilterNuneric(grd)
        # print(flt)

        names = list(map(lambda x: x[0], flt))
        # print(names)
        data = list(map(lambda x: x[1:], flt))

        data = grdReverse(data)
        # print(data)
        df = pd.DataFrame(data, columns=names)

        lColors = [
            "black",
            "gray",
            "red",
            "sienna",
            "gold",
            "yellow",
            "chartreuse",
            "palegreen",
            "deepskyblue",
            "royalblue",
            "blueviolet",
            "pink",
            "m",
            "m",
            "m",
            "m",
            "m",
            "m",
            "m",
            "m",
            "m",
            "m",
        ]

        # ax = df.plot.scatter(x=names[0], y=names[1], label=names[1], color=lColors[0])
        # for i in range(2, len(names)):
        #    df.plot.scatter(x=names[0], y=names[i], label=names[i], ax=ax, color=lColors[i - 1])

        ax = df.plot.scatter(x=names[2], y=names[4])
        plt.show()

    else:
        print("Usage: ./scatter_plot.py <file.csv>")


if __name__ == "__main__":
    try:
        main()
    except:
        print("an error occurred")
