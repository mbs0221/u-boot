#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>

#define CONFIG_SYS_SDRAM_BASE			0x80000000
// do not collide with OpenSBI and U-Boot data
#define CONFIG_SYS_INIT_SP_ADDR         (CONFIG_SYS_SDRAM_BASE + SZ_2M)
// loaded by OpenSBI at 0x80020000
#define CONFIG_SYS_LOAD_ADDR            (CONFIG_SYS_SDRAM_BASE + SZ_2M)

#define CONFIG_SYS_MALLOC_LEN			SZ_8M

#define CONFIG_SYS_BOOTM_LEN			SZ_64M

#define CONFIG_STANDALONE_LOAD_ADDR		0x80200000

#define RISCV_MMODE_TIMERBASE			0x2000000
#define RISCV_MMODE_TIMER_FREQ 			1000000

#define CONFIG_ENV_IS_NOWHERE 1

#define RISCV_SMODE_TIMER_FREQ          1000000

/* SPI */
#define CONFIG_SPI_FLASH_SIZE		(32 << 30)

/* Environment options */

#ifndef CONFIG_SPL_BUILD

#define BOOT_TARGET_DEVICES(func) \
        func(MMC, mmc, 0) \

#include <config_distro_bootcmd.h>
#include <environment/distro/sf.h>

#define TYPE_GUID_LOADER1       "5B193300-FC78-40CD-8002-E86C45580B47"
#define TYPE_GUID_LOADER2       "2E54B353-1271-4842-806F-E436D6AF6985"
#define TYPE_GUID_SYSTEM        "0FC63DAF-8483-4772-8E79-3D69D8477DE4"

#define PARTS_DEFAULT \
        "name=loader1,start=17K,size=1M,type=${type_guid_gpt_loader1};" \
        "name=loader2,size=4MB,type=${type_guid_gpt_loader2};" \
        "name=system,size=-,bootable,type=${type_guid_gpt_system};"


#define CONFIG_EXTRA_ENV_SETTINGS \
        "fdt_high=0xffffffffffffffff\0" \
        "initrd_high=0xffffffffffffffff\0" \
        "kernel_addr_r=0x84000000\0" \
        "fdt_addr_r=0x82200000\0" \
        "kernel_comp_addr_r=0x90000000\0" \
        "kernel_comp_size=0x4000000\0" \
        "type_guid_gpt_loader1=" TYPE_GUID_LOADER1 "\0" \
        "type_guid_gpt_loader2=" TYPE_GUID_LOADER2 "\0" \
        "type_guid_gpt_system=" TYPE_GUID_SYSTEM "\0" \
        "partitions=" PARTS_DEFAULT "\0" \
        "fdtfile=" CONFIG_DEFAULT_FDT_FILE "\0" \
        BOOTENV \
        BOOTENV_SF

#define CONFIG_PREBOOT \
        "setenv fdt_addr ${fdtcontroladdr};" \
        "fdt addr ${fdtcontroladdr};"
#endif

#define CONFIG_TIMESTAMP

#endif /* __CONFIG_H */
