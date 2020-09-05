read input

while [ $input != 'q' ]
do
	output+=$input
	read input
done

echo $output
