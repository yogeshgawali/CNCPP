#bin/bash

display() {
	echo "=================="
	echo "Format: $format"
	echo "Name  : $name"
	echo "Season: $season"
	echo "=================="
}


name=UNKNOWN
season=1
title=UNKNOWN

while getopts :f:n:s:h: opt
do
  case $opt in
    f) format=$OPTARG;;
    n) name=$OPTARG;;
    s) season=$OPTARG;;
    h) help
       exit 1
       ;;
    :)
      echo "Option -$OPTARG requires an argument." >&2
      exit 1
      ;;
  esac
done

display

list=`ls`
list=( $list )

nof=${#list[@]}

echo "Total files: $nof"
for(( i=0; i<$nof; i++ ))
do
#echo "$i: ${list[$i]}"

done
