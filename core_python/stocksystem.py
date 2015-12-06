symbol_list = []
stock_nm_list = []
bought_pr_list = []
current_pr_list = []
encompassing_list = []

def input_data():
    print 'input 3 groups of data'
    count = 0
    while (count < 3):
        symbol_name = raw_input('input symbole name:')
        symbol_list.append(symbol_name)
        stock_name = raw_input('input stock name:')
        stock_nm_list.append(stock_name)
        bought_price = raw_input('input bought price:')
        bought_price = int(bought_price)
        bought_pr_list.append(bought_price)
        current_price = raw_input('input current price:')
        current_price = int(current_price)
        current_pr_list.append(current_price)
        count += 1
    encompassing_list = [symbol_list, stock_nm_list, bought_pr_list, current_pr_list]
    return encompassing_list

def make_dict():
    name_boupr_dict = dict([(stock_nm_list[i], bought_pr_list[i]) for i in range(len(stock_nm_list))])
    name_currpr_dict = dict([(stock_nm_list[i], current_pr_list[i]) for i in range(len(stock_nm_list))])
    print name_boupr_dict, name_currpr_dict

def show_menu():
    prompt = """
    (I)nput group of data
    (M)ake the name boughtprice and current price dictionary
    (Q)uit
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
            if choice not in 'imq':
                print 'invalid input, try again'
            else:
                chosen = True

            if choice == 'i': input_data()
            if choice == 'm': make_dict()
            if choice == 'q': done = True

if __name__ == '__main__':
    show_menu()
