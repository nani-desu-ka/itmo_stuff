man bash | tr '[:upper:]' '[:lower:]' | tr '[:punct:]'  ' ' | tr -s ' ' '\n' | sort |
uniq -c | sort -n -k 1 |
awk '{if (length($2) >= 4) print $2}' |
tail -3
