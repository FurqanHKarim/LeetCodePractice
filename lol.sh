#!/bin/bash
echo $1
stop=$1
i=0

while [[ $i -le $stop ]] ; do
    output="$output Today's Date is $i\n"
    the_Path=$(pwd)
    ((i += 1))
done    
echo  -e "$output" >> output.txt
echo -e $the_Path
echo "HELLO JEE"
