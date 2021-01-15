


#! /bin/bash

#function to display usage instructions
function usage(){
echo "Usage: psmonitor [-t tseconds] [-n count]";
}

#command function
function psmonitor(){

#unset variables to ensure fresh start 
unset opt OPTARG OPTIND canrun 

#set defaults
sleeptime=1
count=5
canrun=1 #flag to indicate if all inputs are correct before process scan is run
 
#use getopts to parge the command arguments 
while getopts ":ht:n:" opt
 do
  case ${opt} in
   (t)
       sleeptime=${OPTARG:=$sleeptime};;
    (n)
       count=${OPTARG:=$count};;
    (h)
       canrun=0
       usage;;
    (*) #handle missing argument errors
       if [ $OPTARG == 'n' ] 
	then
          echo "Missing count Argument" 
        else
          echo "Missing tseconds Argument"
       fi
	canrun=0
       usage;;
  esac
done


#handle interrupts
trap '{ echo ""; echo "Hey, you pressed Ctrl-C.  Time to quit."; sleep 2; return 0; }' INT

i=1

#scan and display the processes per user inputs
while [ $i -le $count -a $canrun -eq 1 ]
do
echo ""
 date
 ps -A
 i=`expr $i + 1`
sleep $sleeptime
done

echo "_________________________________________"
echo "Program written by Derrick Annor"

}


