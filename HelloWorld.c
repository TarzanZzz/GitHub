#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
 
void test_func()
{
 
  printf("HelloWorld!\n\r");
}
 
void init_sigaction()
{
  struct sigaction act;
      
  act.sa_handler = test_func; //���ô����źŵĺ���
  act.sa_flags = 0;
 
  sigemptyset(&act.sa_mask);
  sigaction(SIGPROF, &act, NULL);//ʱ�䵽����SIGROF�ź�
}
 
void init_time()
{
  struct itimerval val;
      
  val.it_value.tv_sec = 0; 
  val.it_value.tv_usec = 100000;//0.1������ö�ʱ��
 
  val.it_interval = val.it_value; //��ʱ�����Ϊ0.1s
 
  setitimer(ITIMER_PROF, &val, NULL);
}
 
int main(int argc, char **argv)
{
 
  init_sigaction();
  init_time();
 
  while(1);
 
  return 0;
}