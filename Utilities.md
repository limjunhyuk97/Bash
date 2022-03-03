# Basic System Utiliy set

- [Reference](https://www.gnu.org/software/bash/manual/bash.html)





## Linux 운영체제의 구조

- Linux Shell (bash, tcsh, zsh, pdksh)
- System Utilities (cat, ls, date, ps, kill, who)
- System Call (Interface)
- Linux (Kernel)
- Hardware

### Linux 계층

<p align="center"><img src="https://user-images.githubusercontent.com/59442344/156514816-98fef483-fe69-47ff-a649-43f4054a0d2d.png" width="50%"></p>

### Linux kernel

<p align="center"><img src="https://user-images.githubusercontent.com/59442344/156515124-d78feb83-d1fe-4e4b-8cc1-f1da0b45d67e.png" width="50%"></p>





## Terminal, Shell, 명령어

- Linux Shell 을 통해서 System Utility의 명령어들을 실행시킨다.
- Terminal을 통해서 Linux Shell을 실행시킨다.
- Terminal과 Shell과 Prompt
  - Terminal : mainframe에 연결되어 있는 단말기들
  - Shell : Terminal에서 명령어를 받아들이는 프로그램 (command interpreter)
    - stdin을 통해서 (키보드를 통해서) input 입력
    - stdout을 통해서 (화면을 통해서) output 입력
  - Prompt : Shell을 실행시키면 prompt화면을 띄운다.
  - 즉, **Terminal이 시작되면 login 프로그램이 실행되고, Shell이 실행되고, prompt를 보여준다.**
    - Git Bash: Terminal 안에서 실행되는 Git Bash Shell 프로그램
    - Cygwin64 Terminal : Cygwin64 Terminal안에서 실행되는 Bash Shell 프로그램
- standard stream
  - stdin : keyboard 통한 입력
  - stdout : display 통한 명령 결과 출력
  - stderr : display 통한 에러 출력
  - 각각 양의 정수번호(File Descriptor, FD)에 의해 처리되는데, stdin 0, stdout 1, stderr 2의 번호로 처리된다.





## Linux 파일 시스템(Directory 구조)

- /(슬래쉬)로 구분되어있다.
- .으로 시작하는 이름을 가진 파일이나 디렉토리는 숨겨진 디렉토리이다.
- . : 디렉토리 자신을 의미한다
- .. : 상위 디렉토리를 의미한다
- / : root 디렉토리
  - 예) /usr/local/bin/python3.10
- ~ : home 디렉토리





## Linux 파일 권한

### Linux 파일 시스템과 접근 권한

- **Linux**는 **여러 사용자들이 함께 사용할 수 있는 운영체제**이다. (멀티유저 시스템)
  - 그러므로, 읽기, 쓰기, 실행 권한을 어떻게 설정할 것인지에 대한 내용이 파일, 디렉토리마다 필요하다.
  - **소유권** : 어떤 파일이나 디렉터리를 소유하고, 지배하는 권리
  - **허가권** : 파일이나 디렉터리에 접근권한을 설정하는 권리

### 권한(퍼미션)과 i-node 번호 (ls -ali)

- 8310885(1) -rwx------(2)  1(3) limjunhyuk(4)  staff(5)   786 10 14(6) 00:11(7) change_name.sh(8)
- **(1) : 파일의 inode 번호**
- **(2) : 파일 타입, 권한(퍼미션)**
- **(3) : 링크 수**
- **(4) : 소유자 정보**
- **(5) : 소유그룹 정보**
- **(6) : 파일 용량**
- **(7) : 파일 생성 날짜**
- **(8) : 파일 이름**

### 권한(퍼미션)

- 0(1) 000(2) 000(3) 000(4)
  - (예) -rw-r--r--@
  - (예) drwxr-xr-x
- **(1) : 파일의 종류**
  - **일반 파일** (**-**)
  - **디렉토리 파일** (**d**)
  - 장치 파일(device file)
    - **block device file** (**b**) : block device를 가리킨다.
    - **character device file** (**c**) : character device를 가리킨다.
    - character device : 키보드, 마우스, 모니터, 터미널 등등의 장치를 가리키며, character 단위로 데이터를 전송한다.
    - block device : 하드디스크, CD/DVD 등의 장치를 말하며, block 단위로 데이터를 전송한다.
  - symbolic link 파일 (**l**)
