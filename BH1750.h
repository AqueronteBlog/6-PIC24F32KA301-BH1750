/**
* @file		BH1750.h
* @author	Manuel Caballero
* @date 	30/3/2015
* @brief 	Variables del dispositivo BH1750.
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



// BH1750 COMANDOS QUE INDICA LECTURA O ESCRITURA AL DISPOSITIVO
#define BH1750_WRITE                        0x00    /**< Comando que indica mandar datos al BH1750 */
#define BH1750_READ                         0xFF    /**< Comando que indica leer datos del BH1750 */


// BH1750 ADDRESS (  2 types, it is determined by ADDR Terminal )
#define BH1750_ADDR_H                       0x5C    /**< ADDR = 'H'   ( ADDR  >=  0.7VCC ) */
#define BH1750_ADDR_L                       0x23    /**< ADDR = 'L'   ( ADDR  <=  0.3VCC ) */


// BH1750 COMMANDS
#define BH1750_POWER_DOWN                   0x00
#define BH1750_POWER_ON                     0x01
#define BH1750_RESET                        0x07
#define BH1750_CONTINUOUS_HIGH_RES_MODE     0x10
#define BH1750_CONTINUOUS_HIGH_RES_MODE_2   0x11
#define BH1750_CONTINUOUS_LOW_RES_MODE_2    0x13
#define BH1750_ONE_TIME_HIGH_RES_MODE       0x20
#define BH1750_ONE_TIME_HIGH_RES_MODE_2     0x21
#define BH1750_ONE_TIME_LOW_RES_MODE        0x23


// PROTOTIPO DE FUNCIONES
uint16_t BH1750_read    ( uint8_t );
uint16_t BH1750_write   ( uint8_t, uint8_t );