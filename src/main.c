#include <xc.h>
#include <avr/interrupt.h>

#include "USART.h"
#include "DHT.h"
#include "BH1750.h"

int main(void) {
    // Iniciando o USART.
    // OBS: Para todos os comandos, verificar arquivo "USART.h"
    USART_Init(MYUBRR);
    
    // Iniciando o sensor BH1750 juntamente com TWI.
    // OBS: Para todos os comandos, verificar arquivo "BH1750.h" e "TWI.h"
    bh1750_init();
    
    // Iniciando interrupt
	sei();
    
    // Relembrando: DHT22 usa PIN6, PD6.
    uint8_t I_RH, D_RH, I_Temp, D_Temp, CheckSum;

    // Para printar no USART:
    uint8_t i = 0;
    unsigned char data[] = "Carlos e lindo";
    unsigned char temp[] = "Temperatura: ";
    unsigned char hum[] = "Umidade: ";
    unsigned char lum[] = "Luminosidade: ";
    char luxbuff[100];


    while (1) {
        // Pedir data:
        Request(); /* send start pulse */
        Response(); /* receive response */

        // Receber data:
        I_RH = Receive_data(); /* store first eight bit in I_RH */
        D_RH = Receive_data(); /* store next eight bit in D_RH */
        while (data[i] != 0) /* print temp */ {
            USART_Transmit(hum[i]);
            i++;
        }
        USART_Transmit(I_RH);
        USART_Transmit(D_RH);

        I_Temp = Receive_data(); /* store next eight bit in I_Temp */
        D_Temp = Receive_data(); /* store next eight bit in D_Temp */
        while (data[i] != 0) /* print temp */ {
            USART_Transmit(temp[i]);
            i++;
        }
        USART_Transmit(I_Temp);
        USART_Transmit(D_Temp);


        CheckSum = Receive_data(); /* store next eight bit in CheckSum */
        
		// Pegar nível de lux
		int lux = bh1750_getlux();
		itoa(lux, luxbuff, 10); /* Convert integer to string */
        
		// Transmitir lux para USART
        i = 0;
        while (lum[i] != 0) /* print lum */ {
            USART_Transmit(lum[i]);
            i++;
        }
        
        i = 0;
        while (luxbuff[i] != 0) /* print lux */ {
            USART_Transmit(luxbuff[i]);
            i++;
        }
        
    }
    return 0;
}