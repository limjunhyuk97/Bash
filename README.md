# Linux

## Linux 구조

- Shell(Bash) > System Utility > System Call > Kernel
- **Bash는..**
  - **GNU(공개 소프트웨어 프로젝트) OS를 위한 명령어 인터프리터 이고, Shell**이다.
  - sh 파일과 호환가능하다. 즉, shell script 언어와 호환가능하다.
- **Shell은..**
  - 명령을 실행시키는 **macro processor**이다. macro processor는 텍스트와 기호를 확장하여 더 큰 표현을 만드는 기능을 의미함.
  - **GNU utility set에 사용자 인터페이스를 제공**한다. 프로그래밍 언어기능으로 utility set을 결합할 수 있다.
  - **명령이 포함된 파일을 작성하여 새로운 명령을 정의**할 수 있다.


## TIPS

#### 1. 터미널에서 cpp 컴파일이 진행되지 않을 경우 확인해볼 것

- 컴파일에 필요한 library에 대한 정보가 없는 경우인가
- g++ 버전을 c++17을 위한 버전으로 강제하면 해결될것인가

```bash
// c++17 버전으로 컴파일
g++ -std=c++17 /*filename*/

// gcc version 확인
gcc --version

// gcc version 업데이트
brew install gcc --HEAD
```

#### 2. c 파일의 컴파일

```sh
gcc -o 컴파일후파일명 파일.c
```

#### 3. 마운트

- 실제 공간인 디스크를 사용하기 위해 현재 운영체제에 연결하는 것 (장치와 파일의 연결 / 디스트와 디렉토리의 연결) 
- Linux 는 Window 와는 다르게 하나의 root 에서 뻗어나가는 single directory tree 구조의 파일 시스템 갖는다.