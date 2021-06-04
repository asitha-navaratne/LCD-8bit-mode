#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

#define LCD_DDR		DDRB						///< DDR of LCD display pins.
#define CTRL_DDR	DDRD						///< DDR of LCD control pins.
#define LCD_PORT	PORTB						///< Port of LCD display pins.
#define CTRL_PORT	PORTD						///< Port of LCD control pins.
#define RS 		PD0						///< Pin for LCD Register Select terminal.
#define EN  		PD1						///< Pin for LCD Enable terminal.

void LCD_DISPLAY_INIT(void);
void LCD_SEND_COMMAND(unsigned char command);
void LCD_SEND_CHARACTER(unsigned char character);
void LCD_SEND_STRING(char *string);

int main(void){
	LCD_DISPLAY_INIT();
    
	LCD_SEND_STRING("Asitha");
	LCD_SEND_COMMAND(0xC0);						///< Move cursor to the beginning of second line.
	LCD_SEND_STRING("Navaratne");
	
	LCD_SEND_COMMAND(0x0C);						///< Turn cursor off.
}

/*!
 *	@brief Initialize LCD in 8-bit mode.
 */

void LCD_DISPLAY_INIT(void){
	LCD_DDR = 0xFF;
    	CTRL_DDR = 0xFF;
	
	LCD_SEND_COMMAND(0x01);						///< Clear LCD screen.
    	LCD_SEND_COMMAND(0x38);						///< 2 line, 5x7 matrix of characters in 8-bit mode.
	LCD_SEND_COMMAND(0x80);						///< Send cursor to beginning of first line.
    	LCD_SEND_COMMAND(0x0E);						///< Turn display and cursor on.
    	_delay_ms(2);
}

/*!
 *	@brief Send a command to the LCD display.
 *	@param Command to be sent (unsigned char).
 */

void LCD_SEND_COMMAND(unsigned char command){
    	LCD_PORT = command;
    
	CTRL_PORT &= ~(1<<RS);						///< Set RS pin low to enter command mode.
    	CTRL_PORT |= (1<<EN);
    	_delay_ms(50);
    	CTRL_PORT &= ~(1<<EN);						///< Create a momentary pulse at EN pin to send the data to the LCD.
	
	_delay_ms(2);
}

/*!
 *	@brief Send a single character to the LCD display.
 *	@param Character to be sent (unsigned char).
 */

void LCD_SEND_CHARACTER(unsigned char character){
    	LCD_PORT = character;
    
	CTRL_PORT |= (1<<RS);						///< Set RS pin high to enter character mode.
    	CTRL_PORT |= (1<<EN);
    	_delay_ms(50);
    	CTRL_PORT &= ~(1<<EN);						///< Create a momentary pulse at EN pin to send the data to the LCD.

	_delay_ms(2);
}

/*!
 *	@brief Send a string of characters to the LCD display.
 *	@param String to be sent (char).
 */

void LCD_SEND_STRING(char *string){
	for(uint8_t i=0;string[i]!=0;i++){	
		LCD_SEND_CHARACTER(string[i]);
		_delay_ms(2);
	}
}
