touch emails.lst
sudo grep -r -h -E -I -o "[[:alnum:]_-]+@[[:alpha:]]+\.[[:alpha:]]+" /etc | tr "\n" ", " > emails.lst
cat emails.lst | rev | cut -c 2- | rev > temp_em.lst
cat temp_em.lst > emails.lst
rm temp_em.lst
