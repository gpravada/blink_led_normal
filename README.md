# blink_led_normal
Blink led which is connected to GPIO5 on ESP32-C3

Flashing:

`esptool -p COM4 -b 460800 --before default_reset --after hard_reset --chip esp32c3  write_flash --flash_mode dio --flash_size detect --flash_freq 80m 0x0 ./ble-demo/bootloader-latest.bin 0x8000 ./ble-demo/partition-table-latest.bin 0x10000 ./ble-demo/ble-demo-latest.bin`

The above command also can get from build output in github actions of the project.

install esptool:

`pip install esptool`
