# "주석처리"
: << 'END'
for ((i=5; i<10; ++i)); do
	touch file${i}.sh
done

for i in {1..4}; do
	touch file${i}.sh
done
END

echo $date
