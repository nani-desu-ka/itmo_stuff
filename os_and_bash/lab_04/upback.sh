prev_backup=$(ls ~ | grep -E "^Backup-????-??-??" | sort -n -r | head -1 )
if [ ! -z ~/$prev_backup ]
then
	for file in $(ls ~/$prev_backup | grep -E -v "*.[0-9][0-9][0-9][0-9]-[0-9][0-9]-[0-9][0-9]")
	do
		cp ~/$prev_backup/$file ~/restore
	done
fi
