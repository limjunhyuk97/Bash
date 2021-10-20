# Bash 명령어

## Bash 명령

### exit : 현재 동작하고 있는 shell을 종료한다

### ( ) : 

### (( )) : numeric한 값에 대한 접근 시에 사용한다.

### = \` ... \` : \` ... \` 내부를 실행한 결과물이 stdout으로 나온 것을 입력한다

### source : shell script를 실행시킨다.

시험 출제!>

for i in file09?.c; do echo mv ${i%c}java; done


for i in {1..100}; do istr=`printf %03d $i`; touch file$istr.c; done


touch a.c b.c d.c

touch "a.c b.c d.c" 

같은 파일이려면 inode 번호 같아야 함
 - 확인 하는 셸 스크립트 만들 수 있어야 함


셸 스크립트..?>

셸 스크립트 실행 : source '...'.sh
: chmod를 통해서 permission 변경
: bash '...'.sh를 통해서 subshell을 통해 실행

- 파일명 바꾸기
- redirection, tee
- git 연결
- stderr 만들기