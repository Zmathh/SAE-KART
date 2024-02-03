# -*- coding: utf-8 -*-
#!/usr/bin/env python
from __future__ import print_function
import argparse
import sys
import serial
import binascii
import time
import datetime

RN2483_CMD_ENDING       = "\r\n"
RN2483_RSP_OK           = "ok"
RN2483_RSP_TX_OK        = "radio_tx_ok"
RN2483_RSP_RX_OK        = "radio_rx  "
RN2483_RSP_MAC_PAUSE_OK = "4294967245"  # 0xFFFFFFCD
RN2483_RSP_RESET        = "RN2483"

###############################################################################
class LoRa_RN2483():
  def __init__(self, port):
    self.port = port      # /dev/ttyS0
    self.serial = None
    self.timeout = 5

  def send_data(self, data):
    if self.serial:
      if data[-2:] == RN2483_CMD_ENDING:
        print(">> ", data[:-2])
      else:
        print(">> ", data)
      self.serial.write(data.encode('utf-8'))
      return True

  def rcv_data(self):
    if self.serial:
      read = ''
      reading = True
      td = datetime.datetime.now() + datetime.timedelta(seconds=self.timeout)
      while reading and datetime.datetime.now() < td:
        available = self.serial.in_waiting
        if available > 0:
          # print("Chars available: {0}".format(available))
          for i in range(available):
            c = self.serial.read().decode('utf-8')
            read += c
            if read[-2:] == RN2483_CMD_ENDING:
              # print("Answer received.")
              reading = False

      if len(read):
        if read[-2:] == RN2483_CMD_ENDING:
          print("<< ", read[:-2])
        else:
          print("<< ", read)
        return read

  def send_cmd(self, cmd, expectedRsp=None):
    cmd += RN2483_CMD_ENDING

    if self.send_data(cmd):
      t = 0
      while t < 3:
        t += 1
        rsp = self.rcv_data()
        if rsp and len(rsp):
          if expectedRsp and len(expectedRsp):
            if rsp.startswith(expectedRsp):
              return rsp
          else:
            return rsp

  def info(self):
    self.send_cmd('sys get ver')
    self.send_cmd('sys get hweui')
    self.send_cmd('sys get vdd')

    # Radio parameters
    self.send_cmd('radio get mod')
    self.send_cmd('radio get freq')
    self.send_cmd('radio get pwr')
    self.send_cmd('radio get sf')
    self.send_cmd('radio get rxbw')
    self.send_cmd('radio get prlen')
    self.send_cmd('radio get crc')
    self.send_cmd('radio get iqi')
    self.send_cmd('radio get cr')
    self.send_cmd('radio get wdt')
    self.send_cmd('radio get sync')
    self.send_cmd('radio get bw')

    return True
    
  def config(self):
    if not self.send_cmd('mac pause', RN2483_RSP_MAC_PAUSE_OK):
      return
    if not self.send_cmd('radio set mod lora', RN2483_RSP_OK):
      return
    if not self.send_cmd('radio set freq 868100000', RN2483_RSP_OK):
      return
    if not self.send_cmd('radio set pwr 15', RN2483_RSP_OK):
      return
    if not self.send_cmd('radio set sf sf8', RN2483_RSP_OK):
      return
    if not self.send_cmd('radio set rxbw 125', RN2483_RSP_OK):
      return
    if not self.send_cmd('radio set prlen 8', RN2483_RSP_OK):
      return
    if not self.send_cmd('radio set crc on', RN2483_RSP_OK):
      return
    if not self.send_cmd('radio set iqi off', RN2483_RSP_OK):
      return
    if not self.send_cmd('radio set cr 4/5', RN2483_RSP_OK):
      return
    if not self.send_cmd('radio set wdt 0', RN2483_RSP_OK):     # 0 for continous reception, otherwise 2000 
      return
    if not self.send_cmd('radio set sync 12', RN2483_RSP_OK):   # 34 public, 12 private network
      return
    if not self.send_cmd('radio set bw 125', RN2483_RSP_OK):
      return
    return True

  def sw_reset(self):
    if not self.send_cmd('sys reset', RN2483_RSP_RESET):
      return
    return True

  def factoryReset(self):
    if not self.send_cmd('sys factoryRESET', RN2483_RSP_RESET):
      return
    return True

  def tx(self, data):
    if not self.send_cmd('mac pause', RN2483_RSP_MAC_PAUSE_OK):
      return
    if not self.send_cmd(('radio tx ' + data), RN2483_RSP_TX_OK):
      return
    return True

  def rx(self):
    if not self.send_cmd('mac pause', RN2483_RSP_MAC_PAUSE_OK):
      return
    
    data = self.send_cmd('radio rx 0', RN2483_RSP_RX_OK)
    if data:
      data = data.replace(RN2483_RSP_RX_OK, '')
      return data

  def open(self):
    self.serial = serial.Serial(
        port=self.port,
        baudrate=57600,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS,
        timeout=1
      )
    if self.serial:
      print("Serial port opened.")
    return self.serial

  def close(self):
    if self.serial:
      self.serial.close()
      self.serial = None
      print("Serial port closed.")

supported_operations = ['info', 'config', 'swreset', 'factory', 'tx', 'rx']

###############################################################################
def parseArgs(argv):
  parser = argparse.ArgumentParser()

  op = ''
  for o in supported_operations:
    if len(op):
      op = op + ', '
    op = op + o
  op = 'One out of these operations: ' + op

  parser.add_argument('-o', '--operation', required=True, help=op)
  parser.add_argument('-p', '--port', required=True, help="USB/serial com port: Windows: com1, com2...")
  
  return parser.parse_args(argv)

###############################################################################
def main(argv=sys.argv[1:]):
  args = parseArgs(argv)
  
  operations = args.operation.lower().replace(';', ' ').replace(',', ' ').split()

  # lora = LoRa_E22(args.port)
  lora = LoRa_RN2483(args.port)

  try:
    if lora.open():
      for o in operations:
        print("Operation: ", o)

        if o == "info":
          lora.info()
        elif o == "config":
          lora.config()
        elif o == "swreset":
          lora.sw_reset()
        elif o == "factory":
          lora.factoryReset()
        elif o == "tx":
          # for _ in range(255):
          print(lora.tx('FF1122334455778899FF'))
          # lora.send_data('Hello')
          # lora.send_data(b'\x12\x12\x12\x12\x12\x12\x12\x12\x12\x12\x12\x12\x12\x12')
        elif o == "rx":
          lora.rx()
        else:
          print("Unknown operation!")
      
      lora.close()
  except Exception as e:
    print("Exception:", e)
  finally:
    lora.close()

if __name__ == "__main__":
  main()
    
  