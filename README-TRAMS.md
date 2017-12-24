# Marlin for MP Select mini v1

## TL;DR;
This is a fork of Marlin to support [Monoprice MP Select Mini V1](https://www.mpselectmini.com/) with its electronics replaced with Arduino Mega R3 + a hacked [TRAMS](https://www.trinamic.com/support/eval-kits/details/trams/) board.

TRAMS board uses [TMC5130](https://www.trinamic.com/products/integrated-circuits/details/tmc5130/) drivers that are not supported by Marlin. Trinamic has its own [version of Marlin](https://github.com/trinamic/TRAMS-Firmware) with extensive changes to use advanced functionality provided by TMC5130 drivers, but it has not been updated since the port was made circa marlin 1.0.

However, with fairly small changes the board can be modified to work in STEP/DIR mode which essentially makes the drivers compatible with [TMC2130](https://www.trinamic.com/products/integrated-circuits/details/tmc2130/) which is supported natively by Marlin since 1.1.7.
In order to enable STEP/DIR mode, carefully cat away pins 11 (SD_MODE) and 12(SPI_MODE) on each driver. Technically, you only need to cut pin 11 as pin 12 is not connected to anything, but practically pin 12 is in the way, so cutting it out makes it possible to cut pin 11 as well. Note that this will render the board incompatible with the Trimatic's version of Marlin.

Pin DCEN_CFG4 is left floating on TRAMS which enables dcStep mode. It's a pretty useful feature in general -- you can drive the load with minimum current and the driver will tell you if/when you've lost steps and how many, and you can compensate for that. Alas, it seems to interfere with the way Marlin's code uses the drivers, so we need to disable dcStep by connecting DCEN_CFG4 to GND. Neighboring pin 23 is already connected to GND, so shorting pin 23 and 24 together on all drivers does the job nicely.

Now you need to connect Step/DIR pins of each driver. The pins responsible for these functions are already available on endstop headers on the board. Connect pins 1 and 5 of each endstop connector to the pins on AUX2 connector described in pins_TRAMS.h. TODO: transcribe specific wiring from my board.

Next we need to hook up normal endstop switches. I've repurposed servo pins for that. Endstop connectors should be connected to GND and servo signal pins. X -> SERVO0, Y -> SERVO1, Z -> SERVO2.

Connecting steppers is a bit of a pain. Connectors on TRAMS are not the standard 4-pin connectors you typically see, but it is possible to plug MP mini's steppers into TRAMS by snipping off plastic ridges on the back of the plug and use some force. I may replace them with 'standard' connectors later. Brute force will do for now.

Temperature sensors go into appropriate sensor connectors. Got to snip the ridges on the back, too.

Hotend, bed heater and fan go into the screw-on connectors on the edge. I've used bits of stiff copper wire to connect things together.

## Once it's up

Z axis appears to struggle during homing with 4mm/s travel speed in StealthChop mode. Reducing max to 3mm/s seems to have fixed the issue.

Oh, did I mention that the printer is virtually silent now? It is virtually silent now. All I can hear is occasional mechanical rattle when things change direction fast, but the ever-present noise of the steppers is *completely* gone. I'm very impressed.

## Sensorless homing.

It works now. The wires for X/Y endstops can be removed now. :-)
