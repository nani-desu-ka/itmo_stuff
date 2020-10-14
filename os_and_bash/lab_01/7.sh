touch emails.lst
sudo grep -r -h -E -I -o "[[:alnum:]_-]+@[[:alpha:]]+\.[[:alpha:]]+" /etc | tr "\n" ", " > emails.lst
