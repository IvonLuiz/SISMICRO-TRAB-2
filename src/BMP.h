#include <xc.h>
#include <avr/io.h>
#include <avr/delay.h>
#include <stdlib.h>
#include <stdio.h>


// Cofigurações do BMP180
// Pressure in hPa
// Temperature will have 16 bits
// Pressure will have 16 to 19 bits 
#define __BMP_PRESSURE_MIN          300 
#define __BMP_PRESSURE_MAX          1100
#define __BMP_TEMPERATURE_MIN       0
#define __BMP_TEMPERATURE_MAX       60
#define __BMP_DELAY_TEMPERATURE     4.5
#define __BMP_DELAY_PRESSURE_ULP    4.5
#define __BMP_DELAY_PRESSURE_STD    7.5
#define __BMP_DELAY_PRESSURE_HR     13.5
#define __BMP_DELAY_PRESSURE_UHR    25.5

// Vamos usar o PIN5, porta PD5

void Request_BMP(); /* Microcontroller send start pulse/request */

void Response_BMP(); /* receive response from DHT22 */

/* Should be:
 *  | 
 *  | __BMP_TEMPERATURE_MAX 
 *  V
 * TEMPERATURE
 *  |
 *  | PRESSURE DELAY
 *  V
 * PRESSURE
*/
uint8_t Receive_data_BMP_PRESSURE(uint8_t TIME); /* receive data */
uint8_t Receive_data_BMP_TEMPERATURE(); /* receive data */