#include "BMP.h"

// NOTE: Usando o PIN65, PD5

void Request_BMP() // Microcontrole send start pulse
{
    DDRD |= (1 << DDD5);
    PORTD &= ~(1 << PB5);
    _delay_ms(__BMP_DELAY_PRESSURE_STD);
    PORTD |= (1 << PB5);
}

void Response_BMP()
{
    DDRD &= ~(1 << DDD5);
    while (PIND & (1 << PIND5));
    while ((PIND & (1 << PIND5)) == 0);
    while (PIND & (1 << PIND5));
}

uint8_t response = 0;
// Variable time as it can have dif await times
uint8_t Receive_data_BMP_PRESSURE(uint8_t TIME)
{
   for (int i = 0; i<8; i++)
   {
       while ((PIND & (1 << PIND5)) == 0)
       {
           _delay_ms(TIME);
           if ( PIND & (1 << PIND5) == 0 )
           {
               response = (response << 1) | (0x01);
           } else 
           {
               response = (response << 1);
           }
       }
       return response;
   }
}