# 6-PIC24F32KA301-BH1750

## DESCRIPCIÓN:

Este programa consiste en leer datos de luz ambiente procedentes del disposititvo externo **BH1750** ( bus I2C ) 
y enviar dichos datos por la UART cada aproximadamente 3 segundos donde se representará de forma gráfica.

La transmisión de datos se ha realizado con un par de módulos XBee modelo *XBee XB24-ZB* ( uno Coordinator y el otro End Device ).

Este firmware está probado para el **PIC24F32KA301**.


## Description:

This firmware shows how to measure ambient light using **BH1750** device ( I2C bus ). We are going to get a data from BH1750 device each three seconds, and send it to our PC using the UART, so that the data can be showed on screen.
 
It was used a couple of XBee modules for the transmission.

This firmware was used with **PIC24F32KA301**.


## Datos Técnicos / Technical Data
* MPLAB X IDE v2.35.
* Compiler XC16 v1.22.


El proyecto completo se encuentra en la siguiente dirección: [AqueronteBlog Project](http://unbarquero.blogspot.com.es/2015/04/microchip-pic-i2c-bh1750-pic24f32ka301.html)