- **(2), (3), (4) 의 r, w, x : 접근 권한의 종류**
  - r, w , x
  - x : 실행권한이다. 디렉토리에 들어가거나, 파일을 실행시키기 위해서는 실행권한이 필요하다.
  - w : 작성권한이다. 파일이나, 디렉토리를 만들기 위해서 필요하다.
  - r : 읽기권한이다. 파일을 읽거나, 디렉터리 안의 내용물 리스트를 보여준다.
- **(2) : 소유자에게 적용되는 권한**
- **(3) : 특정 그룹에게 적용되는 권한**
- **(4) : 그 외의 사용자들에게 적용되는 권한**

### 권한의 변경

- chmod, chown, chgrp





## Linux home 디렉토리 내 숨김 파일

- .zsh_history : 이전 shell 실행까지 실행되었던 명령들이 저장되어 있다.





## rc 파일

- bashrc , zshrc ..
- 처음 terminal, shell이 실행될 때의 환경설정에 대한 내용을 담고 있다.





## Linux 명령어 (File System)

- System Utility에 기본 명령어들이 들어있다.
- 공통적인 명령어들은 coreutil에 정리되어 있다.
- ‘*’ : wild card이다.
  - 현재 디렉토리에 있는 모든 것을 가리킬 때 사용할 수 있다.
- '-r' : recursively sub-directory까지 들어가서 명령을 수행한다.
- '--help' : 명령에 대한 내용들을 볼 수 있다.
- 'v' : 발생한 에러들을 모두 report하게 한다.
  - (예) tar -cvf archieve.tar *
- ';' : ; 로 구분되어 있는 명령어들을 순서대로 수행한다.
- !! : 가장 최근 명령어를 다시 실행시킨다.
- !(문자열) : 특정 문자열로 시작하는 가장 최근에 실행된 명령을 실행시킨다.
  - (예)) history 상에서 ls -al, cat ..., cc ... 순으로 명령이 실행된 기록이 있을 때, !c를 입력하면 cat ... 명령이 다시 실행되고, !cc를 입력하면 cc ... 명령이 다시 실행된다.
- !(명령번호 n) : history 상에서 n 번째로 실행되었던 명령이 다시 실행된다.
  - (예) history 명령으로 1006번째 명령으로 ls 명령어가 실행됨을 확인한 뒤에, !1006을 입력하면, ls 명령이 다시 실행된다.
  - !$ : 여기서 $는 마지막 명령의 return 값을 parameter로 갖고 있고, 해당 vj
- ctrl + c : kill
- ctrl + z : suspend
- ctrl + d : End Of Text (파일의 맨 끝에도 들어있음)
- **shell에서**는 **에러가 없는 경우가 0**, **에러가 있는 경우가 0이 아닌 값** 이다.
- ^(문자열1)^(문자열2) : 위에서 입력했던 명령의 특정 (문자열1)을 (문자열2) 로 바꿔준다.
- $(변수) : 특정 값을 갖고 있는 변수
- $? : 최근 실행한 명령어의 종료 스테이터스를 가진 변수이다.
  - (예)a.out 의 실행결과 return이 0이면 true!

### date : 날짜를 보여주는 명령어

### tty : 각 터미널 디바이스에 해당하는 고유번호를 알려준다. (Teletype)

- 다른 터미널 디바이스의 번호를 알게 되면, 다른 터미널 디바이스에 명령을 부여할 수 있게 된다.

### ls : 현재 디렉토리에 있는 파일의 리스트를 보여줌

- ls -l : 파일들에 대한 정보를 더 상세하게 보여줌 (가장 최근에 파일에 접근한 시간)
- ls -l (directory 위치)/ : 특정 directory의 하부에 존재하는 파일 및 디렉토리를 보여줌
- ls -li (directory 위치)
- ls -al / ls -la: 숨겨져있는 파일들에 대한 정보까지 모두 확인
- ls -al (파일 / 디렉토리명 일부)* : 해당 일부를 갖는 (파일 / 디렉토리 하부 목록들) 목록을 보여준다.
  - 예) ls -al .ba* : .bash_profile, .bash_profile.swp, .bash_profilew 3가지를 보여줌
