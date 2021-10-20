str1=$1 str2=$2

if [[ -n $str1 ]]; then
	echo "str1 is not empty"
else
	echo "str1 is empty"
fi

if [[ $str1 == $str2 ]]; then
	echo "str1 str2 same"
else
	echo "str1 str2 diff"
fi

