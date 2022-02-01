#!/usr/bin/env python3

def echo(input1,input2):
	print('Input1: ' + str(input1))
	print('Input2: ' + str(input2))

	if ((input1 > 5) and (input2 < 20)):
		output = "True"
	else:
		output = "False"
	
	print('Output: ' + output)

	return output


print('Returned: ' + echo(10, 20) + "\n")

print('Returned: ' + echo(50, 20) + "\n")

print('Returned: ' + echo(4, 30) + "\n")

print('Returned: ' + echo(10, 19))