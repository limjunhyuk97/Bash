# 지정된 범위 내에서의 반복문 (for)
for string in "hello" "world" "..." ; do
	echo $string
done

# 수행 조건이 true일 때 실행됨(while)
count=0
while [ ${count} -le 5 ] ; do
	echo ${count}
	count=$(( ${count} + 1 ))
done

# 수행 조건이 false일 때 실행됨
count2=10
until [ $count2 -le 5 ]; do
	echo $count2
	count2=$(( ${count2} - 1 ))
done


# practice

