#!/usr/bin/env python3

def calc_t_force(lenght, momentum):
	print('Lenght: ' + str(lenght) + " m")
	print('Momentum: ' + str(momentum) + " N")

	output = (lenght * momentum)

	print('Output: ' + str(output) + " Nm")

	return str(output)

lenght 	= float(input("Enter lenght (m): "))
momentum = float(input("Enter momentum (N): "))

print("Force: " + calc_t_force(lenght, momentum) + " Nm")
