//
//  toy2.c
//  PA1
//
//  Created by 임준혁 on 2022/04/08.
//

#include <stdio.h>
#include <unistd.h>

void hello(void) {
    printf("Executing Hello\n");
    
    pid_t pid = fork();
    if(pid > 0) printf("Parent Process\n");
    else printf("Child Process\n");
}

int main(void){
    
    int a, b, c=1;
    
    a= b= c;
    printf("Executing Main\n");
    
    hello();
    
    return 0;
}
