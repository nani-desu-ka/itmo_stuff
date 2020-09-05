read input
while [ -z $input ]
do
	read input
done
while [ $input != 'q' ]
do
	output+=$input
	read input
	while [ -z $input ]
	do
		read input
	done
done

echo $output
