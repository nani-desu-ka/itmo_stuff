touch info.log
awk '{if ($2 == "INFO") print $0 > "info.log"}' ~/git_stuff/itmo_stuff/os_and_bash/syslog
