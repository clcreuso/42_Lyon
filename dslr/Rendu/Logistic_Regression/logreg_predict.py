import sys

sys.path.append("..")

from utils import *
from logreg_train import predict


def main():
    if len(sys.argv) == 2:
        weights = readCSV("weights.csv")
        weights = grdReverse(weights)
        weights = list(map(lambda e: list(map(float, e[1:])), weights))
        # print(weights)

        data = readCSV("dataset_train.csv")
        data.pop(0)  # del Index
        data.pop(0)  # del House
        data = mapFilterNuneric(data)
        data = list(map(lambda x: x[1:], data))

        dataTest = readCSV(sys.argv[1])
        dataTest.pop(0)  # del Index
        dataTest.pop(0)  # del House
        dataTest = mapFilterNuneric(dataTest)
        dataTest = list(map(lambda x: x[1:], dataTest))

        for i in range(0, len(data)):
            dataTest[i] = dataTest[i] + data[i]

        dataTest = replaceNoneByKNN(dataTest)
        dataTest = list(map(lambda l: l[:(len(dataTest[0]) - len(data[0]))], dataTest))

        dataTest = grdReverse(dataTest)
        housesPredict = predict(weights[0], weights[1], weights[2], weights[3], dataTest)
        # print(housesPredict)
        try:
            with open("houses.csv", "w+") as f:
                f.write("Index,Hogwarts House\n")
                for i in range(0, len(housesPredict)):
                    f.write(str(i) + "," + housesPredict[i] + "\n")
        except:
            print("write failed")
            exit(1)

        print(len(list(filter(lambda e: e == 'Ravenclaw', housesPredict))))
        print(len(list(filter(lambda e: e == 'Slytherin', housesPredict))))
        print(len(list(filter(lambda e: e == 'Gryffindor', housesPredict))))
        print(len(list(filter(lambda e: e == 'Hufflepuff', housesPredict))))

    else:
        print("Usage: ./logreg_predict.py <file.csv>")


if __name__ == "__main__":
    try:
        main()
    except:
        print("an error occurred")
