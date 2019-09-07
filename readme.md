# Steps needed to prepare STM32F103C8 (Blue Pill) to work with Arduino

## Files in this repo

* hid-flash.exe, not sure anymore
* st-flash.exe, st-info.exe and st-util.exe from https://github.com/texane/stlink if you want to manually upload the bootloader
* win_drivers.7z: Windows drivers for the STM32 when using the stm32duino bootloader
* stm32-pio-blink: Basic blink sketch using PlatformIO


## Rough steps to getting the STM32F103C8 working:

* Note: The generic blue boards do not come with the micro-USB enabled.
* You must flash the bootloader with generic_boot20_pc13.bin (assuming LED is PC13)
* Obtain STM32duino bootloader from https://github.com/rogerclarkmelbourne/STM32duino-bootloader/tree/master/binaries
* Easiest way to flash is via STLINK V2 and STM32CubeProg https://www.st.com/en/development-tools/stm32cubeprog.html
* To program, set Boot1 jumper to 1, then unplug/replug. LED should flash quickly.
* Connect via STM32CubeProg and select the .bin file, use address 0x08000000, size 0x400 and Data width 32-bit. Press Download.
* Important: After download complete, you must select Boot1 back to pin 0 before resetting the board!
* Now connect micro-USB to computer. A new USB Serial Device should appear under Ports (COM & LPT) in Windows Device Manager.

### Arduino IDE

* Using Arduino IDE, Google how to setup the IDE first.
* Upload settings
  * Board: Generic STM32F1
  * Board part number: Blue Pill F103C8
  * USART support: Enabled (generic Serial)
  * USB support: CDC (generic Serial). <- Important, if you don't enable this, you won't get COM port after upload.
  * Upload method: Maple DFU Bootloader 2.0
  * Port: <Check Windows Device Manager>

### PlatformIO

* Install PlatformIO extension in VS Code
* See https://docs.platformio.org/en/latest/boards/ststm32/bluepill_f103c8.html
* Use the following platformio.ini settings after creating a project

```
[env:genericSTM32F103CB]
platform = ststm32
board = genericSTM32F103C8
framework = arduino
upload_port = COM9
upload_protocol = dfu
```

## USB resistor problem
* The D+ of micro USB has a wrong resistor R10 value. It should be 1.5k ohm. 
* Check the resistance between pin A12 and 3.3v. If not, replace R10. I removed it and soldered a regular 1.5k resistor on above the board between A12 and 3.3v.


## References

* https://youtu.be/wGbiT6IxGP0
* https://www.onetransistor.eu/2017/11/stm32-bluepill-arduino-ide.html
* https://github.com/Serasidis/STM32_HID_Bootloader
* https://donneyfan.com/blog/usb-serial-for-blue-pill-stm32-with-platformio
* https://github.com/stm32duino/wiki/wiki/Upload-methods
* https://github.com/stm32duino/Arduino_Core_STM32
* https://circuitdigest.com/microcontroller-projects/getting-started-with-stm32-development-board-stm32f103c8-using-arduino-ide
* https://docs.platformio.org/en/latest/boards/ststm32/bluepill_f103c8.html
* http://reblag.dk/stm32/

## Further Reading
* https://medium.com/swlh/super-blue-pill-like-stm32-blue-pill-but-better-6d341d9347da