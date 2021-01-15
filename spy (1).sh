
#! /bin/bash

#function to display usage instructions
function usage(){
  echo "Usage: spy [list of patterns] [-t tseconds] [-n count]";
}

#command function
function spy(){

#unset variables to ensure fresh start 
unset opt OPTARG OPTIND canrun

#set defaults
sleeptime=1
count=5
canrun=1 #flag to indicate if all inputs are correct before process scan is run


#build the ps command here 
pscommand="ps -eo user,pid,cmd"

endofargs=1 #indicates the index where positional arguments end

#if there are any arguments, then append the input patterns
if [ $# -gt 0 -a $1 != "-n" -a $1 != "-t" ] 
then
pscommand+="|grep" 
for arg in $@
do
  if [[ $arg == "-n" || $arg == "-t" ]];
      then
        break
  fi
    
    pscommand+=" -e "
    pscommand+=$arg
    endofargs=`expr $endofargs + 1`
done
fi

OPTIND=$endofargs
 
#use getopts to parge the option arguments 
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
trap '{ echo ""; echo "Hey, you pressed Ctrl-C.  Time to quit."; sleep 2; rm .temp1.txt; rm .temp2.txt; echo "Command terminated. Please execute command \"cat spy.txt\" to see the process log."; unset array; unset array2; exit 2; }' INT

i=1

echo "Command running in background:::: $pscommand >> spy.txt"

#run the command for count times 
while [ $i -le $count -a $canrun -eq 1 ]
do
 #output file is spy.tx
 echo "" >> spy.txt
 date >> spy.txt

 eval $pscommand > .temp2.txt #run the command here and direct the output to temporary file .temp2.txt
 
 #create a second temporary file .temp1.txt 
 touch .temp1.txt
 
 #On each scan load the contents of the temp files into arrays array1 and array2 respectively
 IFS=$'\n' array2=( `cat ".temp2.txt"` )
 IFS=$'\n' array1=( `cat ".temp1.txt"` )
 
 #for each process in previous, check if it's still running (array1). Log those stopped as ended 
 for p in "${array1[@]}"
   do 
       found=0
       for z in "${array2[@]}"
           do
		if [[ $p != $z ]]; then
                    found=0
		else
		    found=1
		    break
		fi
	   done
	if [ $found -eq 0 ]; then
	   echo "Ended: $p" >> spy.txt 
	fi
 done

 #for each process in current scan (array2), check if it was logged in previous scan (array1) and log it as started if not.  
 for p1 in "${array2[@]}"
   do 
       found1=0
       for z1 in "${array1[@]}"
           do
		if [[ $p1 != $z1 ]]; then
                    found1=0
		else
		    found1=1
		    break
		fi
	   done
	if [ $found1 -eq 0 ]; then
	   echo "Started: $p1" >> spy.txt 
	fi
 done

cp .temp2.txt .temp1.txt #update previous  temporary log with the current scan results

i=`expr $i + 1`
sleep $sleeptime
done

#delete the temporary files and reclaim resources.
rm .temp1.txt
rm .temp2.txt
unset array1
unset array2
echo "_________________________________________" >> spy.txt
echo "Program written by Derrick Annor" >> spy.txt
echo "" >> spy.txt
echo "Done. Please execute command \"cat spy.txt\" to see the process log."
}
