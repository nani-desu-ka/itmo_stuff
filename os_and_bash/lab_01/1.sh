read max

for ((i=0; $i<2; i++))
do
	read input
	if (( $input > $max ))
	then
		max=$input
	fi
done

echo $max
