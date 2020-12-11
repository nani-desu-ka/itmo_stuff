rm output_1.log
touch output_1.log
rm output_2.log
touch output_2.log
./mem.bash&pid0=$!
./mem2.bash&pid1=$!
echo "free_mem_total free_swap_total virt resources cpu_percentage time" >> output_1.log

while :
do
	process_info=$(top -p $pid0 -n 1 | head -8 | tail -1)
	virt=$(echo $process_info | awk '{print $6}')
	resources=$(echo $process_info | awk '{print $7}')
	cpu_percentage=$(echo $process_info | awk '{print $10}')
	running_time=$(echo $process_info | awk '{print $12}')
	mem_free=$(top -n 1 | head -4 | tail -1 | awk '{print $6}')
	swap_free=$(top -n 1 | head -5 | tail -1 | awk '{print $5}')
	echo $mem_free" "$swap_free" "$virt" "$resources" "$cpu_percentage" "$running_time >> output_1.log

	process_info=$(top -p $pid1 -n 1 | head -8 | tail -1)
        virt=$(echo $process_info | awk '{print $6}')
        resources=$(echo $process_info | awk '{print $7}')
        cpu_percentage=$(echo $process_info | awk '{print $10}')
        running_time=$(echo $process_info | awk '{print $12}')
        mem_free=$(top -n 1 | head -4 | tail -1 | awk '{print $6}')
        swap_free=$(top -n 1 | head -5 | tail -1 | awk '{print $5}')
        echo $mem_free" "$swap_free" "$virt" "$resources" "$cpu_percentage" "$running_time >> output_2.log
	sleep 1
done
