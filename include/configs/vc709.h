#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>

#define CONFIG_SYS_SDRAM_BASE 0x80000000
// do not collide with OpenSBI and U-Boot data
#define CONFIG_SYS_INIT_SP_ADDR 0x88000000
// loaded by OpenSBI at 0x80020000
#define CONFIG_SYS_LOAD_ADDR 0x80100000

#define CONFIG_SYS_MALLOC_LEN SZ_8M

#define CONFIG_SYS_BOOTM_LEN SZ_64M

#define CONFIG_STANDALONE_LOAD_ADDR 0x82200000

#define RISCV_MMODE_TIMERBASE 0x2000000
#define RISCV_MMODE_TIMER_FREQ 1000000

#define CONFIG_ENV_IS_NOWHERE 1

/* Environment */
#define ENV_DEVICE_SETTINGS \
	"stdin=serial,usbkbd\0" \
	"stdout=serial,vidconsole\0" \
	"stderr=serial,vidconsole\0"

/* SPI */
#define CONFIG_SPI_FLASH_SIZE		(32 << 30)

//#define CONFIG_EXTRA_ENV_SETTINGS                                              
//	"fdtaddr=0x82200000\0" 

#define CONFIG_TIMESTAMP

#endif /* __CONFIG_H */
