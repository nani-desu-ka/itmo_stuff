touch task_2.txt
ps a u x | grep -E '/sbin/' | awk '{print $2}' > task_2.txt
