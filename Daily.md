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
- nslookup (webpage 도메인 이름) : 도메인이름에 해당하는 IP주소를 돌려준다. canonical name도 알려준다.

### 11.5
- **지식재산권(IPR. Intellectual Property Rights)**
  - 법적인 문제와 관련되어 있다.(국내법, 국제법에 따라 보호받는 권리가 다르다.)
  - **산업재산권**(특허, 실용신안, 디자인, 상표 : 국가 기관에 신청) 
    - 특허
      - 산업상 이용가능(기술적 사상), 신규성(창작), 진보성(고도) - 산업상 이용가능한 권리를 독점 - 출원일부터 20년 보호(출원 날짜부터 소급하여 보호)
      - 1)자연법칙을 이용한 발명. 2)공연히 실시되지 않은 신규의 것. 3)쉽게 발명 불가능한 진보. 4)산업상 이용 가능한 것.
    - 실용신안
      - 산업상 이용가능, 신규성, 고도의 진보까지 X - 마찬가지로 권리를 독점 - 출원일부터 10년 보호
    - 디자인
      - 공업상 이용가능, 신규성, 창작성 - 유사한 범위까지 보호 - 출원 기간으로부터 20년을 보호
    - 상표
      - 자타상품식별력이 있어야 함 - 이미 있는 명칭에 유사하지 않아야 함(부등록 사유에 해당하지 않아야 함) - 설정등록일부터 10년 보호, 10년마다 갱신 가능 
      - 상표권자는 등록한 상표를 '지정상품'에만 사용가능. 제 3자가 등록되지 않는 지정상품군에 등록된 이름을 사용할 수 있다. (DELL 아이스크림..?)
      - 등록 이전에 선점이 필요하다면 TM, 등록후에는 R이 붙는다.
  - **저작권.Copyright**(저작권, 저작인접권, **컴퓨터 프로그램** : 내 것이라고 선언) 
    - 저작권
      - 주관적인 창작이 인정되는 저작물
      - 개인이 베낀 것이 아니라 창작한 것이며, 저작자 자신의 독자적인 사상이나 감정의 표현을 담고 있어야 한다. - 저작자 생존기관 + 사후 70년 동안 보호
      - C로 선언.  
  - **신지식재산권**(반도체회로설계, 영업비밀, 퍼블리시티권, 식물신품종보호권)
    - 산업 저작권 : 컴퓨터 프로그램, 소프트웨어
    - 첨단 산업 재산권 : 반도체 설계, 영업방법, 생명공학기술
    - 정보 재산권 : 데이터베이스, 영업비밀, 뉴미디어
    - 기타 : 캐릭터, 새로운 상표, 색채상표, 맛, 소리, 퍼블리시티권(이름, 필명, 초상권 등의 특정인과 연관되어 있는 정보들) ..  
