# PowerESP

ESP-IDF Project for managing smart BMS'es and provide smart powerbank functionality for USB charging and powering other 5v accesoiries such as a raspberry pi.

## Simplified Hardware Setup

This code runs/is developed in combination with the following hardware:
- ESP32 WROOM32D DevKit C2
- PCA9632DP1 4bit/channel i2c pwm led controller
- SSD1306 w/ 128x32 oled(0.91") using i2c
- Dual n-channel mosfet(using 2x single channel is also okay)
- P-channel mosfet(these mosfets are combined with a button and custom io logic to bootstrap power and shutdown when needed)
- 2 channel level/logic shifter(bidirectional 3.3v-5v) using BSS138 n-channel mosfets
- 50w 12-24v to 5v stepdown module
- buckboost converter for charging li-ion battery
- Smart BMS(JDB-BMS) with uart connection(4S3P setup, 30A max current draw, 10-16.8v, ~0.15kWh)
- Bunch of other components which make the rest work together.

Hardware/kicad/final project might be released on this or another repository later in time. It is too early to provide an alpha release.

## Libraries used

Many thanks to the following repositories/libraries which are used:
- [I2Cbus](https://github.com/natanaeljr/esp32-I2Cbus) Forked: [here](https://github.com/Camphul/esp32-I2Cbus) to fix some minor bugs and add custom functionality.
- [freertos-addons](https://github.com/eagi223/freertos-addons-ESP32-Port) Forked: [here](https://github.com/Camphul/freertos-addons-ESP32-Port) for stability when this repository is cloned.

## License

Please refer to [LICENSE](LICENSE) to see the project's license(MIT).
