#!usr/bin/env python

def show_max_factor(number):
    count = number / 2

    while count > 1:
        if number % count == 0:
            print 'the max factor of %d is %d' %(number, count)
            break
        count -= 1
    else:
        print '%d is prime' %number

for each_number in range(10, 21):
    show_max_factor(each_number)
