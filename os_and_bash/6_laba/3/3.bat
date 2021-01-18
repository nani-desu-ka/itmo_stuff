net start > servicies.txt
net stop dnscache
timeout /t 5
net start > servicies_2.txt
fc servicies.txt servicies_2.txt > diff.txt
net start dnscache
