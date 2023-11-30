##
# _biblical-texts_complete.sh
#
# Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
#  
# Description: My biblical-texts file
# 
# Date: 16/10/2023
# 

_biblical-texts_complete()
{
  local cur_word
  local prev_word
  local long_type_list
  local short_type_list

  cur_word="${COMP_WORDS[COMP_CWORD]}"
  prev_word="${COMP_WORDS[COMP_CWORD-1]}"

  long_type_list=`biblical-texts --help --version --trace \
    --debug-level --colored-log --conf-filename`
  short_type_list=`biblical-texts -h -v -t -l -c -C`
  
  case "$cur_word" in
    --*) COMPREPLY=( $(compgen -W "${long_type_list}" -- ${cur_word}) );;
    -*) COMPREPLY=( $(compgen -W "${short_type_list}" -- ${cur_word}) );;
  esac

  return 0
}

complete -F _biblical-texts_complete -o default biblical-texts

