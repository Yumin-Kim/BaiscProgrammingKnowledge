#include <linux/module.h>
#include <linux/kernel.h>
#define MODULE
int init_module(void)
{
	printk("<1>Hello , world\n");
	return 0;
}
void cleanup_module(void)
{
printk("<1>Goodbye cruel world\n");
}

