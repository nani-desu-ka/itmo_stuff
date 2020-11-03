touch task_3.txt
ps a u x | awk '{if ($1 != "USER") print $0}' | sort -k9 | tail -1 | awk '{print $2}' > task_3.txt

