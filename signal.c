#include <signal.h>
#include <unistd.h>
#include <stdio.h>
 
 
void sigroutine(int dunno)
{ /* �źŴ������̣�����dunno����õ��źŵ�ֵ */
 
        switch (dunno) {
        case 1:
        		printf("dunno = %d\n\r",dunno);
            printf("Get a signal -- SIGHUP \n\r");
            break;
        case 2:
        		printf("dunno = %d\n\r",dunno);
            printf("Get a signal -- SIGINT \n\r");
            break;
        case 3:
        		printf("dunno = %d\n\r",dunno);
            printf("Get a signal -- SIGQUIT \n\r");
            break;
        }
        return;
}
 
 
int main() {
 
        printf("process id is %d \n\r",getpid());
        signal(SIGHUP, sigroutine); //* �������������źŵĴ�����
        signal(SIGINT, sigroutine);
        signal(SIGQUIT, sigroutine);
        for (;;) ;
        return 0;
}
