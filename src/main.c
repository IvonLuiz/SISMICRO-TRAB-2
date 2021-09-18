#include <xc.h>

#include "USART.h"
#include "DHT.h"

int main(void) {
    // Inicinado o USART.
    // OBS: Para todos os comandos, verificar arquivo "USART.h"
    USART_Init(MYUBRR);

    // Relembrando: DHT22 usa PIN6, PD6.
    uint8_t I_RH, D_RH, I_Temp, D_Temp, CheckSum;


    while (1) {
        Request(); /* send start pulse */
        Response(); /* receive response */
        I_RH = Receive_data(); /* store first eight bit in I_RH */
        D_RH = Receive_data(); /* store next eight bit in D_RH */
        I_Temp = Receive_data(); /* store next eight bit in I_Temp */
        D_Temp = Receive_data(); /* store next eight bit in D_Temp */
        CheckSum = Receive_data(); /* store next eight bit in CheckSum */


        USART_Transmit(I_RH);
    }

    return 0;
}