- ls -al (directory 위치)/ : 특정 directory의 하부에 존재하는 파일 및 디렉토리를, 숨겨진 내용을 포함하여 다 보여줌
- ls -ali (directory 위치)/ : 특정 directory의 하부에 존재하는 파일 및 디렉토리를, 숨겨진 내용 + i-node 번호 를 포함하여 다 보여줌
  - i-node 번호 : 파일 시스템에서 각 파일 및 디렉토리에 번호가 부여되는데, 그 번호가 inode 번호이다.
  - ls -ai (directory 위치)
  - ls -i (directory 위치)
- ls -l \`tty` : teletype에 대한 정보를 보여준다. (해당 터미널에 대한 정보)

### touch : 현재 디렉토리에서 빈 파일을 생성함

- touch (file 명) (file명) (file명) : 크기가 0B인 file 생성 (동시에 여러개 생성 가능)
  - 이렇게 생성된 빈 파일을 vi editor를 이용해서 editting할 수 있다.

### mkdir : 현재 디렉토리에서 빈 디렉토리를 생성함

- mkdir (directory 명) : 디렉토리를 생성

### rm / rmdir : 파일을 지우는 명령 / 디렉토리를 지우는 명령

- rm 명령으로 제거된 대상은 다시 복구시킬 수 없다.
- rm (file명 / link명) / rmdir (directory명) : file, link 제거 / 디렉토리 제거  
  - 디렉터리 내부에 파일이 있다면 디렉터리를 지울 수 없다.
- rm -r (directory 명) : (directory)의 하위의 항목들을 모두 지운뒤, 해당 디렉토리를 지운다.
- rm -r * : 해당 디렉토리에 존재하는 모든 하위 디렉토리와 파일들을 제거
- rm -i : 해당 디렉토리에 있는 각 파일들에 대해서 지울 지 말 지를 사용자에게 한번 더 질의한다
- rm * : 해당 디렉토리에 있는 파일들을 전부 제거.
- rm -rf (디렉토리) : 해당 디렉토리에 내용이 있더라도 제거.

### cat : 파일들을 stdout 에 붙인다. / 파일이 주어지지 않았다면, 표준 입력을 읽어서 표준 출력으로 내보낸다

- cat (파일 명) (파일 명) : 하나, 혹은 여러 파일들의 내부 내용들을 stdout을 내보내준다.
- cat (파일 명) (파일 명) > (파일 명) : **여러 파일들의 내용을 다른 파일에 concatenation** 시켜준다.
  - 즉, 여러 파일들을 concatenation할 때 사용할 수 있다.
- cat (stdin) : stdin 으로 받아들인 내용을 stdout으로 그대로 내보내줌.
  - ctrl + d / ctrl + z : stdin의 끝을 알린다. / process를 종료한다.
- cat (stdin) > (파일 명) : stdin으로 받아들인 내용을 특정 파일로 내보낼 수 있다.
  - stdin 으로 써넣은 내용들을 특정 파일 위에 덮어씌울 수 있다.

### cd : 디렉토리 이동

- cd (directory 명) : 디렉토리 이동
- cd ..  : 상위 디렉토리 이동
- cd . : 현재 디렉토리 이동 (변화X)
- cd / : 루트 디렉토리 이동

### pwd : 현재 디렉토리 위치 확인

- pwd : 현재 디렉토리 위치 확인

### man : 어떤 명령어와, 명령어에 대한 옵션의 설명을 보여준다

- man (명령어) : '특정 명령어'와, 그 명령어의 옵션에 대한 설명을 보여준다.
  - man rm : rm 명령어와, rm 명령어 옵션에 대한 설명을 보여준다.

### more / less : 어떤 파일 내에 내용이 매우 많을 때 페이지를 넘겨가면서 볼 수 있게 해준다

- more / less (파일) :  (파일) 내의 내용을 페이지를 넘겨가면서 볼 수 있게 해준다.
  - space 로 페이지 단위로 넘어간다.
  - enter 로 문장 단위로 넘어간다.

