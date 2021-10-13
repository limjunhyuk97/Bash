# global scope variable
string="Lim jun hyuk"
echo string
echo $string

# local scope variable
string_test(){
	# variable with same name declared as local variable
	local string="Lim jun hyuk local"
	echo ${string}
}

string_test

echo ${string}
