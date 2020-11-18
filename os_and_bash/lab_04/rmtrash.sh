file=$1
version=0

if [ ! -d ~/.trash ]
then
	mkdir ~/.trash
fi

temp_file=$file-№$version
while [ -f ~/.trash/$temp_file ]
do
	version=$(echo $version"+1" | bc)
	temp_file=$file-№$version
done

ln $file ~/.trash/$temp_file
if [ -z $(grep $(realpath $file) ~/.trash.log) ]
then
	echo $(realpath $file) >> ~/.trash.log
fi
rm $file
