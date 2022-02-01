#!/usr/bin/env python3

def echo(input1,input2):
	print('Input1: ' + str(input1))
	print('Input2: ' + str(input2))

	if (str(input1) == str(input2)):
		output = "True"
	else:
		output = "False"
	
	print('Output: ' + output)

	return output


print('Returned: ' + echo("Hello", "World") + "\n")

print('Returned: ' + echo(10, 20) + "\n")

print('Returned: ' + echo(30, 30))