/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2017, STMicroelectronics - All Rights Reserved
 * Author(s): Patrice Chotard, <patrice.chotard@foss.st.com> for STMicroelectronics.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>

/* ram memory-related information */
#define PHYS_SDRAM_1			0x40000000
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
#define PHYS_SDRAM_1_SIZE		0x3E000000

#define CONFIG_SYS_HZ_CLOCK		1000000000	/* 1 GHz */

/* Environment */

/*
 * For booting Linux, use the first 256 MB of memory, since this is
 * the maximum mapped by the Linux kernel during initialization.
 */
#define CONFIG_SYS_BOOTMAPSZ		SZ_256M

#define CONFIG_SYS_BOOTM_LEN		SZ_16M

#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 0) \
	func(USB, usb, 0) \
	func(DHCP, dhcp, na)
#include <config_distro_bootcmd.h>
#define CONFIG_EXTRA_ENV_SETTINGS				\
			"kernel_addr_r=0x40000000\0"		\
			"fdtfile=stih410-b2260.dtb\0"		\
			"fdt_addr_r=0x47000000\0"		\
			"scriptaddr=0x50000000\0"		\
			"pxefile_addr_r=0x50100000\0"		\
			"ramdisk_addr_r=0x48000000\0"		\
			BOOTENV

/* Extra Commands */

#define CONFIG_SYS_GBL_DATA_SIZE	1024	/* Global data structures */
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_TEXT_BASE - \
					 CONFIG_SYS_MALLOC_LEN - \
					 CONFIG_SYS_GBL_DATA_SIZE)

/* Monitor Command Prompt */
#define CONFIG_SYS_CBSIZE		1024	/* Console I/O Buffer Size */

/* USB Configs */
#define CONFIG_USB_OHCI_NEW
#define CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS	2

/* NET Configs */

#endif /* __CONFIG_H */
