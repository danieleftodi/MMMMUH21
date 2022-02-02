#!/usr/bin/env python3

def algebra_253(input):
	print('Input: ' + str(input))

	output = str(pow(input, 2) - (5 * input) + 3)

	return output


print('Returned: ' + algebra_253(1) + "\n")

print('Returned: ' + algebra_253(4) + "\n")

print('Returned: ' + algebra_253(10) + "\n")

print('Returned: ' + algebra_253(12))