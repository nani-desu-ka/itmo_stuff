man bash | tr '[:upper:]' '[:lower:]' | tr '[:punct:]'  ' ' | tr -s ' ' '\n' | sort | uniq -c | sort -n -k 1 | tail -3
