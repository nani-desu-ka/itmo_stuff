touch task_1.txt
touch helper_1.txt
top -b U just -n 1 | awk -e '$1 ~ /^[0-9]/ {print $0}' | tr -s ' ' > helper_1.txt
cat helper_1.txt | wc -l > task_1.txt
cat helper_1.txt | awk '{print $1":"$12}' >> task_1.txt
rm helper_1.txt
