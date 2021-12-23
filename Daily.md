## Bash command

- if [[ ]]  VS  if [ ] : 상황에 따라 다르다

- if 내부 ${} 와 $() 의 차이
  - $() : 명령어 바꿔치기. 명령을 수행하고, 수행한 결과를 $()안에 넣는다
  - ${} : 변수의 결과를 ${}안에 넣는다.
  - $(( )) : 산술연산의 결과를 묶어준다.

- if [[ -n ]]의 의미 : -n은 문자열이 empty하지 않은 경우 true 반환

- if [[ -z ]]의 의미 : -z은 문자열이 empty한 경우 true를 반환

- if [[ -e ]]의 의미 : -e 는 파일이 존재하는 경우 true를 반환

- if [[ -d ]]의 의미 : -d 는 디렉토리가 존재하는 경우 true를 반환

- argument 받기 : 함수이름 arg1 arg2 … / $# : 전달받은 인자 갯수 / $1, $2 .. : 전달받은 n번째 인자 / $@ : 전달 받은 전체 인자 (:로 전달받은 인자를 자를 수 있다)

- bash script 내 function 실행 : script를 실행시키면, 안에 있는 정보들이 해석되고 동작하는 것. 외부에서 받을 수도 있음

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

### 11.11

- 버츄얼 웹서버 만드는 것을 할것임 (듣다보니 파일의 접근권한에 대한 내용만 나옴)
- 유저에는 두종류의 유저가 있음 : 일반유저 , 슈퍼유저(root, 0번)
  - sudo su (유저명) : 유저명을 안치면 root 유저가 되고, 유저명을 치면 특정 유저가 된다.
  - whoami : 현재 유저명을 터미널에 묻는 명령어
    - 그렇다명 유저명에 대한 정보는 어디에 있는가? : /etc/passwd라는 파일에 정보가 존재한다.
    - 그 파일에 0번 이름으로 root가 존재한다.
  - sudo su -> whoami : root 라고 나온다.
  - passwd : 유저의 password를 변경하는 명령가능
    - passwd (유저명) : 유저명의 비밀번호를 바로 바꿀 수 있다.
    - man passwd : passwd 명령에 대한 정보 확인
    - man passwd로 확인
      - passwd(1) : 일반인들이 사용할 수 있는 명령
      - chpasswd(8) : superuser가 수행할 수 있는 system administration  command(8의 의미)
      - man 5 passwd : 5는 파일이라는 뜻이다.
  - home directory : user가 로그인하면, 기본적으로 그 디렉토리에 있는 상태가 된다.
  - user command interpreter : shell이다.
  - su - (username) : 특정 user로 다시 돌아갈 수 있다.
- rm * .c : 현재 디렉토리에 있는 모든 파일을 삭제하고, .c 라는 이름을 갖는 파일과 디렉토리를 모두 삭제한다.
- adduser : superuser가 할 수 있는 명령. user의 목록을 새로 추가할 수 있다.
  - adduser (guest 명)
    - 새로운 유저 들어갈 그룹 생성
    - 새로운 홈 디렉토리 생성
    - etc/skel 에서 홈디렉토리 형성에 필요한 정보를 copy 해옴.
  - adduser (guest 명) 생성 후 확인
    - cd /home/(guest 명)로 새로운 유저의 홈 디렉토리로 접근할 수 있다.
    - cat /etc/passwd : guest1: x:1001(게스트 번호):1001(그룹 번호)
- sudo login (유저명) : 특정 유저로 로그인한다. (root 비번 -> 특정 유저 비번 )
- 각각의 유저가 자신의 홈 디렉토리에서 만든 디렉토리에 다른 유저 또한 접근할 수 있다.
- ls -l 을 통해서 누가 그 디렉토리에 접근할 수 있는지 확인할 수 있다.
  - d rwx rwx r-x : 해당 디렉토리 소유한 유저, 해당 유저와 같은 그룹의 멤버, other, root 모두 접근 가능
- vi /etc/group : group들에 대한 정보를 담고 있다.
- group :  유저 그룹에 관한 명령어이다.
  - vi group 을 통해서 group: x:1001:root,guest2 .. 으로 바꾸면 group1에 root, geust2 추가하는 효과
  - 하지만 , LINUX 파일시스템에서의 버그로 인해, group 내 파일 정보를 바꾸는 것으로 유저 추가가 groups 명령으로 확인되지 않을 수도 있다.
  - su (현재 게스트명) : 현재 게스트로 다시 로그인해야 현재 게스트가 어떤 그룹에 속하는지 groups 명령어로 확인할 수 있게 된다. 즉, 버그를 해결하는 방법으로 각 유저가 로그인 상태에서 다시 su (게스트명) 명령어 쳐줘야 함.
- groups : 현재 유저가 속해있는 그룹에 대한 정보를 보여주는 명령어이다.
- 한쪽 유저가 chmod 700을 통해서 접근 권한을 바꾼다면
  - 해당 유저와 root 유저만 해당 파일이나 디렉토리에 접근할 수 있게 된다.
