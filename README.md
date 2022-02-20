## LINUX_COMMAND, VIM editor, Shell script

## Tips

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
