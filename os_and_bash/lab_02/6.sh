ps ax -o pid > processes
for process in $(cat processes | head -n -1)
do
if [[ $process == "PID" ]]
then
continue
fi
cat "/proc/"$process"/status" | grep -E 'VmRSS:' | awk '{print $2}' | awk '{print int($0)}' >> temp.txt
done
cat temp.txt | sort | head -1
rm temp.txt
rm processes