- chown : ‘root 유저’가 해당 파일이나, 디렉토리의 owner를 바꾸는 (소유자를 바꾸는) 명령어이다.
  - super user/administrator/root만 해당 파일/디렉토리에 대한 소유자를 바꿀 수 있다.
  - chown (다른 유저명) (특정 디렉토리/파일)
  - chown -R (다른 유저명) (특정 디렉토리/파일)
- 접근권한과 소유자명 그룹명을 바탕으로 특정 디렉토리/파일에 접근가능한 유저의 종류를 판별할 수 있어야 함
  - 접근가능하다는 것은 x라는 permission이 부여되어 있다는 것.
  - drwx------ guest1 group2
    - 소유한 사람인 guest1과 , root 유저만 들어갈수 있다.
    - group2에 대해서는 x permission이 없기 때문에, group2 유저들은 실행할 수 없다.
  - drwxrwx--- guest2 group2
    - guest2, group2에 속한 유저, root user
- 결국 파일/디렉토리에 대한 접근 권한을 변경하는 방식엔 몇가지가 있다.
  - root user가 group으로 유저들을 묶어주는 방법
  - root user가 파일의 소유자를 변경하는 방법 (root만 가능)
  - 해당 파일/디렉토리를 소유하고 있는 유저가 chmod를 통해서 권한을 바꿔주는 방법
  - 해당 파일을 소유하고 있는 그룹에 속한 유저가 chgrp을 통해서 group을 바꿔주는 방법
- 접근권한을 변경할 수 있는 대상이 되는 것은 ‘파일’이다. (리눅스 시스템에는 파일안에 디렉토리도 포함되어 있다.)
- cd/dev/pts 를 통해서 실행되고 있는 shell을 확인할 수 있다.
  - chmod 777 2 : 2 번 shell 의 접근 권한을 777로 바꾼다.
  - shell 1에서 echo “hahaha” > /dev/pts/2 : shell 2에 hahaha를 붙여 넣을 수 있다.
- /var : 데이터 양이 늘었다 줄었다 했다는 것에 대한 정보를 담고 있다.
  - 각종 활동에 대한 정보를 담고 있는 log 파일이 들어가 있다.
- super user를 제외하고는 /etc/shadow 파일을 변경할 수 없다.
  - 그런데 passwd 로 각 유저들이 자신의 비밀번호를 변경할 수 있는 것은 무엇인가
  - 즉, 비밀번호 변경에 있어서는 shadow 파일을 변경할 수 있는 것은 무엇인가
  - 명령의 실행은 root 에서 이뤄지는 것 : passwd 명령을 수행할 때는 잠시 root가 된다.
  - cd/usr/bin -> ls -l passwd : -rwsr-xr-x 에서 s 는 sticky bit라는 특수 권한을 의미한다.

### 11.18

- virtual web hosting
  - IP 주소를 다르게
  - Name을 다르게
  - Port를 바꿔서 (오늘은 port번호를 바꿔서 virtual hosting 진행)
- /var/www/html/index.html journal.md 존재..
- cd /etc/apache2/apache2/apache2.conf 를 통해서 apache에 대한 각종 option들 확인한다.
- 아파치의 포트설정 파일 열기. /etc/apache2/apache2/ports.conf 파일
  - Listen 80 설정: 80 번 포트로 들어오는 것들에 대해서 듣고 있겠다.
- 아파치의 포트설정 파일을 복제하여, 백업을 한 상태에서 변경한다.
  - editing 하다가 잘못되면 web site가 죽어버리기 때문이다.
- /etc/apache2/ports.conf 파일 내에 Listen 8081 을 추가한다.
  - 가상 머신 내 웹브라우저에서 localhost:8081 을 쳤는데 작동되지 않는다. (아직 내용이 업데이트 되지 않은 것)
  - systemctl status apache2 : apache2 가 실행되고 있는 환경 확인
  - systemctl restart apache2 : apache2 재 실행. 이를 통해서 포트 8081을 추가한 것을 update 한다.
- /etc/apache2/sites-available/000-default.conf 파일 내 새로 추가한 포트번호로 요청받을 위치 설정.
  - Document root가 /var/www/html 로 설정되어있다. 즉, /var/www/html로 호스팅 되게끔 설정되있음.
- VirtualHost \*:8081 을 추가한다.
  - 8081 포트로 요청하는 정보를 어떤 디렉토리에서 가져가라는 내용의 정보를 저장한다.
- apache2ctl configtest : config와 관련된 syntax 오류를 체크할 수 있다.
- /etc에 사용자에 대한 정보가 담겨 있다.
- ctrl + r 을 통해서 web page caching 된 정보 외에 새로운 정보를 가져올 수 있다.

### 11.25

- 공식 웹사이트를 만들 수 있는, ‘저작물 관리 시스템’인 wordpress 설치하기 (wordpress install 검색)
  - 핵심 컨텐츠는 DB로 넣어두고, 데코레이션과 리액션에 대한 내용을 한꺼번에 구성할 수 있게 도와주는 툴.
