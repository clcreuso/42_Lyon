#! /usr/local/bin/python3.7

import sys
sys.path.append("..")

from utils import *

import time
import matplotlib.pyplot as plt
from matplotlib.widgets import Button

## PARSING

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

### INDEX DATA 

class Index():

    def __init__(self, dcts):
        self.ind = 0
        self.style = 0
        self.dcts = dcts
        self.fig, self.ax = plt.subplots()
        self.color = ['blue', 'green', 'red', 'orange']
        self.update()

    def set_ind(self, ind):
        self.ind = ind
        if self.ind < 0:
            self.ind = len(self.dcts) - 1
        if self.ind > len(self.dcts) - 1:
            self.ind = 0
            
    def set_style(self, style):
        self.style = style
        if self.style < 0:
            self.style = 2
        if self.style > 2:
            self.style = 0

    def update(self):
        self.update_title()
        self.courseNotes  = []
        self.hogwartsHouse = []
        for house, note in self.dcts[self.ind]["data"].items():
            self.courseNotes.append([x for x in note if x is not None])
            self.hogwartsHouse.append(house)
        self.update_hist()

    def update_title(self):
        plt.suptitle(self.dcts[self.ind]["name"], y=0.955, x=0.38, fontsize=14)

    def update_hist(self):
        if self.style == 0:
            self.ax.hist(self.courseNotes, 
                    label=self.hogwartsHouse,
                    density=True,
                    stacked=True,
                    edgecolor='black',
                    linewidth=0.7,
                    color=self.color)
        if self.style == 1:
            for i in range(0, len(self.courseNotes)):
                self.ax.hist(self.courseNotes[i], 
                        alpha=0.6, 
                        label=self.hogwartsHouse[i], 
                        density=True,
                        color=self.color[i])
        if self.style == 2:
            self.ax.hist(self.courseNotes, 
                    label=self.hogwartsHouse,
                    density=True,
                    color=self.color)
        self.ax.legend(self.hogwartsHouse, loc='upper right')
        self.ax.set_xlabel("Notes")
        self.ax.set_ylabel("Nb students")

    def switch(self, event):
        self.set_style(self.style + 1)
        self.ax.cla()
        self.update()
        plt.draw()

    def next(self, event):
        self.set_ind(self.ind + 1)
        self.ax.cla()
        self.update()
        plt.draw()

    def prev(self, event):
        self.set_ind(self.ind - 1)
        self.ax.cla()
        self.update()
        plt.draw()

# DISPLAY INFO

def makeDisplayInfo(houses, grd):
    dfs = []
    for i in range(0, len(grd)):
        name = grd[i][0]
        dct = {}
        for j in range(1, len(grd[i])):
            key = houses[j]
            if key not in dct.keys():
                dct[key] = []
            dct[key].append(grd[i][j])
        dfs.append({'name' : name, 'data' : dct})
                
    return dfs


def main():
    if len(sys.argv) != 2:
        print("Usage: ./histogram.py <file.csv>")
        return

    grd = readCSV(sys.argv[1])
    grd.pop(0)
    houses = grd.pop(0)
    grd = mapFilterNuneric(grd)
    dcts = makeDisplayInfo(houses, grd)

    callback = Index(dcts)

    axprev = plt.axes([0.66, 0.90, 0.06, 0.075])
    bprev = Button(axprev, '←')
    bprev.on_clicked(callback.prev)

    axswitch = plt.axes([0.73, 0.90, 0.1, 0.075])
    bswitch = Button(axswitch, 'switch')
    bswitch.on_clicked(callback.switch)

    axnext = plt.axes([0.84, 0.90, 0.06, 0.075])
    bnext = Button(axnext, '→')
    bnext.on_clicked(callback.next)
    plt.show()

if __name__ == "__main__":
    try:
        main()
    except:
        print("an error occurred")
