/**
* @file		main.c
* @author	Manuel Caballero
* @date 	30/3/2015
* @brief 	Archivo principal.
* \copyright
* 	AqueronteBlog@gmail.com
*
* Este archivo es propiedad intelectual del blog Aqueronte,
* cuya direccion web, es la siguiente:
*
* 	http://unbarquero.blogspot.com/
*
* Se permite cualquier modificacion del archivo siempre y cuando
* se mantenga la autoria del autor.
*/
#include <xc.h>
#include <stdint.h>
#include "variables.h"
#include "functions.h"
#include "interrupts.h"
#include "BH1750.h"


/**
 *  \brief     void main( void )
 *  \details   Este programa consiste en leer datos de luz ambiente procedentes
 *             del disposititvo externo BH1750 ( bus I2C ) y enviar dichos datos
 *             por la UART cada aproximadamente 3 segundos.
 *
 *
 *             Este programa se ha probado con un par de módulos XBee modelo
 *             XBee XB24-ZB ( uno Coordinator y el otro End Device ).
 * 
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      5/4/2015
 *  \pre       Este firmware está probado para el PIC24F32KA301.
 *
 *  \pre       MPLAB X IDE v2.35.
 *  \pre       Compiler XC16 v1.22.
 */
void main( void ) {

    uint16_t    aux =   0;

    conf_CLK    ();     // Configura Relojes
    conf_IO     ();     // Configura Pins
    conf_UART   ();     // Configura UART
    conf_I2C1   ();     // Configura I2C 1
    conf_TA1    ();     // Configura Timer 1

    
    while ( 1 )
    {
        // BAJO CONSUMO
        Sleep ();

        if ( opCont ==  1 )
        {
        // PETICIÓN DE CONVERSIÓN LUX
            BH1750_write   ( BH1750_ADDR_H, BH1750_ONE_TIME_HIGH_RES_MODE );
        }
        else if ( opCont == 2 )
        {
        // LECTURA DE DATOS LUX DESDE EL DISPOSITIVO EXTERNO BH1750 Y ENVÍO DE DATOS POR LA UART
            aux  =   BH1750_read    ( BH1750_ADDR_H );

            // Envía datos por la UART
            U1TXREG  =   ( aux >> 8 );
            while ( U1STAbits.TRMT == 0 );

            U1TXREG  =   aux;
            while ( U1STAbits.TRMT == 0 );
        }
    }
}

