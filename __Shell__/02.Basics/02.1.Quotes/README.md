# Quotes

- [reference](https://mug896.github.io/bash-shell/quotes.html)



## 1. Quote의 용도

- shell 에서는 number와 string을 구분하기 위해 '', "" 사용하는 것 아니다.
- **공백으로 분리되는 여러개의 string을 하나의 인수로 묶기 위해** (개행, 둘 이상의 공백을 유지하기 위해서)
- **단어분리, globbing을 방지**하기 위해서 (02.Basics에서 다룸)
- **shell 키워드, 메타문자, glob 문자 등의 특수기능 문자들을 단순한 명령문 string으로 만들기 위해서**
- **스트링 강조**하기 위해서

```sh
# 명령이 실행될 때에는 quote가 제거된 후 인수가 전달 됨

-------------------------------------

# args.sh
echo arg1 : "$1"
echo arg1 : "$2"

# args.sh 실행
./args.sh 111 222     
./args.sh "111 222"   

AAA="111 222"
./args.sh $AAA
./args.sh "$AAA"

-------------------------------------

# sed : 필터링, 텍스트 변환 위한 스트림 편집기. (특정 파일에서의 스트림 변환) 원본 변화없이 출력 변화
sed -n ' 1p; 2p; ' file.txt
sed -n ' 1, 6p' file.txt

-------------------------------------

# 아래 세가지는 차이가 없다. (명령문은 해석 된 뒤에 실행되므로)
ls -ali
ls "-lai"
'ls' "-ail"
```



## 2. 특수 기능을 갖는 문자들

문자 | 기능
--|--
$ | 매개변수 확장, 산술 확장, 명령치환
` | 명령치환
! | history 확장 (prompt 에서만)

- 매개변수 확장 : 변수 길이, 변수치환, 등..
- 산술 확장 : 현재 shell에서 $(( )) 로 연산 진행. 현재 shell의 값 변경 가능.
- 명령치환 : subshell에서 $( ) 로 연산 진행. 실행결과인 stdout 값이 pipe를 통해 전달됨.
- history 확장

### 2.1 특수기능을 갖는 문자, 단어의 escape 처리

- \, ' ' 문자로 escape 가능

```sh
find * -type f '(' -name '*.log' -or -name '*.bak' \) -exec rm -f {} \;

# &는 background process 생성할 때 사용한다.
echo hello '&'

# escape 문자 \ 의 기능을 제거
echo hello world | tr ' ' '\'n
```



## 3. No Quote

- quote 상태 X : escape O
- quote 상태 O : escape X

```sh
# abcd !@$%^&*(){}[]<>/\
echo \a\b\c\d\ \!\@\$\%\^\&\*\(\)\{\}\[\]\<\>\/\\
```

```sh
# quote 가 끝나지 않은 것으로 뜬다
echo '
```

```sh
# quote가 escape 처리 된다.
echo \'
```

- **둘 이상의 whitespace 문자가 붙어있다면 single space로** 줄어든다. 즉, **\를 사용하여 공백 수 의도대로 유지 가능**

```sh
# 공백(whitespace)도 escape 가능하다.
# 인자 2개 들어감
./args.sh 1234' '45
./args.sh 1234\ 45
# 인자 1개 들어감
./args.sh 1234 45

# /로 공백 수 유지 가능
echo hello\ \ \ \ world
```

- \ 문자 escape 위해서 \\\ 사용 가능

```sh
# tab
echo hello\\tworld

# newline
echo hello\\nworld
```

- ! history escape 위해서 \! 사용가능

```sh
# !! 는 이전 명령을 불러온다.
echo hello!!

# /!! 로 escape
echo hello\!!
```

- 행의 마지막에 \ 붙이고 개행하면, \\\n 의 효과를 갖게 된다. (backslash-newline)

```sh
# I like what Ilike
echo I like \
what  I\
like
```

- 대입연산에서도 escape는 처리된 후 대입된다. (실제 명령 -> 실행될 명령으로의 변환)

```sh
# whh
regex=\w\h\h
echo $regex
```



## 4. Double Quote (" ")

- 내부에서 **특수기능을 하는 문자들($, `, !)이 해석되어 실행**된다.
- 내부에서 공백과 개행이 유지된다.

```sh
# 내부 특수 문자 유지
AA="$((2+3)) is five"
echo $AA

# 공백과 개행의 유지
AA="hello!    this
is jun h yuk"
echo $AA
```

### 4.1 double quote에서 escape 할 수 있는 문자

- **" $ ₩ \ newline** 은 \로 escape 할 수 있다.
- ! 를 이용한 command history 확장 또한 일어난다.

```sh
# single qoute : quote \(개행)single
echo 'quote \
single'

# double qoute : quotedouble
echo "quote\
double"
```

### 4.2 array와 quote

- ${arr[@]} : "${arr[0]}" "${arr[1]}" "${arr[2]}" ...
- ${arr[\*]} : "${arr[0]}X${arr[1]}X${arr[2]}X..."
  - X = $IFS 변수값의 첫 번째 문자

### 4.3 null 변수("")에 대한 quote

- 변수 확장의 측면
  - **$변수**로 변수확장 : null로 들어감
  - **"$변수"**로 변수확장 : 공백("")으로 들어가서 문제 발생시킬 수 있음
  - 내가 쓰는 zsh에서는 quote 하든, 안하든 null로 들어가는 것 같김 함..

```sh
# args.sh
echo "All params = $@"

echo "Loop All params!"
for i in $@
		do
				echo "$i"
		done
```



## 5. Single Quote ('')

- 문자들을 있는 그대로 표시한다.
- escape 따위도 일어나지 않는다.

```sh
$ echo '$AA world 
> `date` 
> \$AA
> '
$AA world 
`date` 
\$AA
```

- 대신 안에서 ' 쓰려면 : '(문자열..)' + \\' + '(문자열..)' 

```sh
$ echo 'foo'\''bar'
foo'bar

$ echo 'foo'"'"'bar'
foo'bar
```

### 5.1 command string / trap handler에서 사용

```sh
AA=100

$ sh -c "AA=200; echo $AA"
100

$ sh -c 'AA=200; echo $AA'
200
```