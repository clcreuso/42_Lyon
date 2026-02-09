#! /usr/local/bin/python3.7

import sys

def functionLinear(theta0, theta1):
	return lambda x: (theta1 * x) + theta0

def recoverMileage():
	print("Estimate price of your car.")

	try:
		value = input("What is the mileage of your car: ")
		mileage = int(value)
	except:
		print("Error: invalid mileage", file=sys.stderr)
		sys.exit()

	if (mileage < 0):
		print("Error: negative mileage", file=sys.stderr)
		sys.exit()
	return mileage

def printEstimate(estimate):
	if round(estimate) < 2:
		print(f"Your car is estimate at 1 euro.")
	else:
		print(f"Your car is estimate at {round(estimate)} euros.")

def main():
	mileage = recoverMileage()
	
	theta0 = float(0)
	theta1 = float(0)
	
	printEstimate(functionLinear(theta0, theta1)(mileage))

if __name__ == "__main__":
    main()
