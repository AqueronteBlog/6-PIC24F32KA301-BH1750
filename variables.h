/**
* @file		variables.h
* @author	Manuel Caballero
* @date 	30/3/2015
* @brief 	Variables del sistema.
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



// PIC24F32KA301 Configuration Bit Settings

// 'C' source line config statements

// FBS
#pragma config BWRP = OFF               /**< Boot Segment Write Protect (Disabled)                              */
#pragma config BSS = OFF                /**< Boot segment Protect (No boot program flash segment)               */

// FGS
#pragma config GWRP = OFF               /**< General Segment Write Protect (General segment may be written)     */
#pragma config GSS0 = OFF               /**< General Segment Code Protect (No Protection)                       */

// FOSCSEL
#pragma config FNOSC = FRCPLL           /**< Oscillator Select (Fast RC Oscillator with Postscaler and PLL Module (FRCDIV+PLL))     */
#pragma config SOSCSRC = ANA            /**< SOSC Source Type (Analog Mode for use with crystal)                                    */
#pragma config LPRCSEL = HP             /**< LPRC Oscillator Power and Accuracy (High Power, High Accuracy Mode)                    */
#pragma config IESO = OFF               /**< Internal External Switch Over bit (Internal External Switchover mode disabled (Two-speed Start-up disabled))   */

// FOSC
#pragma config POSCMOD = NONE           /**< Primary Oscillator Configuration bits (Primary oscillator disabled)            */
#pragma config OSCIOFNC = ON            /**< CLKO Enable Configuration bit (CLKO output signal is active on the OSCO pin)   */
#pragma config POSCFREQ = HS            /**< Primary Oscillator Frequency Range Configuration bits (Primary oscillator/external clock input frequency greater than 8MHz)    */
#pragma config SOSCSEL = SOSCHP         /**< SOSC Power Selection Configuration bits (Secondary Oscillator configured for high-power operation)     */
#pragma config FCKSM = CSDCMD           /**< Clock Switching and Monitor Selection (Both Clock Switching and Fail-safe Clock Monitor are disabled)  */

// FWDT
#pragma config WDTPS = PS32768          /**< Watchdog Timer Postscale Select bits (1:32768)                                     */
#pragma config FWPSA = PR128            /**< WDT Prescaler bit (WDT prescaler ratio of 1:128)                                   */
#pragma config FWDTEN = OFF             /**< Watchdog Timer Enable bits (WDT disabled in hardware; SWDTEN bit disabled)         */
#pragma config WINDIS = OFF             /**< Windowed Watchdog Timer Disable bit (Standard WDT selected(windowed WDT disabled)) */

// FPOR
#pragma config BOREN = BOR3             /**< Brown-out Reset Enable bits (Brown-out Reset enabled in hardware, SBOREN bit disabled) */
#pragma config LVRCFG = OFF             /**<  (Low Voltage regulator is not available)                                      */
#pragma config PWRTEN = OFF             /**< Power-up Timer Enable bit (PWRT disabled)                                      */
#pragma config I2C1SEL = PRI            /**< Alternate I2C1 Pin Mapping bit (Use Default SCL1/SDA1 Pins For I2C1)           */
#pragma config BORV = V18               /**< Brown-out Reset Voltage bits (Brown-out Reset set to lowest voltage (1.8V))    */
#pragma config MCLRE = ON               /**< MCLR Pin Enable bit (RA5 input pin disabled,MCLR pin enabled)  */

// FICD
#pragma config ICS = PGx2               /**< ICD Pin Placement Select bits (EMUC/EMUD share PGC2/PGD2)  */

// FDS
#pragma config DSWDTPS = DSWDTPSF       /**< Deep Sleep Watchdog Timer Postscale Select bits (1:2,147,483,648 (25.7 Days))  */
#pragma config DSWDTOSC = LPRC          /**< DSWDT Reference Clock Select bit (DSWDT uses Low Power RC Oscillator (LPRC))   */
#pragma config DSBOREN = ON             /**< Deep Sleep Zero-Power BOR Enable bit (Deep Sleep BOR enabled in Deep Sleep)    */
#pragma config DSWDTEN = OFF            /**< Deep Sleep Watchdog Timer Enable bit (DSWDT disabled)  */




/**
 *  \brief     Variables Globales
 *  \details
 * 		- Buffer:     Variable encargada de almacenar el dato recibido
 *                            por la UART.
 */
uint8_t Buffer = 0;


/**
 *  \brief     Variables Globales
 *  \details
 * 		- opCont:     Variable contador encargada de discernir que
 *                            acción realizar:
 *
 *                              · opCont = 0:   Petición de Conversión de LUX.
 *                              · opCont = 1:   Lectura de dato LUX.
 */
uint16_t opCont = 0;