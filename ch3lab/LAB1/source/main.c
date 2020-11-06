#include<stdio.h>
#include<stdlib.h>

int odd(int u);
int even(int u);
int totalsum(int u);

int main(void)
{
	int n, sum;
	char addchoice;
	printf("1+2+.....+n=?請輸入n=");
	scanf_s("%d", &n);
	printf("請問要做奇數和(O),偶數和(E),還是整數和(I)?請選擇:");
	scanf_s(" %c", &addchoice);

	switch (addchoice)
	{
	case'O':
		sum = odd(n);
		break;
	case'E':
		sum = even(n);
		break;
	case'I':
		sum = totalsum(n);
		break;
	default:
		printf("選擇錯誤\n");
		return -1;

	}
	printf("總合為%d\n", sum);
	system("pause");
	return 0;

}
int odd(int u)
{
	int i, total = 0;
	for (i = 1; i <= u; i++)
	
		if (i % 2 == 1)
		
			total = total + i;
		return total;
	
}
int even(int u)
{
	int i, total = 0;
	for (i = 1; i <= u; i++)
	
		if (i % 2 == 0)

			total = total + i;
		return total;
	
}
int totalsum(int u)
{
	
		return odd(u) + even(u);
	
}