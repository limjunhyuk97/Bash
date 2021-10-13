# 인자를 입력받으면 $1 $2 .. 순서로 인자를 넘겨받게 된다.
commonfilename=$1
echo "swtich file name to $commonfilename"

# 파일을 올린 날짜를 자동으로 오늘로 설정해준다.
today="KakaoTalk_Photo_$(date +%Y)-$(date +%m)-$(date +%d)"
echo "today is $today"

# 각 파일들을 바꾸는 과정
## ${name} : name이라는 변수에 들어있는 값으로 치환한다.
## ./${today}* : 현재 디렉토리에 존재하는 today 변수값을 갖는 파일들 전부 선택
## mv "$i" : 파일명이 몇개의 단어로 나눠져 있을 때 " "로 묶어줘서 단어 분리 방지
## ${commonfilename}_${cnt}.jpeg : 매개변수 확장으로 파일명 지정
cnt=1
for i in ./${today}*; do
	mv "$i" ${commonfilename}_${cnt}.jpeg
	cnt=$(($cnt+1))
done	