### (tab 버튼) : 특정 디렉토리나 파일의 이름에 대해서 자동완성을 도와준다

- 파일 / 디렉토리의 이름이 잘 기억이 안날 때 유용하게 사용할 수 있다.
- test2라는 파일이 디렉토리 내에 존재할 때, te 치고 (tab) 버튼을 누르면 …
  - ‘te’ 로 시작하는 파일이나, 디렉토리 명이 여러개 있다면 해당 이름들을 보여준다.
  - ‘te’ 로 시작하는 파일이나, 디렉토리가 예를 들어 test 파일 하나밖에 없다면, ‘test’ 자동완성

### cp : 특정 파일 / 디렉토리를 다른 디렉토리 / 다른 이름의 디렉토리로 복사시킬 때 사용할 수 있다

- cp (file 명) (file 명) (도착_directory) : **특정파일(들)**을 다른 디렉토리로 복사시킬 때 사용할 수 있다.
- cp -r (디렉토리 명)/ (다른 이름으로 저장할 디렉토리 명) : 디렉토리의 하부 내용까지 전부 복사하여 새로운 이름으로 저장할 수 있게 해준다.

### mv : 특정 파일을 다른 디렉토리로 이동시키거나 / 특정 파일, 디렉토리의 이름을 변경시킬 때 사용

