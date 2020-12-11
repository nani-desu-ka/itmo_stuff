rm report.log
touch report.log
declare -a array
a=1
while [[ $a -le $1 ]]
do
	array+=("1" "2" "3" "4" "5" "6" "7" "8" "9" "10")
	let a=$a+1
done
