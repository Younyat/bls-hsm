/*
 * Copyright (c) 2018 Nordic Semiconductor ASA.
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */


/*
 * Example code for a Secure Partition Manager application.
 * The application uses the SPM to set the security attributions of
 * the MCU resources (Flash, SRAM and Peripherals). It uses the core
 * TrustZone-M API to prepare the MCU to jump into Non-Secure firmware
 * execution.
 *
 * The following security configuration for Flash and SRAM is applied:
 *
 *                FLASH
 *  1 MB  |---------------------|
 *        |                     |
 *        |                     |
 *        |                     |
 *        |                     |
 *        |                     |
 *        |     Non-Secure      |
 *        |       Flash         |
 *        |                     |
 * 256 kB |---------------------|
 *        |                     |
 *        |     Secure          |
 *        |      Flash          |
 *  0 kB  |---------------------|
 *
 *
 *                SRAM
 * 256 kB |---------------------|
 *        |                     |
 *        |                     |
 *        |                     |
 *        |     Non-Secure      |
 *        |    SRAM (image)     |
 *        |                     |
 * 128 kB |.................... |
 *        |     Non-Secure      |
 *        |  SRAM (BSD Library) |
 *  64 kB |---------------------|
 *        |      Secure         |
 *        |       SRAM          |
 *  0 kB  |---------------------|
 */
#define NRF

#include <spm.h>
#include <aarch32/cortex_m/tz.h>

#include <sys/printk.h>
#include <secure_services.h>
#include <bl_crypto.h>
#include <bls_hsm.h>

void main(void)
{
	spm_config();
	spm_jump();
}
