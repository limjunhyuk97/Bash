# Script Test
argument=${@}

# 1. 함수에 인자 전달/꺼내기
func1(){
	echo "total parameter count : $#"
	echo "1st parameter : $1"
	echo "2nd parameter : $2"
	echo "all parameters : $@"
}

echo "--------- test 1 ---------"
func1 200 300 400 500
echo
func1 what thehell
echo 
echo


# 2. 함수에서 '값'을 반한하기
func2() {
	func_result="some results"
	local other="let it be"
}
echo "--------- test 2 ---------"
func2
echo $func_result
echo $other
echo $?


# 3. 함수에서 'return(종료상태)'를 반환하기, 빈 문자열 찾기
func3() {
	if [[ -z ${@} ]]; then
		echo "no arguments"
		return 1
	else
		echo "arguments : ${@}"
		return 0
	fi
}
echo "--------- test 3 ---------"
func3 20 300 400
func3 


# 4. script에 인자 입력 받고 함수로 실행시키기 (확장자 바꾸는 함수)
echo $argument

