rm -r ~/test
mkdir ~/test && {
	file=$(date +"%c")
	touch ~/test/"$file"
	echo "catalog test was created successfully" >> ~/report
};
ping -c1 "www.net_nikogo.ru" || {
	error=$(date +"%D")
	error+=" "
	error+=$(date +"%c" | awk '{print $5}')
	error+=" Сайт недоступен"
	echo $error >> ~/report
}
