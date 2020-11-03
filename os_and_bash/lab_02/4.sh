touch task_4.txt
rm task_4.txt
ps ax -o pid > processes
for process in $(cat processes | head -n -1)
do
if [[ $process == "PID" ]]
then
continue
fi
ppid=$(cat "/proc/"$process"/status" | grep -E 'PPid:' | awk '{print $2}')
#cat "/proc/"$process"/sched"
sum_exec_runtime=$(cat "/proc/"$process"/sched" | grep -E 'se.sum_exec_runtime' | awk '{print $3}')
nr_switches=$(cat "/proc/"$process"/sched" | grep -E 'nr_switches' | awk '{print $3}')
sum_exec_runtime=${sum_exec_runtime/.*}
nr_switches=${nr_switches/.*}
if (( $sum_exec_runtime == 0 ))
then
sum_exec_runtime=1
fi
#echo $sum_exec_runtime
#echo $nr_switches
let "ART = $nr_switches / $sum_exec_runtime"
echo "ProcessID="$process" : Parent_ProcessID="$ppid" : Average_Running_Time="$ART >> temp_task_4.txt
done
rm processes
cat temp_task_4.txt | sort -k2 -V > task_4.txt
rm temp_task_4.txt
