# LCD-8bit-mode
<p align="justify">In this code a 16x2 LCD module is interfaced with the ATmega32A in 8-bit mode.</p>

<p align="justify">The 16x2 LCD module can be interfaced with a microcontroller in two modes; 8-bit mode where all 8 data pins of the LCD module are connected to the microcontroller, and 4-bit mode where only the last 4 data pins are connected. While 4-bit mode saves the microcontroller's pins for other operations, 8-bit mode, which we have implemented here, is generally easier to understand and use for beginners.</p>

![Circuit diagram](https://github.com/asitha-navaratne/LCD-8bit-mode/blob/master/LCD_8bit_mode.jpg?raw=true)

<p align="justify">The LCD module has a built-in microcontroller unit within itself which controls what the display does. There are two modes of operation for this microcontroller unit; command mode where any data sent to the module is read as a command, and character mode where any data sent is read as an ASCII character. The mode of operation is changed by changing the logic level at the RS pin of the module; logic LOW to enter command mode and logic HIGH to enter character mode.</p>

<p align="justify">By sending commands to the module's microcontroller unit the module can be made to perform certain functions such as moving the cursor about the screen, clearing the screen, or turning the cursor on or off. The mode of operation (4-bit or 8-bit mode) is specified to the module using commands as well. Usually, before displaying anything on the screen, certain commands have to be sent to the module to "initialize" it by clearing the screen, setting the mode of operation and moving the cursor to the beginning of the first line.</p>

<p align="justify">In character mode, the relevent ASCII character sent to the module will be displayed wherever the cursor is on the screen and the cursor will be incremented by one position.</p>

<p align="justify">The pins D0 to D7 are used to send 8-bit data (commands or characters) to the LCD module. To send any data, the relevant data is first loaded onto the pins D0 to D7. Afterwards, a pulse of certain minimum width must be provided to the E pin of the module for it to "accept" the data.</p>

<p align="justify">The RW pin is used to determine if we want to read from or write to the LCD module's microcontroller unit. Since we will be exclusively writing commands and characters to it, this pin can be directly connected to GND. The VEE pin is used to control the contrast of the display. It can be connected through a potentiometer to GND so that the user can control the contrast as they wish, or it can be connected through a fixed resistor to GND.</p>

<p align="justify">Some LCD modules have two additional pins, A and K to control the backlight of the display. These are connected to VCC and GND respectively, either directly or through a resistor to control the brightness of the backlight. Alternatively, they can be ignored completely to conserve power or if the device is meant to be used in a well lit area where the backlight won't be necessary.</p>
