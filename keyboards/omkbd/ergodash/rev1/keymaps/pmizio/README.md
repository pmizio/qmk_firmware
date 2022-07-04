# ISP Flash ProMicros with QML-DFU bootloader
```sh
avrdude -c arduino -p m32u4 -P COM6 -U flash:w:"ergodash_production.hex":a -U lfuse:w:0x5E:m -U hfuse:w:0x99:m -U efuse:w:0xC3:m
``` 

# Fish shell script to run qmk-cli using Docker
## WSL2 script autostarting Docker before running QMK
```fish
function qmkd
  set -l RUNNING (ps aux | grep dockerd | grep -v grep)

  if test -z "$RUNNING";
    sudo dockerd > /dev/null 2>&1 &
    disown
    sleep 2
  end

  bash -c "$HOME/qmk_firmware/util/docker_build.sh $argv"
end
```
