/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Device Tree constants for the Texas Instruments DP83867 PHY
 *
 * Author: Dan Murphy <dmurphy@ti.com>
 *
 * Copyright:   (C) 2015 Texas Instruments, Inc.
 */

#ifndef _DT_BINDINGS_TI_DP83867_H
#define _DT_BINDINGS_TI_DP83867_H

/* PHY CTRL bits */
#define DP83867_PHYCR_FIFO_DEPTH_3_B_NIB	0x00
#define DP83867_PHYCR_FIFO_DEPTH_4_B_NIB	0x01
#define DP83867_PHYCR_FIFO_DEPTH_6_B_NIB	0x02
#define DP83867_PHYCR_FIFO_DEPTH_8_B_NIB	0x03

/* RGMIIDCTL internal delay for rx and tx */
#define	DP83867_RGMIIDCTL_250_PS	0x0
#define	DP83867_RGMIIDCTL_500_PS	0x1
#define	DP83867_RGMIIDCTL_750_PS	0x2
#define	DP83867_RGMIIDCTL_1_NS		0x3
#define	DP83867_RGMIIDCTL_1_25_NS	0x4
#define	DP83867_RGMIIDCTL_1_50_NS	0x5
#define	DP83867_RGMIIDCTL_1_75_NS	0x6
#define	DP83867_RGMIIDCTL_2_00_NS	0x7
#define	DP83867_RGMIIDCTL_2_25_NS	0x8
#define	DP83867_RGMIIDCTL_2_50_NS	0x9
#define	DP83867_RGMIIDCTL_2_75_NS	0xa
#define	DP83867_RGMIIDCTL_3_00_NS	0xb
#define	DP83867_RGMIIDCTL_3_25_NS	0xc
#define	DP83867_RGMIIDCTL_3_50_NS	0xd
#define	DP83867_RGMIIDCTL_3_75_NS	0xe
#define	DP83867_RGMIIDCTL_4_00_NS	0xf

/* IO_MUX_CFG - Clock output selection */
#define DP83867_CLK_O_SEL_CHN_A_RCLK		0x0
#define DP83867_CLK_O_SEL_CHN_B_RCLK		0x1
#define DP83867_CLK_O_SEL_CHN_C_RCLK		0x2
#define DP83867_CLK_O_SEL_CHN_D_RCLK		0x3
#define DP83867_CLK_O_SEL_CHN_A_RCLK_DIV5	0x4
#define DP83867_CLK_O_SEL_CHN_B_RCLK_DIV5	0x5
#define DP83867_CLK_O_SEL_CHN_C_RCLK_DIV5	0x6
#define DP83867_CLK_O_SEL_CHN_D_RCLK_DIV5	0x7
#define DP83867_CLK_O_SEL_CHN_A_TCLK		0x8
#define DP83867_CLK_O_SEL_CHN_B_TCLK		0x9
#define DP83867_CLK_O_SEL_CHN_C_TCLK		0xA
#define DP83867_CLK_O_SEL_CHN_D_TCLK		0xB
#define DP83867_CLK_O_SEL_REF_CLK		0xC
/* Special flag to indicate clock should be off */
#define DP83867_CLK_O_SEL_OFF			0xFFFFFFFF

/*
 * Register values and helper macros for ti,led-function and ti,led-ctrl
 *
 * Example:
 *
 * ti,led-function = <(DP83867_LED0(FUNC_LINK_ACT) |
 *                     DP83867_LED1(FUNC_LINK_1000))>;
 * ti,led-ctrl = <(DP83867_LED0(CTRL_ACTIVE_HIGH) |
 *                 DP83867_LED1(CTRL_ACTIVE_HIGH) |
 *                 DP83867_LED2(CTRL_FORCE_LOW) |
 *                 DP83867_LED3(CTRL_FORCE_LOW))>;
 *
 * It is recommended to force all unused LED pins to high or low level via
 * led-ctrl (led-function is ignored in this case). LEDs that are missing from
 * the configured value will be set to value 0x0 (FUNC_LINK and
 * CTRL_ACTIVE_LOW).
 */

/* Link established */
#define DP83867_LED_FUNC_LINK		0x0
/* Receive or transmit activity */
#define DP83867_LED_FUNC_ACT		0x1
/* Transmit activity */
#define DP83867_LED_FUNC_ACT_TX		0x2
/* Receive activity */
#define DP83867_LED_FUNC_ACT_RX		0x3
/* Collision detected */
#define DP83867_LED_FUNC_COLLISION	0x4
/* 1000BT link established */
#define DP83867_LED_FUNC_LINK_1000	0x5
/* 100BTX link established */
#define DP83867_LED_FUNC_LINK_100	0x6
/* 10BT link established */
#define DP83867_LED_FUNC_LINK_10	0x7
/* 10/100BT link established */
#define DP83867_LED_FUNC_LINK_10_100	0x8
/* 100/1000BT link established */
#define DP83867_LED_FUNC_LINK_100_1000	0x9
/* Full duplex */
#define DP83867_LED_FUNC_FULL_DUPLEX	0xa
/* Link established, blink for transmit or receive activity */
#define DP83867_LED_FUNC_LINK_ACT	0xb
/* Receive Error or Transmit Error */
#define DP83867_LED_FUNC_ERR		0xd
/* Receive Error */
#define DP83867_LED_FUNC_ERR_RX		0xe

#define DP83867_LED_CTRL_ACTIVE_HIGH	0x4
#define DP83867_LED_CTRL_ACTIVE_LOW	0x0
#define DP83867_LED_CTRL_FORCE_HIGH	0x3
#define DP83867_LED_CTRL_FORCE_LOW	0x1

#define DP83867_LED_SHIFT(v, s)		((DP83867_LED_##v) << (s))

#define DP83867_LED0(v)			DP83867_LED_SHIFT(v, 0)
#define DP83867_LED1(v)			DP83867_LED_SHIFT(v, 4)
#define DP83867_LED2(v)			DP83867_LED_SHIFT(v, 8)
#define DP83867_LED3(v)			DP83867_LED_SHIFT(v, 12)

#endif
