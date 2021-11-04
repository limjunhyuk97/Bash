## Bash command

- if [[ ]]  VS  if [ ] : 상황에 따라 다르다

- if 내부 ${} 와 $() 의 차이
  - $() : 명령어 바꿔치기. 명령을 수행하고, 수행한 결과를 $()안에 넣는다
  - ${} : 변수의 결과를 ${}안에 넣는다.

- if [[ -n ]]의 의미 : -n은 문자열이 empty하지 않은 경우 true 반환

- if [[ -z ]]의 의미 : -z은 문자열이 empty한 경우 true를 반환

- if [[ -e ]]의 의미 : -e 는 파일이 존재하는 경우 true를 반환

- if [[ -d ]]의 의미 : -d 는 디렉토리가 존재하는 경우 true를 반환

- argument 받기 : 함수이름 arg1 arg2 … / $# : 전달받은 인자 갯수 / $1, $2 .. : 전달받은 n번째 인자 / $@ : 전달 받은 전체 인자 (:로 전달받은 인자를 자를 수 있다)

- bash script 내 function 실행 : script를 실행시키면, 안에 있는 정보들이 해석되고 동작하는 것. 외부에서 받을 수도 있음

- $(( )) : 산술연산을 수행하기 위해서 사용됨

- [ ] [[ ]] : [[ ]] 은 [] 명령이 확장된 버전이다.

- ${ } : 매개변수 확장

- $( ) : 명령 치환

- ‘’ “” quote
  - 단어분리, globbing 방지 기능
  - 라인 개행이나 둘 이상의 공백 유지
  - shell에서 특수기능을 하는 문자, 단어를 명령문의 스트링으로 만들기
  - 문자 그대로 스트링 강조

- find . -type f -name “…” : 하부 디렉토리에 있는 파일들 까지 싹다 긁어서 찾는다.
- fine . -type f -name “…” | while read file; do mv -v $file ${file/ / } done
  - 하부 디렉토리까지 해당 파일명 갖는 파일들 싹다 뒤져서 파일명 변경

- 리디렉션

```bash
>   <   >>

0 stdin 1 stdout 2 stderr
>&숫자 >>&숫자 (& 붙여줘야 파일명으로 인식하지 않음)
```

- 이스케이프 문자 \ 는 “” 안에서의 기능 확장을 막기 위해 사용된다.

- 스크립트 외부에서 선언된 변수에 대해서는 스크립트 내에서 바로 접근이 불가능하다.

- shell은 변수를 기본적으로 문자열로 받는다.
- 아무 것도 입력하지 않으면 숫자 0이 입력된 셈 치고 산술 연산이 가능해진다.

- wc -c : 바이트 수


### 10.28
- 컴퓨터 구성요소 : cpu memory input output storage
- 컴퓨터 시스템 구성요소 : 사용자 데이터 HW SW
- ssd, httpd (-d) : 서비스 프로토콜의 서버쪽 단에는 -d를 붙였다.
- sudo apt : super user가 되어서 install을 해라
- apt : terminal에서 그냥 install 하는 경우
- sshd : ssh server 환경을 실행시켜라.
- sudo su : super user 로서 각종 명령을 진행할 수 있다.
- $는 prompt이다. : shell이 명령받을 준비가 되었다는 것을 유저한테 보내는 것
- ps -ae | grep (프로세스): 특정 프로세스가 현재 진행중인지를 확인 가능
- ssh (parallels)@(IP address) : 내 컴퓨터 내의 ubuntu 프로세스 내로 ssh이용하여 접속.
- /etc/ssh/ssh_config.d/ : 각 종 sshd에서의 설정을 설정할 수 있다.
- sudo 명령은 해당 세션에서 한번 비밀번호를 치면, 더이상 물어보지 않는다.
- 내 컴퓨터 안의 다른 세션에 들어가는 것 = local host에 들어가는 것
- ifconfig : ip주소 및 네트워크 관련 정보 알아내기
- ubuntu vm 생성 -> terminal에서 sshd 서버환경을 위한 다운로드 -> terminal에서 httpsd 서버환경을 위한 apache 다운로드 -> index.html 페이지 변경

### 11.4
	- sudo su : super user로써 명령할 수 있다.
	- sudo su 에서 파일을 만들면 root에서 만들었다고 뜬다. 파일이나, 폴더의 삭제에 제약이 생길 수 있다.
	- apt update : 운영체제에서 사용 가능한 패키지들과 그 버전에 대한 정보를 업데이트하는 명령어다
	- apt upgrade : 내 컴퓨터에 설치된 프로그램 중 버전이 옛날인 프로그램에 대해서 최신으로 업그레이드 해라
	- fork, branch, clone 기말고사 출제
		- fork : 기존 프로젝트를 냅두고, 프로젝트를 복사하여 변경하는 것
		- branch : 기존 프로젝트 안에서 분기를 나누어서 변경하는 것
		- clone : 기존의 프로젝트를 복사하는 것
	- UBUNTU 서버 환경을 위해서 LAMP를 설치할 것이다. (Linux, Apache, MariaDB, Php, Python, Pearl)
	- systemctl status (apache2, sshd …) : apache의 동작상태를 확인하는 것.
	- systemctl stop apache2 : apache 서버를 종료함. (Unable to connect)
	- systemctl start apache2 : apache 서버를 시작함.
	- MariaDB install
		- sudo apt install mariadb-server mariadb-client : mariadb 설치
		- systemctl status mariadb : mariadb 동작상태를 확인하는 것.
		- sudo mysql_secure_installation : mariadb 관련 설정 (root 비밀번호 등..)
	- PHP install
		- sudo apt install php7.4 libapache2-mod-php7.4 php7.4-mysql php-common php7.4-cli php7.4-common php7.4-json php7.4-opcache php7.4-readline
		- sudo apt install phpmydmin : PHP myadmin install
	- 네트워크 카드 여러개를 하나의 apache 서버에 꽂을 수 있다.
	- virtual web hosting 
		- 각각의 네트워크 카드(다른 IP 주소 마다) 마다 다른 웹페이지로 호스팅해줄 수 있다.
		- 
	- nslookup (webpage 도메인 이름) : 도메인이름에 해당하는 IP주소를 돌려준다. canonical name도 알려준다.
