./4_helper.sh & pid_1=$!
./4_helper.sh & pid_2=$!
./4_helper.sh & pid_3=$!
renice +19 -p $pid_1

