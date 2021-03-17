/*
 * Display.hpp
 *
 *  Created on: Mar 2, 2021
 *      Author: Tyler
 */

#define LCD_SDI_PORT GPIOE
#define LCD_SDO_PORT GPIOE
#define LCD_SCK_PORT GPIOE
#define LCD_RST_PORT GPIOE
#define LCD_CS_PORT  GPIOH
#define LCD_DC_PORT  GPIOH

#define LCD_SDI_PIN GPIO_PIN_15
#define LCD_SDO_PIN GPIO_PIN_14
#define LCD_SCK_PIN GPIO_PIN_13
#define LCD_RST_PIN GPIO_PIN_12
#define LCD_CS_PIN  GPIO_PIN_0
#define LCD_DC_PIN  GPIO_PIN_1

#define LED_SPI SPI1
#define LCD_SPI_AF GPIO_AF5_SPI1

#ifndef INC_DISPLAY_HPP_
#define INC_DISPLAY_HPP_

#include "../../Drivers/ILI9341_Display_Driver/third/SPI_TFT_ILI9341.hpp"

class Display : public SPI_TFT_ILI9341 {
public:

	Display(PinName mosi, PinName miso, PinName sclk, PinName cs, PinName reset, PinName dc, const char* name ="TFT");

	void print_text(char* text, int x, int y, unsigned char* font);
};

#endif /* INC_DISPLAY_HPP_ */
