#!/usr/bin/env python3

def algebra_2557(input):
	print('Input: ' + str(input))

	output = str(pow(-input, 2) + (55 * input) + 7)

	return output


print('Returned: ' + algebra_2557(1) + "\n")

print('Returned: ' + algebra_2557(4) + "\n")

print('Returned: ' + algebra_2557(10) + "\n")

print('Returned: ' + algebra_2557(12))