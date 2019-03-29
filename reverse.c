#include <stdio.h>
#include <stdlib.h>

unsigned int reverse_bit (unsigned int v)
{
	v = (( v << 16 ) & 0xFFFF0000 ) | (( v >> 16 ) & 0x0000FFFF );    	//高16位于低16位互换
	v = (( v << 8  ) & 0xFF00FF00 ) | (( v >> 8  ) & 0x00FF00FF );		
	v = (( v << 4  ) & 0xF0F0F0F0 ) | (( v >> 4  ) & 0x0F0F0F0F );			
	v = (( v << 2  ) & 0xCCCCCCCC ) | (( v >> 2  ) & 0x33333333 );	
	v = (( v << 1  ) & 0xAAAAAAAA ) | (( v >> 1  ) & 0x55555555 );

	return v;
}


/*unsigned int reverse_bit(unsigned int num)
{
	int i;
	int bit;
	unsigned int new_num = 0;
	for (i = 0; i < 32; i++)
	{
		bit = num & 1;            //取出最后一位
		new_num <<= 1;            //新数左移
		new_num =new_num | bit;   //把刚取出的一位加到新数
		num >>= 1;                //原数右移，准备取第二位
	}
	return new_num;
}
*/


//转换为二进制显示
void to_binary(unsigned long n)
{
	int r;

	r = n % 2;

	if(n >= 2)
	{
		to_binary(n/2);
	}


	putchar('0' + r);

	return;
}

int main (void)
{
	char buf[100];
	unsigned int i;
	unsigned long n;
	
	printf ("请输入数字：");
	scanf ("%d",&i);
	
	printf("输入的数字为：%d\n\r",i);
	
	printf("二进制为：\n\r");
	to_binary(i);
	printf("\n\r");
	
	n = reverse_bit(i);
	
	printf("翻转之后的二进制为：\n\r");
	//printf ("%ld\n\r",n);
	to_binary(n);
	printf("\n\r");
}











