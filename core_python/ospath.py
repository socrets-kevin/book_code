#!usr/bin/env python

import os

cwd = os.getcwd()
print '*** current directory'
print cwd
print '*** creating example directory...'

os.mkdir('example')
os.chdir('example')
cwd = os.getcwd()
print '*** original directory listing:'
print os.listdir(cwd)

print '*** creating test file...'
fobj = open('test', 'w')
fobj.write('foo\n')
fobj.write('bar\n')
fobj.close()
print '***updated directory listing:'
print os.listdir(cwd)

print "*** renaming 'test' to 'file_test.txt'"
os.rename('test', 'file_test.txt')
print '*** updated directory listing:'
print os.listdir(cwd)

path = os.path.join(cwd, os.listdir(cwd)[0])
print '*** absolte file path'
print path

print '*** (pathname, basename) =='
print os.path.split(path)
print '***(file_name, extension) =='
print os.path.splitext(os.path.basename(path))

print '*** display file contents:'
fobj = open(path)
for each_line in fobj:
    print each_line,
fobj.close()

print '*** deleting test file'
os.remove(path)
print '*** updated directory listing:'
print os.listdir(cwd)
os.chdir(os.pardir)
print '*** deleting test directory'
os.rmdir('example')
print '*** Done'
