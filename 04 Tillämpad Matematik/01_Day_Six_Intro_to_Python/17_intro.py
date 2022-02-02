#!/usr/bin/env python3

def calc_rpm_for_second(teethA, rpmA, teethB):
	print('Teeths gear A: ' + str(teethA))
	print('RPM gear A: ' + str(rpmA) + " rpm")
	print('Teeths gear B: ' + str(teethB))

	output = (rpmA * (teethA/teethB))

	print('Output: ' + str(output) + " rpm")

	return str(output)

teethA 	= int(input("Enter teeths for gear A: "))
rpmA 	= float(input("Enter RPM for gear A: "))
teethB 	= int(input("Enter teeths for gear B: "))

print("Gear B has: " + calc_rpm_for_second(teethA, rpmA, teethB) + " rpm")
