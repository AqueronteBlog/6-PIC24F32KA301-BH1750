/**
* @file		I2C.h
* @author	Manuel Caballero
* @date 	31/3/2015
* @brief 	Variables del bus I2C.
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



// I2C COMANDOS QUE INDICA LECTURA O ESCRITURA AL DISPOSITIVO
#define I2C_WRITE                        0x00
#define I2C_READ                         0xFF



// PROTOTIPO DE FUNCIONES
uint16_t I2C_WriteRead    ( uint8_t, uint8_t, uint8_t );
void I2C_Start            ();
void I2C_Stop             ();