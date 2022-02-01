#!/usr/bin/env python3

def echo(input1,input2):
	print('Input1: ' + str(input1))
	print('Input2: ' + str(input2))

	if (input1 > input2):
		output = str(input1)
	elif (input1 == input2):
		output = "Equal"
	else:
		output = str(input2)
	
	print('Output: ' + output)

	return output


print('Returned: ' + echo(10, 20) + "\n")

print('Returned: ' + echo(50, 20) + "\n")

print('Returned: ' + echo(30, 30))