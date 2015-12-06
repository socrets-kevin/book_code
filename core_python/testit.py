#usr/bin/env python

def testit(func, *nkwargs, **kwargs):
    try:
        retval = func(*nkwargs, **kwargs)
        result = (True, retval)
    except Exception, diag:
        result = (False, str(diag))
    return result

def test():
    funcs = (int, long, float)
    vals = (1234, 12.34, '1234', '12.34')

    for each_func in funcs:
        print '-'*20

        for each_val in vals:
            retval = testit(each_func, each_val)

            if retval[0]:
                print '%s(%s)=' %(each_func.__name__, each_val), retval[1]
            else:
                print '%s(%s)=FAILED' %(each_func.__name__, each_val), retval[1]

if __name__=='__main__':
    test()
