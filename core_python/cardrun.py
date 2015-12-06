#!/usr/bin/env python

def safe_float(obj):
    try:
        retval = float(obj)
    except (TypeError, ValueError), diag:
        retval = str(diag)
    return retval

def main():
    log = open('cardlog.txt', 'w')
    try:
        ccfile = open('carddata.txt', 'r')
    except IOError, e:
        log.write('no txns this month\n')
        log.close()
        return

    txns = ccfile.readlines()
    ccfile.close()
    total = 0.0
    log.write('account log:\n')

    for each_txn in txns:
        result = safe_float(each_txn)
        if isinstance(result, float):
            total += result
            log.write('data...processed\n')
        else:
            log.write('ignored: %s' %result)

    print '%.2f (new balance)' %(total)
    log.close()

if __name__ == '__main__':
    main()


