#!/usr/bin/env python3

def echo_bin(input):
	print('Input: ' + str(input))

	output = str(bin(input))
	
	print('Output: ' + output)

	return output


print('Returned: ' + echo_bin(1) + "\n")

print('Returned: ' + echo_bin(2) + "\n")

print('Returned: ' + echo_bin(3) + "\n")

print('Returned: ' + echo_bin(4))