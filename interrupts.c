/**
* @file		interrupts.c
* @author	Manuel Caballero
* @date 	30/3/2015
* @brief 	Interrupciones del sistema.
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
#include "interrupts.h"


/**
 *  \brief     _T1Interrupt (void) interrupt service routine
 *  \details   Subrutina de interrupción del Timer 1.
 *
 *             Cada aproximadamente 1 segundo, se incrementa la variable contador
 *             para realizar la acción de determinada en el programa principal
 *             despertando al microcontrolador de su estado de bajo consumo.
 *               
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      6/4/2015
 */
void __attribute__ ((interrupt,no_auto_psv)) _T1Interrupt (void)
{
    if ( IFS0bits.T1IF  ==  1 )
    {
        opCont++;

        if ( opCont == 3 )
            opCont   =   0;


        IFS0bits.T1IF    =   0;     // Reset flag
    }
}