#!/bin/bash
# 
# install.sh: Script to install biblical-texts
# 
# Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
# 
# Date: 16/10/2023

# Checking if user is root
if [[ $EUID -ne 0 ]]; then
  # Checking if the terminal suport colored text
  if [[ test -n $(tput colors) && test $(tput colors) -ge 8]]; then
    printf "\033[1;31mE:\033[m This script must be run as root\n"
  fi
  
  print "E: This script must be run as root\n"

  exit 1
fi

printf "\n#######################\n"
printf "# Installing biblical-texts #\n"
printf "#######################\n"

# Creating the documentation directory
mkdir -pv /usr/share/doc/biblical-texts

# Install the binary of software and yout autocomplete script
cp -rvf ./bin/biblical-texts /usr/bin
cp -rvf ./_biblical-texts_complete.sh /usr/share/bash-completion/completions

# Installing the configuration file of the software
cp -rvf ./biblical-texts.conf /etc

# Installing the documentation
cp -rvf ./man/biblical-texts.1.gz /usr/share/man/man1
cp -rvf ./doc/* /usr/share/doc/biblical-texts
cp -rvf ./LICENSE.gz /usr/share/doc/biblical-texts
cp -rvf ./AUTHORS.gz /usr/share/doc/biblical-texts
cp -rvf ./NEWS.gz /usr/share/doc/biblical-texts
cp -rvf ./README.gz /usr/share/doc/biblical-texts

printf "biblical-texts was installed successfuly!"

