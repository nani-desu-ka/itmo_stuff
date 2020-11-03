pid=$$
operator="+"
result=1

(tail -f channel) |
while true; do
    read line;
    case $line in
        "quit")
            echo "exit_2"
	    kill $pid
            exit 0
        ;;
        "+")
            operator="+"
        ;;
        "multiply")
            operator="multiply"
        ;;
        [0-9]*)
            case $operator in
                "+")
                    let "result+=$line"
                ;;
                "multiply")
                    let "result*=$line"
                ;;
            esac
            echo $result
        ;;
        *)
            exit 1
        ;;
    esac
done
