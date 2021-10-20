num1=$1 num2=$2

if [[ num1 == num2 ]]; then
	echo "num1 == num2"
	echo "num1 == num2" >> result.txt
elif [[ num1 > num2 ]]; then
	echo "num1 > num2"
	echo "num1 > num2" >> result.txt
else
	echo "num1 < num2"
	echo "num1 < num2" >> result.txt
fi