- mv (file 명) (도착_directory) : 현재 디렉토리에 위치한 특정파일을 다른 디렉토리로 이동시킬 때 사용할 수 있다.
- mv (file 명) (변경할 file명) : 현재 디렉토리에 위치한 특정파일의 이름을 변경시킬 때 사용할 수 있다.
- mv (directory 명)/ (변경할 directory 명) : 현재 디렉토리에 위치한 하부 디렉토리의 이름을 변경시킬 때 사용할 수 있다.
- mv (출발 directory 명)/* (도착 directory 명)/ : 출발 디렉토리 아래에 있는 모든 항목들을 도착 디렉토리 아래로 옮긴다.
- mv (출발 directory 명)/(특정 file 명) (도착 디렉터리 명)/ : 출발 디렉토리 아래에 있는 특정 파일을 도착 디렉토리 아래로 옮긴다.

### cc : 특정 파일을 compile 시키는 명령어이다. (.out 파일이 생성된다)

- cc (file 명) : 특정 파일을 컴파일 시키고, .out 파일(.exe)을 생성시킨다.
- !cc : 가장 최근의 compile을 실행시켜라

### (./ )의 의미: 해당 directory(.) 아래에 있는(/) 무언가를 가리킨다

- (예) ./a.out : 그냥 a.out는 실행되지 않는다, ./를 명시해주어야만 한다.
- (예) ~/bash_profile : home directory 아래에 있는 bash_profile을 실행시킨다.
  
### tail / head : 특정 파일이 매우 길 때, 특정 파일의 뒷부분 / 앞부분만 확인할 수 있게 해준다. (기본적으로 10줄 보여줌)

- tail -(정수) (file 명) : 특정 파일의 10-n 문장만큼의 뒷부분만 확인할 수 있게 해주는 명령
- head -(정수) (file 명) : 특정 파일의 10-n 문장만큼의 앞부분만 확인할 수 있게 해주는 명령

### clear : terminal을 깨끗하게 정리해 준다

### grep : 특정 파일 내에서 특정 문자열이 있는 부분을 찾아준다.]

- grep (찾고자 하는 문자열) (특정 file) : 특정 파일 내에서 찾고자 하는 특정 문자열을 찾아서 보여준다.

### od : 특정 파일에 대해 필터를 적용하여 보여준다 (octal dump)

- od -x (file 명) : 16진수형으로 파일의 내용을 display 한다.
  - 16비트 기준으로 8비트씩 비트 스왑이 일어난 상태로 display 되기도 한다.
- od -a (file 명) : ASCII 코드 형식으로 파일의 내용을 display 한다.

### strings : 특정 파일(binary file)에서 우리가 읽을 수 있는 ASCII 코드 값만 들어내는 명령어이다

- strings (file 명) : 어떤 실행 파일이나, 오브젝트 파일에서 읽을 수 있는 ASCII 값들만 들어내어 보여준다.
- strings (file 명) | grep (문자열) : 어떤 실행 파일이나, 오브젝트 파일에서 grep으로 특정한 문자열이 있는 부분을 들어내어 보여준다.

### link / ln : 똑같은 파일을 다른 이름으로 access하고 싶을 때 사용

- ln / link (파일 명) (별칭 파일 명) : (hard link)를 만든다. 파일 명에 대한 별칭 파일명을 부여한다.
  - link : 에러 있어도 무조건 link 걸어줌. / ln : 에러가 있으면 report를 해줌.
  - **동일 i-node 번호**를 갖는 동일한 파일이 생성된다. (ls -ali 를 통해서 확인하면 file i-node 번호가 동일한 것을 확인할 수 있다.)
  - ln을 통해 생성한 link를 제거 : rm 명령어
  - **ln으로 링크한 파일 추가** 시에, 추가한 파일들 모두 같은 파일을 가리키는 다른 이름의 reference를 새로 만드는 것일 뿐이기에 **하나의 파일을 변경하면, 다른 파일도 변경된다.** (reference를 추가하는 것도 기존의 디렉토리 디스크 용량을 사용하는 것 뿐이다.)
  - **ln으로 링크한 파일 제거** 시에, reference 갯수를 줄이는 것 뿐이다. (**디스크 용량에 변화가 없다.** : du 명령어로 확인할 수있다.)
- ln -s (파일 명) (별칭 파일 명) : symbolic link(soft link)를 만든다.
  - **다른 i-node 번호**를 갖으며, 원본 파일을 가리키는 새로운 파일이 생성된다.
  - 원본파일을 삭제했다가, 동일한 이름을 갖는 원본파일을 만들면 그 파일이 열린다. (즉 **없는 파일에 대해서도 symbolic link를 만들 수 있다.**)
  - 바로가기와 같은 기능을 하며, **원본 파일의 이름을 저장한다.**

 |symbolic link(-s)|hard link|
 |:---:|:---:|
 |특정 이름을 갖는 파일을 가리키는 바로가기 생성|동일한 내용을 갖는 파일의 복사본을 생성|
 |파일 시스템 상에서 link된 파일인지 알아차릴 수 있음(가상본)|파일 시스템 상에서 link된 파일인지 알아차릴 수 없음 (ls -ali로 확인해야 함)|
 |원본과 i-node 번호가 다르다|원본과 i-node 번호가 같다|
 |원본 파일을 제거하면 내용 확인 불가능|원본 파일을 제거해도 내용 확인 가능(동일 파일에 대한 하나의 레퍼런스가 제거된 것에 불과하기 때문)|

### tar : 파일을 묶는 명령 (tape archieve file)

- **tar 파일은 압축을 제공하지 않는다.**
- tar -cvf (.tar 파일명) (파일 명) (파일 명) .. : 특정 파일들을 포함하는 .tar 확장자를 갖는 파일 묶음을 만들어, 해당 디렉토리에 생성한다. create
- tar -cvfz (.tar.gzip 파일 명) (압축 대상 파일들) : 압축 대상이 되는 파일들을 .tar 파일로 묶은 후에 gzip으로 압축해버린다.
- tar -tvf (.tar 파일명) : .tar 확장자를 갖는 파일 내에 무슨 파일이 있는지 확인할 수 있다.
- tar -xvf (.tar) : .tar 확장자를 갖는 파일을 푼다. extract
  - 동일한 디렉터리에서 .tar 파일을 풀면, 이전에 있던 파일들을 덮어쓰면서 내용이 풀린다. 즉, 같은 이름의 파일을 덮어쓰면서 풀림. (주의 요망)
  - 그렇기 떄문에 백업 용도로 .tar 파일을 사용하기도 한다.
- tar -xvfz (.tar.gz) : .tar.gz 확장자를 갖는 파일을 압축해제하고, tar 묶음 해제한다.

### gzip : 파일들을 '압축'하여 묶는 명령

- gzip (-1 ~ -9) * : 해당 파일에 있는 내용들을 각각 다 gzip 압축해버린다.
- gzip -d (압축 해제의 대상) : 압축 해제의 대상들을 압축해제한다.
- gzip (-1 ~ -9) (파일명) : -1(빠르지만 적은 압축) ~ -9(느리지만 강한 압축) 레벨을 설정하여 파일(.tar 포함)들을 대상으로 압축을 진행할 수 있다.

### chmod : 대상 파일과 디렉토리의 사용권한을 변경할 때 사용한다. (change mode)

- -rwxrwxrwx : -421421421로 문자 단위로 끊어서 봐보자. 즉, 사용자 권한rwx, 그룹 권한rwx, 방문자 권한rwx에 각각 4, 2, 1 값이 해당한다고 고려.
- **숫자 모드**
  - chmod (수)(수)(수) : 각각의 집합(사용자/그룹/방문자)에 대한 접근 권한을 숫자로 부여한다.
    - (예) chmod 700 sample.txt : sample 파일에 대해서 사용자에게만 읽기, 쓰기, 실행 권한을 부여하고 나머지 집합에 대해서는 권한을 부여하지 않음.
- **문자 모드**
  - chmod (reference) (operation) (mode), (reference) (operation) (mode) .. : 특정 reference에게 mode(권한)을 부여한다.
  - reference : u(user), g(group), o(others), a(모두)
  - operation : =(할당, 할당 안된 항목은 권한 부여하지 않음), +(권한 추가) , -(권한 제거)
  - mode : r(읽기), w(쓰기), x(실행)
  - reference 각각에게 mode를 부여하는 연산을 구분하기 위하여 , 사용
  - (예) chmod u+r,o-r cproj / chmod u=rwx,go= cproj / chmod a= cproj ...

### file : 특정 파일이 어떤 파일인지 알려준다

- file (파일 명) : 특정파일이 어떤 파일인지 알려준다.

### history : 여태까지 실행되었던 명령어들을 보여준다

- history : 지금까지 실행시켰던 모든 명령어를 보여준다.
- !! : 가장 최근 명령어를 다시 실행시킨다.
- !(문자열) : 특정 문자열로 시작하는 가장 최근에 실행된 명령을 실행시킨다.
  - (예)) history 상에서 ls -al, cat ..., cc ... 순으로 명령이 실행된 기록이 있을 때, !c를 입력하면 cat ... 명령이 다시 실행되고, !cc를 입력하면 cc ... 명령이 다시 실행된다.
- !(명령번호 n) : history 상에서 n 번째로 실행되었던 명령이 다시 실행된다.
  - (예) history 명령으로 1006번째 명령으로 ls 명령어가 실행됨을 확인한 뒤에, !1006을 입력하면, ls 명령이 다시 실행된다.

### tail : 시스템 유틸리티로 입력받은 파일의 마지막 부분을 출력하는 프로그램이다

- tail -(n) (파일명) : 특정 파일의 마지막 n 줄 만큼을 출력한다.
  - tail -10 .zsh_history : zshell에서 입력받은 명령어의 목록을 저장하는 zsh_history파일의 마지막 10줄을 보여준다.
  - tail -10 sample.txt : sample.txt 파일에서의 마지막 10줄을 보여준다.

### exit : shell 종료

- exit : shell을 종료시킨다.

### alias : 명령어의 별칭을 지정해준다

- alias (별칭 명)=(기존 명령) : 기존의 명령에 별칭을 부여한다.
  - 만약 별칭 명에 기존에 있는 명령이름을 쓸 경우, 기존의 명령을 입력할 때 가려질 수 있다.
  - (예) alias h=history

### unalias : 별칭을 제거해 준다

- unalias (별칭 명) : 특정 별칭을 제거한다.

### Redirection (>, >&, >>, <)

- 0 : stdin, 1 : stdout, 2 : stderr. (각 standard stream에 할당된 File Descriptor라는 양의 정수 번호 사용)
- **> >> < 기호 좌측 FD 값 공백 없이** 붙혀야 한다.
- **> >> 기호 우측 FD 값 &** 붙여야 한다.
- stderr 까지 stdout과 함께 보내고 싶다면, 2>&1 을 사용해야 한다.
- **> >> < & 사용**
  - **> (파일 명)**: **명령의 결과물을 파일로 내보낸다.**
  - **>> (파일 명)**: **명령의 결과물을 파일 뒤에 붙힌다.**
    - (예) ls -l > lsout : lsout이라는 파일에 ls -l 의 결과물을 내보낸다.
      - lsout 파일 내에 lsout에 대한 내용이 있는데, 이는 lsout이라는 파일을 만들고 ls -l 의 결과를 보내기 때문.
    - (예) date >> lsout : 원래 있던 lsout이라는 파일에 date의 결과를 덧붙인다.
    - (예) python >> py_result.txt : python interpreter의 문장단위 수행의 결과들이 py_result.txt 파일에 저장된다.
  - **>& (파일 명)** : **특정 명령의 결과물과, stderr의 결과까지**를 특정 파일로 내보낸다.
    - (예) python >& py_result.txt : stderr의 결과들을 py_result.txt에 함께 내보낸다.
  - **< (파일 명)**: (파일 명) 파일에 있는 내용을 stdin으로 받아들인다.
    - (예) cat < lsout : lsout 이라는 파일에 있는 내용을 stdin으로 내보내고, 그것을 cat 명령을 통해 stdout으로 출력한다.
    - (예) cat < lsout > lsout2 : lsout 파일 내용 stdin으로 보냄, cat으로 stdin이 stdout으로 보내짐, stdout 내용이 lsout2로 넣어짐.
  - **<<< (stdin)**: 특정 파일에 stdin으로 어떤 값을 넣어준다.
    - cat <<< END >> file.txt : stdin을 file.txt에 넣는다.

### diff: 두 파일의 내용을 비교해서 보여준다

- diff (file 1) (file2) : file1 과, file2의 내용을 비교해서 보여준다.
  - (예) diff lsout lsout2 : lsout이라는 파일과 lsout2라는 파일의 차이점을 보여준다.

### Pipe(|) : 파이프 기준 앞 명령의 결과를, 그 다음 명령에 대한 stdin으로 사용한다

- (어떤 명령의 수행 ...) | (명령어) : 파이프 앞부분에서 수행한 명령의 결과를, 뒷 명령의 stdin으로 활용한다.
  - (예) ls -al | wc : ls -al 을 통해 나온 결과 stdin으로 wc 를 수행한다.
  - (예) python | tee teefile : python으로 수행한 명령에 대한 분기를 따서, teefile에 저장한다.

### Redirection 과 Pipe

- **Redirection** : 앞 명령의 결과나, 출력 > 다른 파일이나 스트림
- **Pipe** : 앞 명령 혹은 프로세스, 프로그램의 결과 > 다른 명령, 프로그램

### wc : 특정 파일의 글자수를 보여준다

- wc (파일 명) : 특정 파일에 존재하는 문장 수, 단어의 수, 바이트 수르 보여준다.
  - (예) wc sample.txt : sample.txt에 대해서 wc 명령을 수행한다.
- | wc -c : 바이트 수를 세준다.
- | wc -m : 문자들의 수를 세준다.
- | wc -l : 문장의 수를 세준다.

### tee : 수행되는 명령 결과의 분기를 만든다

- (어떤 명령의 수행) | tee (파일 명) : 어떤 명령의 수행결과에 대한 분기를 따서 특정 파일/stdout에 저장한다.
  - (예) python | tee teefile : python으로 수행한 명령에 대한 분기를 따서, teefile에 저장한다.

### sort : stdin으로 입력된 것이나, 특정 파일내의 내용을 sort한 결과를 보여준다

### pushd : 현재 작업 디렉토리를 변경하면서, 변경하기 전의 작업 디렉토리를 계속 기억하고 싶다면 pushd, popd 명령어 사용

- pushd (디렉토리) : 디렉토리로 이동하면서, 이전 디렉토리를 stack안으로.
- popd : 현재 디렉토리에서 나가면서, stack에 저장되어 있던 이전 디렉토리로 이동.

### which : 특정 명령어가 어떤 디렉토리에 들어있는 명령어인지 알려준다

- which로 찾았을 때 나오지 않으면 shell에 기본으로 들어있는 명령어이다. (which 명령어)
  - (예) which df : df 명령어가 어떤 디렉토리에 들어있는지
  - (예) which java
  - (예) which python
- shell에 기본적으로 들어있는 명령어들의 위치에 대해서 찾으려면 which bash를 통해서 찾는다. (which bash)
  - (예) which bash
- which -a find : 검색가능한 모든 경로에서 해당 명령어를 찾는다.

### df : (disk free) 리눅스 시스템 전체의 디스트 사용량을 나타낸다

- 파일 시스템의 디스크 공간에 대한 필수 정보를 표시
- df -h : 마운트 된 디스크의 크기, 사용량, 남아있는 용량에 대한 정보
  - **마운트**란, 디스크와 같은 물리적인 장치를 디렉터리에 연결해주는 것을 말한다.
  - 서버 환경의 경우는 PnP 기능(디바이스를 연결하기만 하면 알아서 세팅이 완료되는 기능)이 지원되지 않기 때문에 관리자가 디바이스를 특정 디렉토리에 직접 붙여주는 작업이 필요하다.(mount)

### du : (disk usage) 특정 디렉토리에서 디스크를 얼마나 사용했는지 KB 단위로 보여준다

- du -h (directory 위치): 특정 디렉토리에 어떤 하부 파일들이, 디스크 용량을 얼마나 사용하고 있는지 K, M, G 단위로 출력한다.

## Linux 명령어 (Process Management)

- Linux에서 작업이 실행되는 경우, 작업은 3가지로 나뉜다.
  - background에서 진행되는 작업
    - '&' : 명령어를 background로 동작시킬 때 사용한다.
  - foreground에서 진행되는 작업
    - 명령어를 쳤을 때 어떤 일이 일어나는 것
  - pause된 상태의 process
- ctrl + c : kill
- ctrl + z : suspend
- ctrl + d : End Of Text

### echo : 어떤 문자열을 입력하면 그대로 출력한다

- echo .... : .... 그대로 다시 출력한다 (stdout으로 나간다)
- echo $? : 최근 실행한 명령어의 종료 스테이터스를 보여준다.
  - 에러나, c파일의 return 값 등을 보여준다.

### sleep (n 초) : n초 동안 프롬프트가 잠에 든다

- sleep n : n초 동안 프롬프트가 잠에 든다.
  - (예) sleep 5 ; echo "5 seconds" ; ls -l :: 5초 대기 , "5 seconds" 출력, ls -l 명령어 수행
  - (sleep 20 ; echo '20sec') & :: 20초 대기, '20sec'출력을 background에서 진행
- 여러 개의 작업들을 어떻게 관리할 건지에 대해서 만들 때, 여러 작업을 관리하기 위해 sleep 사용
- control + c : control + c 버튼을 통해서 sleep 중인 상태를 끝낼 수 있다. (foreground에서 동작하는 작업을 제거시킨다.)
- control + z : control + z 버튼을 통해서 foreground에서 동작하는 작업을 정지시킨다.

### jobs : foreground와 background에서 실행되고 있는 명령들을 보여준다. (process들에서의 구체적인 명령을 알아낼 수 있다.)

### ps : process를 보는 명령

- ps -1/-al : process에 대한 내용을 좀 더 자세히 볼 수 있다.
  - PPID : parent process ID, 각 process의 바로 상위 process가 누구인가?
  - PID : process ID

### fg : 특정 작업을 foreground에서 동작하는 것으로 돌린다

- fg %(n) : jobs로 확인할 수 있는 프로세스중 n번째 작업을 foreground로 돌린다.

### bg : 특정 작엄을 background에서 동작하는 것으로 돌린다

- bg %(n) : jobs로 확인할 수 있는 프로세스중 n번째 작업을 background 돌린다.

### kill : 특정 process를 중지시킨다

- kill (PID 수) : 특정 PID 수를 갖는 process를 제거시킨다.
- kill -9 (PID 수) : 특정 PID 수를 갖는 process를 강제 종료시킨다.

### sudo su : root로 현재 사용자를 변경한다.

### sudo - (user명) : (user명)으로 현재 사용자를 변경한다.