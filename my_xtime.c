#include <linux/linkage.h>
#include <linux/export.h>
#include <linux/time.h>
#include <asm/uaccess.h>
#include <linux/printk.h>
#include <linux/slab.h>

asmlinkage int sys_my_xtime(struct timespec* current_time)
{
	int nbytes;
	
	if(access_ok(VERIFY_WRITE,current_time,sizeof(current_time)))
	{
		struct timespec x=current_kernel_time();

		nbytes=copy_to_user(current_time, &x, sizeof(x));

		if(nbytes==0)
		{
			printk(KERN_CRIT "\nTime in nano seconds %ld",current_time->tv_nsec);
		}
		else
		{
			printk(KERN_CRIT "\nCOPY TO USER FAIL");
		}
	}
	else
	{
		printk(KERN_DEBUG "\nINVALID USER SPACE ACCESS");
	}
	return 0;
}
EXPORT_SYMBOL(sys_my_xtime);
