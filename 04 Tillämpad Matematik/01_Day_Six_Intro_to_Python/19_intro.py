#!/usr/bin/env python3

import statistics
import math

def ret_std_deviation(list):
	print('list:   ' + str(list))

	l = len(list)
	sl = sorted(list)
	print("sorted: " + str(sl))

	zum = sum(sl)
	print("Sum: " + str(zum))
	avg = (zum / l)
	print("Avg: " + str(avg))
	
	tmp_sum = 0
	for i in range(len(sl)):
		tmp_sum += ((sl[i] - avg) * (sl[i] - avg))
		print("[" + str(sl[i]) + "]: " + str(tmp_sum))

	output = math.sqrt(tmp_sum / l)


	return str(output)

listA = [10, 20, 30, 1, 2, 9]
listB = [10,  8, 10, 8, 8, 4]



print("The std deviation is: " + str(statistics.pstdev(listA)))

print("The std deviation is: " + ret_std_deviation(listA))



print("\nThe std deviation is: " + str(statistics.pstdev(listB)))

print("The std deviation is: " + ret_std_deviation(listB))