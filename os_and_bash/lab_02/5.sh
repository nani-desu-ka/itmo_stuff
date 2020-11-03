prev=0
sum=0
amount=0
cat task_4.txt | awk '{print $3, $5}' | tr '=' ' ' | awk '
$2 == prev {amount+=1; sum+=$4;}
$2 != prev {average=$(echo "$sum/$amount" | bc); output_info="Average_Sleeping_Children_of_ParentID="prev" is "average;
prev=$2; sum+=$4; amount=1; print output_info;}
END {average=$(echo "$sum/$amount" | bc); output_info="Average_Sleeping_Children_of_ParentID="prev" is "average; print output_info}
' > task_5.txt
