#!/usr/bin/env python3

import statistics

def ret_mean(list):
	print('list:   ' + str(list))

	l = len(list)
	sl = sorted(list)
	sum = 0

	print("sorted: " + str(sl))

	for i in sl:
		sum = sum + i

	output = (sum / l)

	return str(output)

list = [10, 20, 30, 1, 2, 9]

print("The mean is: " + str(statistics.mean(list)))

print("The mean is: " + ret_mean(list))