- **오픈소스와 프리소스(FOSS. Free Open Source Software)**
  - 소프트웨어가 돈을 받고 파는 물건이 된 것에 대한 역작용으로 FOSS 등장 (그렇다고 FOSS와 IPR)
  - 배타적인 저작권과 FOSS는 병립가능하다. 즉, 저작권과 source를 사용할 수 있는 권리를 허여하는 것은 동시에 성립될 수 있다.
  - **COPYRIGHT**
    - 저작권에 대해서 배타적인 권리를 갖는다.
    - 즉, 저작자의 허용 없이 사용, 수정, 배포, 복제 불가능하다.
  - **PUBLIC DOMAIN**
    - 저작자의 허가 없이 사용, 수정, 배포, 복제가 가능하다. 
  - **CREATIVE COMMON(CC)**
    - CC : 자유롭게 사용할 수 있다
    - + BY : 원작자 써야됨
    - + SA : license 변경 불가능함
    - + ND : 내용 modify, adapt 불가능
    - + NC : Commercial 사용 불가능  
  - **COPYLEFT**
    - copyright에 반대되는 개념으로, 저작권을 기반으로 하는 정보 공유를 위한 조치이다.
    - 저자에게 주어진 똑같은 자유를 작품을 소유한 사람들에게 제공하는 조치이다.
      - 결과물을 연구하고 사용하는 자유
      - 결과물을 다른 사람들과 같이 쓰고 복사하는 자유
      - 결과물을 수정하는 자유
      - 수정된 결과물(2차 저작물)을 배포할 자유
    - COPYLEFT로 배포된 결과물의 2차 결과물에 마찬가지로 COPYLEFT 라이센스를 적용할 의무를 강제할 수도 있는 문제가 발생
    - COPYLEFT로 배포된 결과물이 더이상 COPYLEFT가 아니게 된다면 문제가 발생
  - **FREE SOFTWARE**
    - 공짜를 의미하는 것이 아니다. 또한 기본적으로 open source(소스코드에 대한 접근이 선행된다.) 여야지만 free software일 수 있다.
    - 상업성에 대해서 반대
    - 1)프로그램을 어떠한 목적을 위해서라도 실행할 수 있는 자유
    - 2)프로그램의 작동원리를 연구하고, 이를 필요에 따라 변경시킬 수 있는 자유
    - 3)프로그램을 복제, 배포할 수 있는 자유
    - 4)수정한 프로그램을 복제, 배포할 수 있는 자유
  - proprietary software VS free software
 
	<p align="center"><img src="https://user-images.githubusercontent.com/59442344/140479326-f3abcdb4-a445-49fc-b3d8-1a1d9c0a1a5a.jpg" width=40% height=40%></p>

  - **OPEN SOURCE SOFTWARE**
    - 상업성에 대해서 관대함 
    - 자유 배포
    - 소스코드 포함
    - 2차 저작몰 허용
    - 원시 소스코드 유지
    - 개인 및 단체에 대한 차별 금지
    - 사용 분야에 대한 차별 금지
    - 다양한 라이선스 포괄 및, 라이선스 기술적 중립성 유지 
  - **LICENSE**
    - 저작권자가 권리 중 일부를 일정 조건으로 사용자가 사용할 수 있도록 권한을 부여하는 것이다.
    - 소프트웨어에 대해서, 저작권은 원래의 권리자에게 남아있고, 일부 사용의 권리만 타인에게 부여하는 것.
    - 모든 오픈소스 라이센스들은 원작자의 보증을 부인하고, 사용에 대한 책임을 원작자에게 부여하지 않는다.
    - Open source software를 위한 license 모델들이 존재한다.
      - BSD / MIT : 수정된 source code를 공개하지 않아도 되는 license. 공공의 이익을 위해 지정. 다른 라이선스로 변경하여 판매 가능.
      - Apache 2.0 : Apache라는 상표권을 침해해서는 안된다. 수정 프로그램의 source code를 공개해야 하는 의무 없다.
      - GPL 2.0
        - Source code 수정 시에 수정 사실, 내용, 및 그 날짜 등을 파일 안에 명시해야 한다. 새로운 source code와 link 시킬 경우 source code를 GPL로 공개해야 한다.
        - object code, running module로 배포할 때는 source code를 포함하거나, 그 source code를 제공받을 방법을 명시해야 한다.
        - 특허가 적용되었다면, 특허료를 포기한 것으로 간주.(특허료를 받을 수가 없음)
      - GPL 3.0
        - 설치에 필요한 모든 정보를 제공해야 함
        - DRM 관련해서 각국의 법률에 의해 보호되는 이익을 포기해야 함
        - 특허를 개선하여 배포한 경우에, 자신이 기여한 부분에 대해 비차별적이고 무료라는 라이선스 제공이 필수적
        - 다른 라이센스를 혼합하여 사용할 수 있다.
      - LGPL 2.1
        - LGPL 라이브러리 수정한 경우 수정한 라이브러리의 source code 공개해야 함
        - LGPL 라이브러리를 링크한 경우에는, 해당 응용프로그램은 비공개할 수 있다.  
