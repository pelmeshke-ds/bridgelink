# Wrong board upload

> I chose wrong processor (ex. ATmega32U4 3.3V 8MHz, not 5V 16MHz) for the SparkFun Pro Micro board, now when I try upload sketch Arduino IDE doesn't detect any board (on Windows) or output is `avrdude: butterfly_recv(): programmer is not responding` (on UNIX-like)

1. Connect your board via USB to your computer, open Arduino IDE board selection (**Select other board and port...**)
2. Choose right board in Arduino IDE, paste a minimal sketch, something like this:
    ```ino
    void setup() {} 
    void loop() {}
    ```

    Save it
3. Enter the bootloader mode
    * Press twice rapidly reset button (if your board has such)
    * Or locate RST and GND pins on the board, pick a wire and double-tap RST pin and GND pin together rapidly

    Delay between pressing or tapping should be less than 500ms. This will enter your board into bootloader mode for ~8 seconds, board's leds can flicker at that time

4. In Arduino IDE you should see new serial port (ex. COM4 or /dev/XXX), switch to it and try to upload a plain sketch
5. If IDE's output is `avrdude: ser_open(): can't open device "\\.\COM4"`, try another time

If time of bootloader mode is too short for Arduino IDE to upload the sketch, try this:

1. Download AVRDUDE for your platform: [https://github.com/avrdudes/avrdude/releases/latest](https://github.com/avrdudes/avrdude/releases/latest)
2. Unzip downloaded archive
3. Export a compiled binary of the sketch (**Sketch** -> **Export Compiled Binary**), in sketch folder you should get `build/sketch_XXX.ino.hex`
4. Launch command line terminal, type this command, but don't press Enter: 
    ```sh
    ./path/to/avrdude -p atmega32u4 -c avr109 -P YOURPORT -b 57600 -U flash:w:"./path/to/build/sketch_XXX.ino.hex":i
    ```

    Replace paths for `avrdude` and `sketch_XXX.ino.hex`, `YOURPORT` for your port or `usb:048C:26AE` for UNIX (where `048C` is VID and `26AE` is PID)

5. Trigger the bootloader mode by tapping RST and GND pins and hit Enter. Sketch's upload should have started 

In desperate cases consider using an external programmer (ex. another Arduino) or research more about it
