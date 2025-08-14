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

## Host device daemon installation

TODO


