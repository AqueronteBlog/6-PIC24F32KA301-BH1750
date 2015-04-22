/**
* @file		I2C.c
* @author	Manuel Caballero
* @date 	31/3/2015
* @brief 	Funciones del bus I2C.
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
#include "I2C.h"


/**
 *  \brief     void I2C_Start ( void )
 *  \details   I2C 1 envía comando STRAT.
 *
 *
 *
 *  \warning    El código no soporta un sistema de seguridad en aquellos puntos
 *              donde el microcontrolador espera a una respuesta exterior, generalmente
 *              cuando se espera un ACK por el bus I2C, en caso de haber un error,
 *              es muy probable que el microcontrolador se quede atascado en dicho punto.
 *
 *              Para evitarlo, se recomienda usar un tiempo de seguridad o una variable
 *              contador.
 *
 *
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      31/3/2015
 */
void I2C_Start ( void )
{
    I2C1CONbits.SEN  =   1;

    while ( I2C1CONbits.SEN == 1);       // Peligro de que el programa se quede atascado!!!
}


/**
 *  \brief     void I2C_Stop ( void )
 *  \details   I2C 1 envía comando STOP.
 *
 *
 *
 *  \warning    El código no soporta un sistema de seguridad en aquellos puntos
 *              donde el microcontrolador espera a una respuesta exterior, generalmente
 *              cuando se espera un ACK por el bus I2C, en caso de haber un error,
 *              es muy probable que el microcontrolador se quede atascado en dicho punto.
 *
 *              Para evitarlo, se recomienda usar un tiempo de seguridad o una variable
 *              contador.
 *
 *
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      31/3/2015
 */
void I2C_Stop ( void )
{
    I2C1CONbits.PEN  =   1;

    while ( I2C1CONbits.PEN == 1 );     // Peligro de que el programa se quede atascado!!!
}


/**
 *  \brief     TODO uint16_t BH1750_WriteRead ( uint8_t, uint8_t, uint8_t )
 *  \details   Esta función tiene el objetivo tanto de mandar datos y recibirlos
 *             por el bus I2C al dispositivo externo BH1750.
 *
 *
 *  @param     uint8_t opWriteRead  Indica si se va a enviar o recibir datos.
 *  @param     uint8_t addr         Dirección del dispositivo externo.
 *  @param     uint8_t cmd          Comando a enviar al dispositivo externo.
 *
 *  @return    uint16_t aux         En modo LECTURA de datos, devuelve el dato
 *                                  leído del dispostivo externo.
 *
 *
 *  \warning    El código no soporta un sistema de seguridad en aquellos puntos
 *              donde el microcontrolador espera a una respuesta exterior, generalmente
 *              cuando se espera un ACK por el bus I2C, en caso de haber un error,
 *              es muy probable que el microcontrolador se quede atascado en dicho punto.
 *
 *              Para evitarlo, se recomienda usar un tiempo de seguridad o una variable
 *              contador.
 *
 *
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      31/3/2015
 */
uint16_t I2C_WriteRead ( uint8_t opWriteRead, uint8_t addr, uint8_t cmd )
{
    uint16_t    aux =   0;

    I2C_Start   ();

    if ( opWriteRead == I2C_READ )
    {
    // LEE datos procedentes del I2C
        I2C1TRN   =   ( addr << 1 ) + 0x01;
        while ( I2C1STATbits.TRSTAT == 1 );     // Peligro de que el programa se quede atascado!!!

        I2C1CONbits.RCEN     =   1;
        while ( I2C1CONbits.RCEN == 1 );

        aux                  =   I2C1RCV;

        I2C1CONbits.ACKEN    =   1;
        while ( I2C1CONbits.ACKEN == 1 );       // Peligro de que el programa se quede atascado!!!

        I2C1CONbits.RCEN     =   1;
        while ( I2C1CONbits.RCEN == 1 );        // Peligro de que el programa se quede atascado!!!
        aux                 <<=  8;
        aux                 +=   I2C1RCV;
    }
    else
    {
    // ESCRIBE datos por el I2C
        I2C1TRN   =   ( addr << 1 ) + 0x00;
        while ( I2C1STATbits.TRSTAT == 1 );     // Peligro de que el programa se quede atascado!!!

        I2C1TRN   =   cmd;
        while ( I2C1STATbits.TRSTAT == 1 );     // Peligro de que el programa se quede atascado!!!
    }

    I2C_Stop    ();

    return  aux;
}