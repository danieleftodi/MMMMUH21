#!/usr/bin/env python3

def calc_power(volt, ampere):
	print('Volts: ' + str(volt) + " V")
	print('Ampres: ' + str(ampere) + " A")

	output = (volt * ampere)

	print('Output: ' + str(output) + " Watt")

	return str(output)

volts 	= float(input("Enter Volts: "))
amperes = float(input("Enter Amperes: "))

print("Power: " + calc_power(volts, amperes) + " Watt")
