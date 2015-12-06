#!usr/bin/env python
import time

data_base = {}
db_logintime = {}

def new_user():
    prompt = 'login desired:'

    while True:
        name = raw_input(prompt)
        if data_base.has_key(name):
            print 'name already taken, take another one'
            continue
        else:
            break
    pwd = raw_input('enter password:')
    data_base[name] = pwd

def old_user():
    name = raw_input('enter name:')
    pwd = raw_input('enter password:')
    pass_wd = data_base.get(name)

    if pass_wd == pwd:
        login_time_seconds = time.time()
        login_time = time.ctime(login_time_seconds)
        login_name_key = name + '_login_time'
        db_logintime[login_name_key] = login_time
        print 'Login correct,welcome back'
    else:
        print 'login fail'

def admin_user():
    prompt = """
    (R)emove a user
    (L)ist the user and password
    """
    choice = raw_input(prompt).strip()[0].lower()
    print 'your choice is [%s]' %choice
    try:
        if choice == 'r':
            del_name = raw_input('enter a name:')
            if del_name in data_base.keys():
               del data_base[del_name]
               print 'delete %s of the database' %del_name
               return data_base
            else:
                print 'nothing change'
        elif choice == 'l':
            list_namepwd = data_base.keys() + data_base.values()
            print 'the list of name and password', list_namepwd
    except (EOFError, KeyboardInterrupt):
        print 'nothing'

def show_menu():
    prompt = """
    (N)ew User,
    (O)ld User,
    (A)dmin User
    (Q)uit
    Enter your choice:
    """
    done = False

    while not done:
        chosen = False
        while not chosen:
            try:
                choice = raw_input(prompt).strip()[0].lower()
            except (EOFError, KeyboardInterrupt):
                choice = 'q'
            print 'your choice is [%s]' %choice
            if choice not in 'noqa':
                print 'invalid input,try again'
            else:
                chosen = True
        if choice == 'q': done=True
        if choice == 'n': new_user()
        if choice == 'o': old_user()
        if choice == 'a': admin_user()

if __name__ == '__main__':
    show_menu()




