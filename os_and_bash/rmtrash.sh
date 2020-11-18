file=$1
version=0

if [ ! -d ~/.trash ]
then
	mkdir ~/.trash
fi

if [ ! -f ~/.trash.log ]
then
	touch  ~/.trash.log
fi

trashname=$file-$version
while [ -f ~/.trash/$trashname ]
do
	(( version++ ))
	trashname=$file-$version
done

ln $file ~/.trash/$trashname
rm $filename && echo $(realpath $file) $trashname >> $trashlog
