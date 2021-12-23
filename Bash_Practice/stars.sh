stars=$1
for (( i=1; i<=$stars ; ++i )); do
	for (( j=0 ; j<$i ; ++j )); do
		printf "*"
	done
	printf "\n"
done
