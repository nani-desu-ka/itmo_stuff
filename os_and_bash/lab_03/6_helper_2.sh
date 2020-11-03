while true; do
    read line
    case $line in
        "term")
            kill -SIGTERM $1
            echo "exit_1"
            sleep 1
            exit 0
        ;;
        "+")
            kill -USR1 $1
        ;;
        "*")
            kill -USR2 $1
        ;;
    esac
done
