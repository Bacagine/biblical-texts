#!/bin/bash
# 
# uninstall.sh: Script to uninstall biblical-texts
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

if test -f /usr/bin/biblical-texts; then
  printf "#########################\n"
  printf "# Uninstalling biblical-texts #\n"
  printf "#########################\n"

  # Creating the documentation directory
  rm -rv /usr/share/doc/biblical-texts

  # Install the binary of software and yout autocomplete script
  rm -rvf /usr/bin/biblical-texts
  rm -rvf /usr/share/bash-completion/completions/_biblical-texts_complete.sh 

  # Installing the configuration file of the software
  rm -rvf /etc/biblical-texts.conf

  # Installing the documentation
  cp -rvf /usr/share/man/man1/biblical-texts.1.gz
  cp -rvf /usr/share/doc/biblical-texts

  printf "\nbiblical-texts was uninstalled successfuly!\n"
elif
  # Checking if the terminal suport colored text
  if [[ test -n $(tput colors) && test $(tput colors) -ge 8]]; then
    printf "\033[1;31mE:\033[m biblical-texts is not installed!\n"
  elif
    printf "E: biblical-texts is not installed!\n"
  fi

  printf "Nothing to do\n"

  exit 1
fi