- mysql과 mariaDB 똑같음. 똑같은 명령어를 그대로 사용한다.
- 내 컴퓨터에 서버를 위한 DB 환경을 설치하고, 다른 곳에 존재하는 유저들에게 접근 및 수정권한을 주는 것은 굉장히 위험할 수 있다. 그러므로 permission에 대한 정리가 필요하다.
- cp -a :  archieve 명령으로 copy를 진행할 시에, owner, group, 변경일자 등에 대한 정보가 하나도 바뀌지 않은 채로 다른 곳으로 복사된다.
- chown, chmod, chgrp 을 통해서 파일에 대한 접근 권한을 바꿀 수 있다.
- chown -R www-data:www-data 를 쓰면, owner:gorup 한번에 바꿀 수 있다.

### ubuntu server 계정 추가 + ssh 접속 가능하게 만들기

- **출처: <https://hays99.tistory.com/117> [Thinking Warehouse]**
- sudo su 로 root 유저로 변경
- adduser new_user 로 새로운 유저 추가
  - /etc/passwd 에 새로운 유저가 추가됨
  - /home directory에 새로운 유저의 홈 디렉토리가 만들어짐
- mkdir /home/new_user/.ssh 를 통해서 .ssh 폴더를 생성
- cp /home/ubuntu/.ssh/authorized_keys /home/new_user/.ssh (ubuntu 환경 시에) 를 통해서 authorized_key 파일을 복사
- chown -R new_user:new_user /home/new_user/.ssh 를 통해서 권한을 변경
- systemctl restart ssh 또는 service ssh restart 를 통해서 ssh 서비스 재시작
- usermod -aG sudo new_user (ubuntu) 를 통해서 권한 주기
- sudo chmod 640 /etc/sudoers 를 통해서 sudoers 파일 등록 (sudo 유저로써 등록하는 것. 안해도 됨)
  - sudo vi/etc/sudoers
    - root ALL=(ALL:ALL) ALL
    - new_user ALL=(ALL:ALL) ALL
- password 묻지 않도록 설정
  - $ sudo su -
  - $ sudo cp /etc/sudoers.d/90-cloud-init-users /etc/sudoers.d/90-mysudoer
  - $ sudo chmod 640 /etc/sudoers.d/90-mysudoer
  - $ sudo vi /etc/sudoers.d/90-mysudoer
    - new_user ALL=(ALL) NOPASSWD:ALL
  - $ sudo chmod 440 /etc/sudoers.d/90-mysudoer
- ssh 접속 시에 pem 키 없이 비밀번호를 접속하도록 설정
  - $ sudo vi /etc/ssh/sshd_config
    - PasswordAuthentication : yes  로 변경 (기존 no)
  - $ sudo systemctl restart ssh     (sudo service ssh restart)  (ubuntu)

### 12.02

- df : 어떤 디스크가 사용되고 있나 확인하는 명령어
- ps -ef | grep [regex] : 실행중인 프로세스 중 regex 가 포함된 프로세스

### 12.9

- adduser 하면 /etc/passwd 바뀐다고 할 때, etc 앞에 root를 까먹지 말자.
- 무엇인가 공부하기 전에 그것이 무엇인지 정확히 정의하는 것이 중요하다 : 위키에서 찾아보는 것 좋다.
- webmin : Unix 계열 시스템을 위한 웹 기반 시스템 구성 도구이다.
- debian : 데비안 프로젝트가 개발한 자유 컴퓨터 운영체제. 우분투에서도 데비안 파일을 그대로 사용할 수 있다.
  - .deb 의 확장자를 갖는다.
  - sudo dpkg -i 확장자명.deb 으로 .deb 파일 실행 가능
    - '-i' 는 install의 약자
- ubuntu20.04 webmin install
  - dependency problem : 어떤 파일을 설치하기 위한 tool이 선행되어 설치되어있지 않은 경우에 발생한다.
  - webmin 은 perl(libio-pty-perl)을 선행으로 요구한다.
- SSL mode : 전송계층보안. 컴퓨터 네트워크에 통신보안을 제공하기 위해 설계된 암호 규약.
- .log
  - 에러, 접속, 등에 대한 기록을 담고 있는 파일 
  - /var 하위에 존재한다 : /var 에 있는 파일들은 파일 사이즈에 변동이 있을 수 있는 파일들이다.
- cron : 유닉스 계열 컴퓨터 운영체제의 시간 기반 잡 스케줄러이다.
- Biz Model Canvas 작성하는 연습하기 - 이런 주제를 갖는 item 이라면 어떤 biz model을 갖고 있을까 생각.
- GitLab, GitHub twin editing을 통해서 sync 맞출 수 있다.
  - GitLab GitHub API 사용가능
  - transifix 번역 전 상태 받아보고, 그 뒤의 상태 내가 한거 서로 비교 가능하도록 함.
  - Magenta
