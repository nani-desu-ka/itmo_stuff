file=$1
ver=0

selected_file=none
temp_file=$1-№$ver

while [ -f ~/.trash/$temp_file ]
do
	echo "Untrash "$temp_file"? (y/n)"
	read input
	if [[ $input == "Y" || $input == "y" ]]
	then
		selected_file=$temp_file
		break
	fi
	if [[ $input == "N" || $input == "n" ]]
	then
		(( ver++ ))
		temp_file=$1-№$ver
		continue
	fi
	echo "Wrong input. Try again"
done

if [ $selected_file != "none" ]
then
	temp_path=$(grep $file ~/.trash.log)
	if [ -d ${temp_path%$file} ]
	then
		if [ -f $temp_path ]
		then
			echo "Change file name"
			read input
			temp_path=${temp_path%$file}$input
		fi
		ln ~/.trash/$selected_file $temp_path
	else
		ln ~/.trash/$selected_file ~/$file
		echo "Untrashed to home dir"
	fi
	rm ~/.trash/$selected_file
else
	echo "File not found"
fi
