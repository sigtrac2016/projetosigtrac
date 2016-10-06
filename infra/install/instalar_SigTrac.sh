#!/bin/bash


apt-get install dialog


dialog --yesno 'Atualizar o Linux?' 5 40 
	 if [ $? = 0 ]; then 
		clear; 
		apt-get update
        	apt-get upgrade	 
	fi

dialog --yesno 'Instalar Standard system utilities?'  5 40 
	 if [ $? = 0 ]; then 
		clear;
        	apt-get install aptitude vim manpages dnsutils bsdmainutils psmisc python3-gdbm ufw dosfstools ed telnet powermgmt-base ntfs-3g ubuntu-release-upgrader-core iputils-tracepath groff-base bind9-host mtr-tiny bash-completion mlocate tcpdump geoip-database install-info irqbalance language-selector-common friendly-recovery command-not-found info hdparm man-db lshw update-manager-core apt-transport-https accountsservice command-not-found-data time ltrace parted popularity-contest strace ftp ubuntu-standard lsof glances ssh-keygen
	 fi

SERVER=$( dialog --stdout --title 'Qual Servidor'        \
        --menu '\nQual servidor esta instalando?\n\n'  \
        0 0 0                                    \
        API_WEB        'SERVIDOR 1 - API + WEB'  \
        BROKER         'SERVIDOR 2 - BROKER'     \
        BANCO_DADOS    'SERVIDOR 3 - BANCO DE DADOS' \
        PROCESSAMENTO  'SERVIDOR 4 - PROCESSAMENTO ' ) 



users=$( dialog --stdout --separate-output --title 'Criar Usuários'        \
   	--checklist '\nQuais Usuários deseja criar?\n\n'  \
   	0 0 0                                    \
   	1  'Time Scrum 01 - ts01'      off    \
	2  'Time Scrum 02 - ts02'      off    \
	3  'Time Scrum 03 - ts03'      off    \
	5  'Time Scrum 05 - ts04'      off    \
	6  'Time Scrum 06 - ts05'      off    \
	7  'Time Scrum 07 - ts06'      off    \
	8  'Time Scrum 08 - ts07'      off    )


echo "$users" | while read USERID
do

	clear
	echo "##########################################"
	echo "##				        ##"
	echo "## Criando Conta do TIME 0$USERID             ##"
	echo "##                                      ##"
	echo "##########################################"

	USER="ts0$USERID"
	if grep -qs $USER /etc/passwd; then continue; fi

	useradd -s /bin/bash -m -d /home/$USER -c "SIG-TRAC - $USER"  -u 800$USERID  $USER

	sudo -u $USER mkdir /home/$USER/.ssh
	sudo -u $USER ssh-keygen -f /home/$USER/.ssh/key#$USER#$SERVER
	sudo -u $USER cat /home/$USER/.ssh/key#$USER#$SERVER.pub >> /home/$USER/.ssh/authorized_keys

	echo $USER >> .tmpUser


done

dialog --yesno 'Configurar o sudo'  5 40
         if [ $? = 0 ]; then
                clear
		cp /etc/sudoers /etc/sudoers.old
		sed "s/@TIMES/User_Alias      TIMES=$(cat .tmpUser | sed ':a;$!N;s/\n/, /;ta;')/g" ./files/sudoers > /etc/sudoers
	 fi

rm -fr .tmpUser

