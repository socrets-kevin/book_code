#!/bin/bash
#dir="$(dirname "$0")"
#$dir/show_info

echo "1 perform show_info" && read REPLY
case $REPLY in 
    1) ./show_info ;;
esac

