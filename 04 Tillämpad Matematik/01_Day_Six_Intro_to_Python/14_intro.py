#!/usr/bin/env python3

def conv_Ncm_Nm(input):
	print('Input: ' + str(input) + " Ncm")

	output = (input / 100)

	print('Output: ' + str(output) + " Nm")

	return str(output)

asked = int(input("Enter Ncm: "))

print( str(asked) + " Ncm is " + conv_Ncm_Nm(asked) + " Nm")
