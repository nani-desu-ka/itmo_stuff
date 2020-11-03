operator="+"
result=1
plus() {
    operator="+"
}

multiply() {
    operator="*"
}
shut_down() {
    echo "exit_2"
    exit 0
}
trap 'plus' USR1
trap 'multiply' USR2
trap 'shut_down' SIGTERM
while true; do
    case $operator in
        "+")
            let "result+=2"
        ;;
        "*")
            let "result*=2"
        ;;
    esac
    sleep 1
    echo $result
done
