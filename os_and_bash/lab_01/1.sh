read first_number
read second_number
read third_number

if (( $first_number > $second_number ))
then max=$first_number
else max=$second_number
fi

if (( $third_number > $max ))
then max=$third_number
fi

echo $max
