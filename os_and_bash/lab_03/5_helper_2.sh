while true; do
    read line
    if [[ $line != "+" && $line != "multiply" && ! $line =~ [0-9]+ && $line != "quit" ]]; then
        echo "Incorrect input"
	continue
    fi
    echo $line > channel
    if [[ $line == "quit" ]]; then
        echo "exit_1"
        exit 0
    fi
done
