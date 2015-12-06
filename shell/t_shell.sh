clear
echo "--------------------------"
echo "fresh ubuntu setup"
echo "--------------------------"

show_info() {
echo  "\033[1;33m$@\033[0m"
}

show_success() {
echo  "\033[1;32m$@\033[0m"
}

show_error() {
echo  "\033[1;31m$@\033[0m"
}

function main {
echo ""
show_info "select part to setup"
echo ""
echo "1. setup and config the terminal"
echo "2. setup and config vim"
echo "3. setup python web development environment"
echo "q. quit"
show_info "Enter choice: " && read REPLY
case $REPLY in 
    1) terminal_setup;;
    2) vim_setup;;
    3) python_setup;;
    
}
