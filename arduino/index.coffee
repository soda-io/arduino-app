# https://www.npmjs.org/package/serialport

SerialPort = require("serialport").SerialPort
serialPort = new SerialPort "/dev/tty.usbmodem1411", baudrate: 115200

serialPort.on "open", ->
  console.log "open"

exports.enable = (fn=->) ->
  serialPort.write "on\n", (err) ->
    fn err                      # null

exports.disable = (fn=->) ->
  serialPort.write "off\n", (err) ->
    fn err



