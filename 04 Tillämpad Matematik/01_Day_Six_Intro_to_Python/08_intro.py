#!/usr/bin/env python3

def echo_hex(input):
	print('Input: ' + str(input))

	output = str(hex(input))
	
	print('Output: ' + output)

	return output


print('Returned: ' + echo_hex(1) + "\n")

print('Returned: ' + echo_hex(10) + "\n")

print('Returned: ' + echo_hex(50) + "\n")

print('Returned: ' + echo_hex(100))