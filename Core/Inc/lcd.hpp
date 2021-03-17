/*
 * lcd.hpp
 *
 *  Created on: Mar 1, 2021
 *      Author: Tyler
 */

#pragma once

#include <Display.hpp>
#include <GraphicsDisplay.hpp>

#include <pages/Page.hpp>

#include "../../Drivers/ILI9341_Display_Driver/compat/mbed.hpp"
#include "../../Drivers/ILI9341_Display_Driver/compat/mbed_io_ex.hpp"

extern "C" {
#include "../../Drivers/BSP/STM32L476G-Discovery/stm32l476g_discovery.h"
#include "Fonts/Arial12x12.h"
#include "Fonts/Arial24x23.h"
}

// EXTERNAL VARIABLES
extern Display* lcd;
extern Page* pages[10];
extern int num_pages;
extern Page* active_page;

// COLORS
#define BG 			RGB(57, 65, 101)
#define HEADER 		RGB(25, 79, 101)
#define ACCENT 		RGB(52, 105, 175)

// OTHER MACROS
#define W			lcd->width()
#define H			lcd->height()
#define ARIAL12		(unsigned char*) Arial12x12
#define ARIAL24		(unsigned char*) Arial24x23

Page* get_page(char* name);

void add_page(Page* p);

void lcd_start(void);
