lower=$1 upper=$2

# Test1 #

name="junhyuk"
num=$(echo hi there)
echo ${name} got ${num} '\n' 

# Test2 #
sum=0
echo lower = ${lower}, upper = ${upper}
for ((i=$lower ; i <= $upper ; ++i)); do
	sum=$(($i+$sum))
done
echo $sum
