touch full.log
awk '{if ($3 == "(WW)") print $0}' ~/git_stuff/itmo_stuff/os_and_bash/X.log | sed 's/(WW)/Warning:/' > full.log
awk '{if ($3 == "(II)") print $0}' ~/git_stuff/itmo_stuff/os_and_bash/X.log | sed 's/(II)/Information:/' >> full.log
