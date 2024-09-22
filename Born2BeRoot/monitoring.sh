#!/bin/sh
wall "
    #Architecture: $(uname -a)
    #CPU physical : $(nproc)
    #vCPU : $(cat /proc/cpuinfo | grep processor |  wc -l)
    #Memory Usage: $(free -m | grep Mem | awk '{print $3}')/$(free -m | grep Mem | awk '{print $2}')MB $(free -m | grep Mem | awk '{printf("%.2f%%"), $3/$2100}')
    #Disk Usage: $(df -Bm | grep '^/dev/mapper' | awk '{avail += $4} END {print avail}')/$(df -Bg | grep '^/dev/mapper' | awk '{all += $2} END {print all}')Gb $(df -Bm | grep '^/dev/mapper' | awk '{used+=$3} {all+=$2} END {printf("(%d%%)"), used / all 100}')
    #CPU load: $(top -bn1 | grep '^%Cpu' | cut -c 11- | awk '{printf("%.1f%%"), $1 + $3}')
    #Last boot: $(who -b | awk '{print $3}') $(who -b | awk '{print $4}')
    #LVM use: $(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
    #Connections TCP : $(netstat -ant | grep ESTABLISHED | wc -l) ESTABLISHED
    #User log: $(who | wc -l)
    #Network: IP $(hostname -I) ($(cat /sys/class/net/*/address | head -n 1))
    #Sudo : $(journalctl -q _COMM=sudo | grep COMMAND | wc -l) cmd"
