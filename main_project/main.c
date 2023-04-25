#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ret;

    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid());

    // Fork
    if ((ret = fork()) < 0) { 
        perror("Erro na duplicação do processo");
        return EXIT_FAILURE;
    }


    // Parent
    if (ret > 0) {
        if (execl("./reciever", "./reciever", NULL) < 0) { 
            perror("Erro no lancamento do Parent");
            return EXIT_FAILURE;
        }
    }
    // Child
    else if (ret == 0) {
        sleep(1);   // VER
        if (execl("./sender", "./sender", NULL) < 0) { 
            perror("Erro no lancamento do Child");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
