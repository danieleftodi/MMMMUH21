#!/usr/bin/env python3

def conv_Nm_Ncm(input):
	print('Input: ' + str(input) + " Nm")

	output = (input * 100)

	print('Output: ' + str(output) + " Ncm")

	return str(output)

asked = int(input("Enter Nm: "))

print( str(asked) + " Nm is " + conv_Nm_Ncm(asked) + " Ncm")
