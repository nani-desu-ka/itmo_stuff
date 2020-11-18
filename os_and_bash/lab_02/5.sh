rm task_5.txt
touch task_5.txt
prev=0
sum=0
amount=0
is_process_id=1
process_id=0
temp_average_time=0
for process in $(cat task_4.txt | awk '{print $3, $5}')
do
	if (( $is_process_id == 1 ))
	then
		is_process_id=0
		process_id=$(echo $process | tr '=' ' ' | awk '{print $2}')
		continue
	else
		is_process_id=1
		temp_average_time=$(echo $process | tr '=' ' ' | awk '{print $2}')
	fi
	if (( $process_id == $prev ))
	then
		amount=$(echo $amount"+1" | bc)
		sum=$(echo $sum"+"$temp_average_time | bc)
	else
		if (( $amount != 0 ))
		then
			average=$(echo "scale=2; "$sum"/"$amount | bc)
			output_info="Average_Sleeping_Children_of_ParentID="$prev" is "$average
		fi
		prev=$process_id
		sum=$(echo $sum"+"$temp_average_time | bc)
		amount=1
		echo $output_info >> task_5.txt
	fi
done
average=$(echo "scale=2; $sum/$amount" | bc)
output_info="Average_Sleeping_Children_of_ParentID="$prev" is "$average
echo $output_info >> task_5.txt
