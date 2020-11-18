prev_backup=$(ls ~ | grep -E "^Backup-????-??-??" | sort -n -r | head -1 )
dir_made=0
new_backup=~/Backup-$(date +"%F")
backup_update=0
if [ -z $prev_backup ]
then
	mkdir $new_backup && dir_made=1
else
	if (( $(echo "($(date -d $(date +'%F') +'%s') - $(date -d ${prev_backup:7} +'%s')) / 86400" | bc) > 7 ))
	then
		mkdir $new_backup && dir_made=1
	else
		echo "Directory was not created"
	fi
fi

if (( $dir_made == 1 ))
then
	cp ~/source/* $new_backup
	echo "New backup created: Backup-"$(date +"%F")" "$(date +"%T")" "$(ls ~/source/*) >> ~/backup-report
else
	changed_files="Changed files:\n"
	new_files="New Files:\n"
	for file in $(ls ~/source)
	do
		if [ -f ~/$prev_backup/$file ]
		then
			if [[ $(stat -c "%s" ~/$prev_backup/$file) -ne $(stat -c "%s" ~/source/$file) ]]
			then
				backup_update=1
				mv ~/$prev_backup/$file ~/$prev_backup/$file.$(date +"%F")
				cp ~/source/$file ~/$prev_backup
				changed_files=$changed_files""$file" "$file.$(date +"%F")"\n"
			fi
		else
			backup_update=1
			cp ~/source/$file ~/$prev_backup
			new_files=$new_files""$file"\n"
		fi
	done
	if (( $backup_update == 1 ))
	then
		echo -e "Backup updated: "${prev_backup:7}" "$(date +"%T")"\n"$new_files"---\n"$changed_files"---\n" >> ~/backup-report
	fi
fi

