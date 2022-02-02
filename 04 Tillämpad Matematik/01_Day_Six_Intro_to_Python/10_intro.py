#!/usr/bin/env python3

def to_the_power_of_two(input):
	print('Input: ' + str(input))

	output = pow(input, 2)
	
	print('Output: ' + str(output))

	return str(output)


print('Returned: ' + to_the_power_of_two(1) + "\n")

print('Returned: ' + to_the_power_of_two(4) + "\n")

print('Returned: ' + to_the_power_of_two(10) + "\n")

print('Returned: ' + to_the_power_of_two(12))