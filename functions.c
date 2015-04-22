/**
* @file		functions.c
* @author	Manuel Caballero
* @date 	30/3/2015
* @brief 	Funciones del sistema.
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
#include "functions.h"

/**
 *  \brief     void conf_CLK (void)
 *  \details   Configura los relojes disponibles
 *                  - Reloj Principal F_OSC: INTERNO 8 x 4 ( PLL enabled ) = 32 MHz.
 *                  - Reloj LPRC 32 kHz activado.
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      30/3/2015
 */
void conf_CLK (void)
{
    OSCCONbits.COSC      =   0b001;
    OSCCONbits.SOSCEN    =   1;

    CLKDIVbits.RCDIV     =   0b000;
}



/**
 *  \brief     void conf_IO (void)
 *  \details   Configura los pines del MCU a usar en este proyecto.
 *                  - Puerto B: LEDs y UART.
 *  			- RB8:	Salida.	  SCL1     ( BH1750 SCLK )
 *  			- RB9:	I/O.	  SDA1     ( BH1750 SDA )
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      30/3/2015
 */
void conf_IO (void)
{
    ODCBbits.ODB8    =   0;     //I2C ASDA and ASCL are open-drain.
    ODCBbits.ODB9    =   0;
}



/**
 *  \brief     void conf_UART (void)
 *  \details   Configura el módulo UART a 9600 Baud Rate.
 *
 * 		· Reloj UART: PLL ON: F_CY = ( F_OSC )/2 = ( 32 MHz )/2 = 16 MHz
 *              · Alta Velocidad: BRGH = 1.
 * 		· Buad Rate ~ 9600:
 *
 *     		Baud Rate = F_CY/(4(X + 1))
 *
 *                  9600 = ( 16·10^6 )/(4(X + 1))
 *
 * 		Por lo tanto:
 *
 *                  X ~ 415.67 = 416
 *
 *  \pre       Para ampliar información: DataSheet PIC24FKA301, apartado 18.0
 *             UNIVERSAL ASYNCHRONOUS RECEIVER TRANSMITTER (UART)
 *  \pre       El reloj interno debe estar a 32 MHz.
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      7/4/2015
 */
void conf_UART (void)
{
    U1MODEbits.STSEL     =   0;     // 1-Stop bit
    U1MODEbits.PDSEL     =   0;     // No Parity, 8-Data bits
    U1MODEbits.ABAUD     =   0;     // Auto-Baud disabled
    U1MODEbits.BRGH      =   1;     // High-Speed mode

    U1BRG                =   416;

    U1MODEbits.UARTEN    =   1;     // Enable UART
    U1STAbits.UTXEN      =   1;     // Enable UART TX
}



/**
 *  \brief     void conf_I2C1 (void)
 *  \details   Configura el módulo I2C 1 a 400 kHz.
 *
 *
 *                  F_SCL = F_CY/[ I2CxBRG + 1 + F_CY/10000000 ]
 *
 *             Siendo:
 *
 *                  · F_CY = F_OSC/2
 *
 *                  400 kHz = ( 32/2 MHz )/[ I2CxBRG + 1 + ( 32/2 MHz )/10000000 ]
 *
 * 		Por lo tanto:
 *
 *                  I2CxBRG ~ 37.4 = 37 ( 0x25 )
 *
 *  \pre       Para ampliar información: DataSheet PIC24F32KA301, apartado
 *             17.0 INTER-INTEGRATED CIRCUIT (I2C).
 *
 *
 *  \pre       El reloj interno debe estar a F_OSC = 32 MHz.
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      30/3/2015
 */
void conf_I2C1 (void)
{
    I2C1BRG              =   37;        // 400 kHz @ F_OSC 32 MHz
    I2C1CONbits.I2CEN    =   1;
}


/**
 *  \brief     void conf_TA1 (void)
 *  \details   Configura el Timer1 como 16-bit timer.
 *
 *             El Timer1 despertará al microcontrolador del estado bajo consumo
 *             cada, aproximadamente 1 segundo causando interrupción.
 *
 * 
 *  \pre       El reloj interno debe ser 32 kHz.
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      28/2/2015
 */
void conf_TA1 (void)
{
    T1CONbits.TON       =   0;      // TA1 stopped
    T1CONbits.TCS       =   1;
    T1CONbits.T1ECS     =   0b10;   // f_TA1 = LPRC

    TMR1                =   0;
    PR1                 =   32000;

    IEC0bits.T1IE       =   1;      // TA1 interrupt enabled
    T1CONbits.TON       =   1;      // TA1 enabled
}