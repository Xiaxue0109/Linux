/*************************************************************************
	> File Name: 9.fork.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月24日 星期二 19时01分40秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*
int main() {
    pid_t pid;
    for (int i = 1; i <= 10; i++) {
        pid = fork();
        if (pid == 0 || pid == -1) {
            break;
        }
    }
    if (pid == -1) {
        printf("create fail");
    } else if (pid == 0) {
        sleep(60);
    }
    return 0;
}
*/


int main() {
    int pid, x;
    for (int i = 1; i <= 10; i++) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            continue;
        }
        if (pid == 0) {
            x = i;
            break;//子进程就直接跳出结束
            //如果不break，就会有2的10次方
        }
    }
    printf("I'm %dth Child.\n", x);
    sleep(60);
    return 0;
}
