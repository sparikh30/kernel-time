#include<stdio.h>
#include<unistd.h>
#include<linux/unistd.h>
#include<inttypes.h>
#include<math.h>
#include<time.h>
int main()
{
	int y;
	time_t s;
	long ns;
	struct timespec ct;
	
	y = syscall(327,&ct);

	if(y==0)
	{
		printf("\nsyscall return value :%d\n",y);//negative value of y will indicate a failure
		s = ct.tv_sec;
		printf("\nTime in seconds: %ld",s);

		printf("\nTime in nano seconds: %ld \n",ct.tv_nsec);
	}
	else
	{
		printf("\nSystem Call Failed. Return value: %d",y);
	}
	return 0;
}
