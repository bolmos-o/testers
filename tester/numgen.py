import random
import sys

numbers = int(sys.argv[1])
l = random.sample(range(-10000, 10000), numbers)
for num in l:
    print (num, end = ' ')