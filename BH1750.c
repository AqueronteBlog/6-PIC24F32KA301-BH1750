/**
* @file		BH1750.c
* @author	Manuel Caballero
* @date 	31/3/2015
* @brief 	Funciones del dispositivo BH1750.
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
#include "BH1750.h"
#include "I2C.h"


/**
 *  \brief     uint16_t BH1750_read ( uint8_t )
 *  \details   Lee dato LUX del dispositivo externo BH1750
 *
 *  @param     uint8_t addr     Dirección del dispositivo externo BH1750.
 *
 *  @return    uint16_t aux     Si todo ha ido correctamente, devuelve el valor
 *                              LUX correspondiente. 
 *
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      31/3/2015
 */
uint16_t BH1750_read ( uint8_t addr )
{
    uint16_t    aux =   0;

    aux  =   I2C_WriteRead   ( BH1750_READ, addr, 0 );

    return  aux;
}


/**
 *  \brief     uint16_t BH1750_write ( uint8_t , uint8_t )
 *  \details   Escribe datos al dispositivo externo BH1750
 *
 *  @param     uint8_t addr     Dirección del dispositivo externo BH1750.
 *  @param     uint8_t cmd      Comando a enviar al dispositivo externo BH1750.
 *
 *  @return    uint16_t aux     
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      31/3/2015
 */
uint16_t BH1750_write ( uint8_t addr, uint8_t cmd )
{
    uint16_t    aux =   0;

    aux  =   I2C_WriteRead   ( BH1750_WRITE, addr, cmd );

    return  aux;
}