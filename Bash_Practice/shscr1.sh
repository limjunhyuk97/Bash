# !bin/bash
# 날짜별로 파일 새로 생성

today=$(date +%Y-%m-%d)
filename="file-${today}.txt"
touch ${filename}
echo "Hello World" > $filename
echo "End" >> $filename
echo "마지막 줄은 $(tail -n 1 $filename)입니다."
