# Shell basics

- [reference](https://mug896.github.io/bash-shell/basics.html)

## 1. shell의 동작

- shell은 "실제 명령 -> 실행될 명령"으로 변환
- 프로세스를 생성 -> exec 시스템 콜 함수에 인수 전달 ->  명령 실행

```sh
num=3 str=hello

# mycomm <- mycomm.c
#include <stdio.h>

int main(int argc, char *argv[]){
	for (int i = 0 ; i < argc; i++)
		printf("arg%d : %s\n", i, argv[i] );
	return 0;
}

# 입력 : ./mycomm {1..3} $(( 1 + $num )) "$(echo $str)"
# 실제 입력 : mycomm 1 2 3 4 hello
```

## 2. 명령문 작성 규칙

- 단어분리, globbing : 변수, 명령치환은 quote하지 않고 사용할 때 유의해야 함

### 2.1 파일명 작성

- **파일명이 곧 명령 이름**
- NUL, / 문자 제외하고 파일이름으로 사용가능

### 2.2 공백 작성

- **명령과, 따라오는 각 인수들은 공백으로 분리하여 작성**한다.
- 단, **대입 연산에 대해서는 공백없이 붙여서 사용해야 한다**
- 대입 연산 외에는 모두 공백으로 구분하여 적어주자

```sh
# 명령의 작성
command arg1 arg2 arg3 ...

# '[' 는 마지막에 ']'를 붙여야 하는 명령이다. 즉, '[' 뒤 와 ']' 앞 부분에 전달하는 인수와 띄어써야 함
[ 10 -eq 10 ]; echo $?  # 0(true)
[ a=b ]; echo $?        # 0(true)  - a=b가 하나의 인수로 전달
[ a = b ]; echo $?      # 1(false) - a = b의 조건문 으로 인식됨
{echo 1; echo 2;}       # error    - {echo 가 하나의 명령으로 인식됨
AA=10; echo $AA         # 10       - 대입연산은 붙여주어야 함
```

### 2.3 참과 거짓

- shell에서는 (0) : 참(정상종료), (그 외의 수) : 거짓(오류발생)
- $? : 명령 종료 시의 상태 값을 나타낸다.

```sh
# $? 와 함수의 종료상태

# 첫 인자를 그대로 종료상태로 돌려주는 함수 작성
func() { return $1; }

if func 0; then echo true; else echo false; fi  // true
if func 1; then echo true; else echo false; fi  // false
```

### 2.4 return

- 2.3에서 살펴봤듯이 **shell에서 return 명령어는 종료 상태의 값을 지정**한다.
- **stdout 출력과 return 값은 다르다.**

```sh
# return 의 사용

func() { expr $1 + $2; return 5; }

# stdout 출력 : 3
func 1 2

# 종료 상태 : 5
echo $?

# stdout 출력이 연산 결과 값이 된다 : 3
AA=$((func 1 2))
echo $AA
```

### 2.5 명령 종료 문자

- 문장 끝에 반드시 ; 를 붙일 필요는 없다 (라인 개행을 알아서 인식)
- **개행 없이 연이어 명령을 작성할 경우 ; 를 붙여야** 한다.
- **명령 grouping 위해 { } 로 묶는 경우 { } 내부 마지막 명령덩이에 ; 를 붙여야** 한다.

```sh
for i in {1...3}
do
  echo $i
done

# 1. 한줄에 적기. ; 로 구분.
for i in {1...3}; do echo $i; done

# 2. 명령 grouping 에서 ; 로 구분.
{ echo 1; echo 2; }
```

### 2.6 shell 메타문자 ( ) 는 제외

- **( )** 메타 문자는 **subshell을 실행**시키기 위해서 사용한다. (현재 shell의 자식 프로세스를 실행시키는 역할 수행)
- **( ) 의 subshell 안에서는..**
  - **( 뒤에 공백을 반드시 두지 않아도 된다.**
  - **) 앞에 ;를 반드시 붙이지 않아도 된다.**

```sh
(echo 1; echo 2)
# 1 개행 2 출력
# { }의 명령어 grouping 과 다른 subshell의 형성이다.
```

### 2.7 Escape

- shell 에서 제공하는 **키워드 / 메타문자 / glob문자 와 동일한 문자가 사용**되면..
  - **escape** : \ 를 이용하여
  - **quote** : ' ', " " 를 이용하여
  - 둘 중 하나 사용하여 스트링으로 만들어 주어야 오류가 발생하지 않는다.
- [shell 키워드](https://doitnow-man.tistory.com/276)
- [shell 메타문자](https://velog.io/@kyy00n/Shell-Special-Characters-Metacharacters-%EC%9E%90%EC%A3%BC%EC%93%B0%EB%8A%94-%EC%89%98-%ED%8A%B9%EC%88%98%EB%AC%B8%EC%9E%90%EB%A9%94%ED%83%80%EB%AC%B8%EC%9E%90-%EC%A0%95%EB%A6%AC)
- [glob 문자](https://mug896.github.io/bash-shell/exp_and_sub/filename_expansion.html)

```sh
# 1. glob 문자(*, [], ? 중 *)가 포함되어 escape 진행 한 뒤 expr 이용한 연산 진행 
# 아래 모두 12를 출력함
expr 3 \* 4
expr 3 '*' 4
echo "`expr 3 \* 4`"
echo $((3 * 4))

# 2. meta 문자(> , < 는 redirection 을 위한 문자) escape 요구
expr 3 \> 4

# 3. meta 문자( (), ;) escape 요구
find * \( -name "*.bak" -or -name "*.log" \) -exec rm -f \;
```

### 2.8 '단어분리 방지' quote

- **공백이 존재하는 변수나 명령치환을 출력**할 때 **quote 하지 않으면 단어가 분리**된다.
- 그러므로 공백이 존재하는 변수의 출력이나, 명령 치환을 사용할 때 quote 해주어야 한다.
- **근데 내 zsh에서는 단어분리가 일어나지 않는다..!**

```sh
dir="01 02"
cd $dir       # "01" 이라는 폴더로 이동
cd "$dir"     # "01 02" 이라는 폴더로 이동

# 내 zsh에서는 $dir로도 01 02 폴더로 이동하던데..
# 공백이 존재하는 변수나 명령치환에서는 어쩄든 " " quote로 감싸주는 것이 오류를 줄이는 길일 수도 있다.
```

### 2.9 'Filename Expansion (Globbing) 방지' quote

- **변수나 명령치환을 quote하지 않고 사용할 경우** glob 문자가 포함되면 globbing 발생 가능
- 2.8과 마찬가지로 globbing 발생 안하는 것 같은데, 어쩄든 globbing 방지를 위해서 선제적으로 quote 해주기

```sh
AA="User-Agent: *"

echo $AA      # globbing 발생 가능
echo "$AA"    # globbing 발생 안함
```

## 3. 기타.

### 3.1 명령의 옵션

- short form : - 시작. 하나의 문자
- long form : -- 시작. 여러개의 문자

short form | long form
:--:|:--:
-h | --help
-o value | --option=value
-axjf (합쳐서 표기 가능) | (합쳐서 표기 불가능)

- **이미 존재하는 특정 옵션과 인수의 이름이 겹치는 경우 -- 로 구분**
- **변수를 명령의 인수로 사용할 경우, '-- 로 구분 권장' + 'quoting으로 감쌀 것 권장'**

```sh
grep -r -- "-n"
# stdin 에서 -n 이라는 문자열을 찾아낸다.
```

### 3.2 STDIO 나타내는 '-'

- stdin 으로 '-' 사용하는 경우

```sh
echo hello world | cat -
echo hello world | cat
# hello world

cat <<< 1111 > test.txt
echo hello world | cat - test.txt
# hello world
# 1111

seq 10 | paste - - -
# 1 2 3
# 4 5 6
# 7 8 9
# 10
```

- stdout 으로 '-' 사용하는 경우

```sh
# dir1 디렉토리 이하 모든 파일들을 tar 압축하여 stdout 으로 출력하면
# split 명령이 stdin 으로부터 받아서 100M 크기 파일로 분리해 저장합니다.
$ tar czv -f - dir1 | split -d -b 100M - tardisk

# cat 명령에 의해 tardisk00, tardisk01 ... 파일들이 모두 합쳐져서 stdout 으로 출력되면
# tar 명령이 stdin 으로부터 받아서 extract 합니다.
$ cat tardisk* | tar xvz -f -     # 여기서 '-' 는 stdin
```

### 3.4 Shell 에서 $ 이용한 확장

- **${ } 매개변수 확장**
  - ${ } : 매개변수 확장
  - { } : 명령 grouping, 문자열 집합
- **$(( )) 산술확장**
- **$( ) 명령치환**
  - $(( )) : 명령치환
  - ( ) : subshell


### 3.5 주석

- \# 앞에 공백이 있을 때, \# 뒤를 공백으로 처리한다

```sh
#echo 1234  # 전체 문장이 주석처리 된 것
echo 12#4   # 12#4 출력
echo #1234  # 출력 X
```