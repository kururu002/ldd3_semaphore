#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("pohuang");
MODULE_DESCRIPTION("A Simple Hello World module");

static char *whom = "world";
static int howmany = 1;
module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);

static int __init hello_init(void)
{
        int i = 0;
        printk(KERN_ALERT "hello\n\n");
        *(int *)0 = 0;
        return 0;
}

static void __exit hello_cleanup(void)
{
        printk(KERN_ALERT "Goodbye, cruel world\n\n");
}

module_init(hello_init);
module_exit(hello_cleanup);
