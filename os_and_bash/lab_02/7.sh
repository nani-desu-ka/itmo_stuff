for process in $(ps ax -o pid | sed 1d)
do
rchar_temp=$(grep -s -i "rchar" /proc/$process/io | awk '{print $2}')
if [[ -z $rchar_temp ]]
then
continue
fi
echo $process" "$rchar_tmep >> task_7_temp.txt
done
sleep 5s

for process in $(ps ax -o pid | sed 1d)
do
rchar_temp=$(grep -s -i "rchar" /proc/$process/io | awk '{print $2}')
if [[ -z $rchar_temp ]]
then
continue
fi
echo $process" "$rchar_temp >> task_7_temp_2.txt
done

for process in $(cat task_7_temp.txt)
do
pid=$(echo $process | awk '{print $1}')
rchar=$(echo $process | awk '{print $2}')
process_2=$(grep -s "^$pid" task_7_temp_2.txt)
if [[ $process_2 ]]
then
rchar_2=$(echo $process_2 | awk '{print $2}')
result=$((rchar_2 - rchar))
bootline=$(cat "/proc/"$pid"/cmdline")
echo $pid" : "$bootline" : "$result >> task_7_temp_3.txt
#echo $pid":"$result >> task_7_temp_3.txt
else
continue
fi
done
cat task_7_temp_3.txt | sort -t":" -n -k2 > task_7.txt
cat task_7.txt | tail -3
rm task_7_temp.txt task_7_temp_2.txt task_7_temp_3.txt
