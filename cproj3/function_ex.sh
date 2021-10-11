string_test(){
	echo "string test"
}

# function 생략 가능
function string_test2(){
	echo "string test 2"
	echo "argument values : ${@}"
}

string_test
string_test2 "hello" "world"
