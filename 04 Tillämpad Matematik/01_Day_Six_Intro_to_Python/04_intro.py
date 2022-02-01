#!/usr/bin/env python3
import math

def ret_hyp(cat_oposite, cat_closest):
	print('Catheter oposite: ' + str(cat_oposite))
	print('catheter closest: ' + str(cat_closest))

	output = str(math.sqrt((cat_closest^2) + (cat_closest^2)))
	
	print('Output: ' + output)

	return output


print('Hypotenuse: ' + ret_hyp(10, 20) + "\n")

print('Hypotenuse: ' + ret_hyp(50, 20) + "\n")

print('Hypotenuse: ' + ret_hyp(30, 30))