#include <common.h>
#include <command.h>
#include <stdio.h>
#include <linux/delay.h>
static int do_kfc(struct cmd_tbl *cmdtp, int flag, int argc,
		   char *const argv[])
{
	for(int i=0;i<10;i++){
		printf("KFC\n");
		mdelay(500);
	}
	printf("===FINISH====\n\n");
	return 0;
}

U_BOOT_CMD(
	kfc, CONFIG_SYS_MAXARGS, 0, do_kfc,
	"HI Faker!"
	"kfc args to console",
	"[-n] [args..]\n"
	"    - kfc args to console; -n suppresses newline"
);
