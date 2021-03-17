/*
 * lcd.cpp
 *
 *  Created on: Mar 1, 2021
 *      Author: Tyler
 */

#include <lcd.hpp>

static PinName s_lcd_cs (LCD_CS_PORT,  LCD_CS_PIN);
static PinName s_lcd_dc (LCD_DC_PORT,  LCD_DC_PIN);
static PinName s_lcd_rst(LCD_RST_PORT, LCD_RST_PIN);

static SPI_HandleTypeDef s_lcd_spi = {.Instance = LED_SPI};

static PinName s_lcd_mosi(LCD_SDI_PORT, LCD_SDI_PIN, &s_lcd_spi);
static PinName s_lcd_miso(LCD_SDO_PORT, LCD_SDO_PIN, &s_lcd_spi);
static PinName s_lcd_sclk(LCD_SCK_PORT, LCD_SCK_PIN, &s_lcd_spi);


int num_pages = 0;
Page* pages[] = {};
Page* active_page = nullptr;
Display* lcd = nullptr;

Page* get_page(char* name) {
	for (int i = 0; i < num_pages; i++)
		if (!strcmp(name, pages[i]->name))
			return pages[i];
	return nullptr;
}

void add_page(Page* p) {
	pages[num_pages++] = p;
}

void lcd_start(void) {
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_SPI1_CLK_ENABLE();

	pin_init_out(s_lcd_cs);
	pin_init_out(s_lcd_dc);
	pin_init_out(s_lcd_rst);

	pin_init_af(s_lcd_mosi, LCD_SPI_AF);
	pin_init_af(s_lcd_miso, LCD_SPI_AF);
	pin_init_af(s_lcd_sclk, LCD_SPI_AF);

	// SPI baudrate is set to 40 MHz (PCLK1/SPI_BaudRatePrescaler = 80/2 = 40 MHz)
	spi_handle_init(&s_lcd_spi, 8, 0, SPI_BAUDRATEPRESCALER_2);

	lcd = new Display(s_lcd_mosi, s_lcd_miso, s_lcd_sclk, s_lcd_cs, s_lcd_rst, s_lcd_dc);

//	bouncing_ball(lcd);
//	bmp_test(lcd);


	lcd->background(BG);  	  // set background to BG color
	lcd->foreground(White);    // set chars to white
	lcd->cls();                // clear the screen
	lcd->set_orientation(0);


	add_demo_data();

//	// PAGE TITLE
//	lcd.fillrect(0, 0, lcd.width(), 40, ACCENT);
//	lcd.background(ACCENT);
//	lcd.print_text("Time Clock", 40, 10, (unsigned char*) Arial24x23);
//
//	// TABLE HEADERS
//	lcd.fillrect(0, 40, lcd.width(), 80, BG);
//	lcd.background(BG);
//	lcd.print_text("[name]", 10, 50, (unsigned char*) Arial12x12);
//	lcd.print_text("[id]", 100, 50, (unsigned char*) Arial12x12);
//	lcd.print_text("[wage]", 170, 50, (unsigned char*) Arial12x12);
//	lcd.line(0, 70, lcd.width(), 70, White);
//
//	// TABLE ROWS
//	Employee* e;
//	char id[10], wage[10];
//
//	for (int i = 0; i < num_employees; i++) {
//		e = employees[i];
//
//		lcd.fillrect(0, 80 + 30 * i, lcd.width(), 80 + 30 * (i + 1), BG);
//		lcd.foreground(LightGrey);
//
//		sprintf(id, "#%d", e->id);
//		sprintf(wage, "%.2f/hr", e->wage);
//		lcd.print_text(e->name, 10, 80 + 30 * i, (unsigned char*) Arial12x12);
//		lcd.print_text(id, 100, 80 + 30 * i, (unsigned char*) Arial12x12);
//		lcd.print_text(wage, 170, 80 + 30 * i, (unsigned char*) Arial12x12);
//		lcd.line(0, 70 + 30 * (i + 1), lcd.width(), 70 + 30 * (i + 1), Black);
//	}




//	lcd.set_font((unsigned char*) Arial24x23);
//	lcd.character(0, 0, 'a');

}




// ==TEST FUNCTIONS==

//void bouncing_ball(SPI_TFT_ILI9341& lcd)
//{
//	uint16_t color = Red, cdelta = 7103;
//	int const R = 31, W = 240, H = 320;
//	int x = R, y = R, dx = 1, dy = 1;
//	for (;;) {
//		lcd.fillcircle(x, y, R, color);
//		x += dx;
//		y += dy;
//		if (x <= R || W - R <= x) {
//			dx = -dx;
//			color += cdelta;
//		}
//		if (y <= R || H - R <= y) {
//			dy = -dy;
//			color += cdelta;
//		}
//	}
//}
//
//#define N 100
//static uint16_t s_bmp[N*N*2];
//
//void bmp_test(SPI_TFT_ILI9341& lcd)
//{
//	int i;
//	for (i = 0; i < N; ++i) {
//		s_bmp[i*N + i] = Red;
//	}
//	for (;;) {
//		for (i = 0; i <= N; ++i) {
//			lcd.Bitmap(20, 50, N, N, (unsigned char*)(s_bmp + i*N));
//		}
//	}
//}
