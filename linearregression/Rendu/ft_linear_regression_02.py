#! /usr/local/bin/python3.7

import sys
import csv

def functionLinear(theta0, theta1):
	return lambda x: (theta1 * x) + theta0

def errorMean(price, km, estimatePrice):
	sumtheta0 = float(0)

	for i in range(0, len(km)):
		sumtheta0 += abs(estimatePrice(km[i]) - price[i])
	
	return sumtheta0 / len(km)

def errorVariances(price, km, estimatePrice):
	sumtheta0 = float(0)
	sumtheta1 = float(0)

	for i in range(0, len(km)):
		sumtheta0 += estimatePrice(km[i]) - price[i]
		sumtheta1 += (estimatePrice(km[i]) - price[i]) * km[i]
	
	return sumtheta0 / len(km), sumtheta1 / len(km)

def minimizeErrorVariances(price, km, theta0, theta1):
	learningRateTheta0 = 0.001
	learningRateTheta1 = 0.0000000001

	tmpTheta0, tmpTheta1 = errorVariances(price, km, functionLinear(theta0, theta1))

	theta0 -= tmpTheta0 * learningRateTheta0
	theta1 -= tmpTheta1 * learningRateTheta1

	return theta0, theta1

def readCsvFile():
	km, price = list(), list()

	try:
		with open('./data.csv','rt') as f:
			data = csv.reader(f)
			for row in data:
				try:
					km.append(int(row[0]))
					price.append(int(row[1]))
				except:
					pass
	except:
		print("Error: no data.csv file at root", file=sys.stderr)
		sys.exit()

	return (km, price)

def saveThetaValue(theta0, theta1):
	with open('./ft_linear_regression_01.py','r') as f:
		lines = f.readlines()
	with open('./ft_linear_regression_01.py','w') as f:
		for line in lines:
			if line.lower().startswith("\ttheta0 = float("):
				line = f"\ttheta0 = float({theta0})\n"
			if line.lower().startswith("\ttheta1 = float("):
				line = f"\ttheta1 = float({theta1})\n"
			f.write(line)

def main():
	km, price = readCsvFile()
	
	theta0 = float(0) 
	theta1 = float(0)

	while True:
		meanBefore = errorMean(price, km, functionLinear(theta0, theta1))
		theta0, theta1 = minimizeErrorVariances(price, km, theta0, theta1)
		meanAfter = errorMean(price, km, functionLinear(theta0, theta1))
		if (abs(meanAfter - meanBefore) < 0.00001):
			break
	
	saveThetaValue(theta0, theta1)

if __name__ == "__main__":
    main()
