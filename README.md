# bridgelink

**BridgeLink** is a component that connects input driver controller and host device via UART. This enables HID input (such as buttons, sticks position, gyroscope data) forwarding from controllers to Linux hosts

In **pelmeshke-ds** BridgeLink is used for communication between Arduino Pro Micro (also known as SparkFun Pro Micro with ATmega32U4) and Raspberry Pi Zero 2 W

## Controller firmware installation

The provided code is supposed for use on Arduino Pro Micro (or other HID-compatible Arduino-like controllers)

1. Download the latest version of Arduino IDE from https://www.arduino.cc/en/software/

2. Install required libraries:
    * Go to **Sketch** -> **Include Library** -> **Manage Libraries**
    * Search and install:
        * `HID-Project` by NicoHood ([https://github.com/NicoHood/HID](https://github.com/NicoHood/HID))
        * `MPU6050` by Electric Cats ([https://github.com/electroniccats/mpu6050](https://github.com/electroniccats/mpu6050))

3. Connect your board to your computer with IDE. Select your board:

    Add package with SparkFun specific boards:

    * **File** -> **Preferences** -> Add to **Additional Boards Manager URLs**:
        ```
        https://raw.githubusercontent.com/sparkfun/Arduino_Boards/master/IDE_Board_Manager/package_sparkfun_index.json
        ```
    * **Tools** -> **Board** -> **Boards Manager** -> Search for "SparkFun Pro Micro" -> Install **SparkFun AVR Boards** package
    * Select board: **Tools** -> **Board** -> **SparkFun AVR Boards** -> **SparkFun Pro Micro**
    * Select right processor: **Tools** -> **Processor** -> **ATmega32U4 (5V, 16MHz)** or **ATmega32U4 (3.3V, 8MHz)**

    If you have a board with **ATmega32U4 (5V, 16MHz)** you can skip all those steps. You can select preinstalled board: **Tools** -> **Board** -> **Arduino AVR Boards** -> **Arduino Micro**. It should work the same

4. Upload firmware:
    * Download and open `controller/controller.ino` in Arduino IDE
    * Upload the sketch by pressing button with an arrow (or **Sketch** -> **Upload**)

    If Arduino board is soldered to Raspberry Pi connect Raspberry Pi to sufficient power source



## Host daemon installation

The following instruction should work on all Raspberry Pi boards supporting Linux and having UART interface

1. Enable UART on your Raspberry Pi by using one on these methods:

    * Add in your boot config `/boot/config.txt` this line:
        ```config.txt
        enable_uart=1
        ```

        You can do it with SD boot card plugged into your PC
    
    * Or use raspi-config on powered Raspberry Pi. Type in the terminal
        ```sh
        sudo raspi-config
        ```

        Select **3 Interface Options** -> **I6 Serial Port**

        Select **No** to **Would you like a login shell to be accessible over serial?**

        Select **Yes** to **Would you like the serial port hardware to be enabled?**

        The output should be this:
        ```
        The serial login shell is disabled 
        The serial interface is enabled
        ```

    * Or type this command in the terminal:
        ```sh
        sudo raspi-config nonint do_serial 2
        ```

    Reboot your Raspberry Pi to make the changes take effect

2. Enter in the terminal:

    ```sh
    git clone https://github.com/pelmeshke-ds/bridgelink.git
    ```

    TODO


