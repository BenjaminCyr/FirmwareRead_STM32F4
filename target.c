/*
 * Copyright (C) 2017 Obermaier Johannes
 *
 * This Source Code Form is subject to the terms of the MIT License.
 * If a copy of the MIT License was not distributed with this file,
 * you can obtain one at https://opensource.org/licenses/MIT
 */

#include "target.h"
#include "clk.h"

void targetSysCtrlInit( void )
{
	RCC->AHB1ENR |= RCC_AHBENR_GPIO_RESET;
	RCC->AHB1ENR |= RCC_AHBENR_GPIO_POWER;

	GPIO_RESET->MODER |= (0x01u << (PIN_RESET << 1u));
	GPIO_POWER->MODER |= (0x01u << (PIN_POWER << 1u));

	GPIO_RESET->OSPEEDR |= (0x03u << (PIN_RESET << 1u));
	GPIO_POWER->OSPEEDR |= (0x03u << (PIN_POWER << 1u));

	targetSysOff();
	targetSysReset();

	return ;
}

void targetSysReset( void )
{
	GPIO_RESET->BSRR = (0x01u << (PIN_RESET + GPIO_BSRR_BR0_Pos));

	return ;
}

void targetSysUnReset( void )
{
	GPIO_RESET->BSRR = (0x01u << (PIN_RESET + GPIO_BSRR_BS0_Pos));

	return ;
}


void targetSysOff( void )
{
	GPIO_POWER->BSRR = (0x01u << (PIN_POWER + GPIO_BSRR_BR0_Pos));

	return ;
}

void targetSysOn( void )
{
	GPIO_POWER->BSRR = (0x01u << (PIN_POWER + GPIO_BSRR_BS0_Pos));

	return ;
}
