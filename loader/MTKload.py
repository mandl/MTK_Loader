#!/usr/bin/env python3
#
# Bootloader Utility for MTK
#
#
# This program is free software; you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation; either version 2 of the License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful, but WITHOUT 
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# this program; if not, write to the Free Software Foundation, Inc., 51 Franklin
# Street, Fifth Floor, Boston, MA 02110-1301 USA.


import argparse
import csv
import os
import struct
import sys
import time
import traceback

import serial


class MTKLoader:

    # These are the currently known commands supported by the ROM
    # 0xA0 0x5F / 0x0A 0xF5 /0x50 0xAF / 0x05 0xFA 
    MTK_BAECON = 0xA0
    
    # write 16 bit    0xA1  + Address 32 bit + lentgh (words) + data
    MTK_COMMAND_WRITE16 = 0xA1
    # read 16bit    0xA1 + Address 32 bit + length ( words )
    MTK_COMMAND_READ16 = 0xA2
    # write 32 bit
    MTK_COMMAND_WRITE32 = 0xAE
    MTK_COMMAND_READ32 = 0xAF
    
    # start code 0xA8 + Address
    MTK_COMMAND_START = 0xA8
    
    # calc xor checksum 0xA4 + address + length
    MTK_C0MMAND_CHECKSUM = 0xA4
    
    
    WRITE_SIZE = 1024
    
    ChipVersion = 0x6516
    
  
    def __init__(self, port, baud):
        self._port = serial.Serial(port, baud)

    def changeBaud(self, baud):
        self._port.setBaudrate(baud)
    
    """ send baecon """
    def mtksendsync(self):
       
        self._port.write(struct.pack('B', self.MTK_BAECON))
        val = self._port.read(1)
        return val
        
    """ enable bootloader """
    def mtksync(self):
        # 0xA0 0x5F / 0x0A 0xF5 /0x50 0xAF / 0x05 0xFA 
        print ('Send sync magic')
        
        self._port.write(struct.pack('B', 0x0A))
        if self._port.read(1) != b'\xf5':
            raise Exception('snyc lost 2')
        self._port.write(struct.pack('B', 0x50))
        if self._port.read(1) != b'\xaf':
            raise Exception('snyc lost 3')
        self._port.write(struct.pack('B', 0x05))
        if self._port.read(1) != b'\xfa':
            raise Exception('snyc lost 4')

    """ Read a 16 bit register """
    def read16(self, adr):
        pkt = struct.pack('>I', adr)
        
        command = struct.pack('B', self.MTK_COMMAND_READ16)
        self._port.write(command)
        if self._port.read(1) != command:
            raise Exception('Invalid resonse command')
        self._port.write(pkt)
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse address')
        pkt = struct.pack('>I', 0x01)
        self._port.write(pkt)
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse length')
        val = self._port.read(2)
        value, = struct.unpack('>H', val)
        return value
            
    """ write a 16 bit register """
    def write16(self, adr, data):
        pkt = struct.pack('>I', adr)
        
        command = struct.pack('B', self.MTK_COMMAND_WRITE16)
        self._port.write(command)
        if self._port.read(1) != command:
            raise Exception('Invalid resonse command')
        self._port.write(pkt)
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse address')
        pkt = struct.pack('>I', 0x01)
        self._port.write(pkt)
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse length')
        pkt = struct.pack('>H', data)
        self._port.write(pkt)
        if self._port.read(2) != pkt:
            raise Exception('Invalid resonse data')

    """ write a 32 bit register """
    def write32(self, adr, data):
        pkt = struct.pack('>I', adr)
        
        command = struct.pack('B', self.MTK_COMMAND_WRITE32)
        self._port.write(command)
        if self._port.read(1) != command:
            raise Exception('Invalid resonse command')
        self._port.write(pkt)
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse address')
        pkt = struct.pack('>I', 0x01)
        self._port.write(pkt)
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse length')
        pkt = struct.pack('>I', data)
        self._port.write(pkt)
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse data')
        
    """ write a 32 bit register """
    def read32(self, adr):
        pkt = struct.pack('>I', adr)
        
        command = struct.pack('B', self.MTK_COMMAND_READ32)
        self._port.write(command)
        if self._port.read(1) != command:
            raise Exception('Invalid resonse command')
        self._port.write(pkt)
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse address')
        pkt = struct.pack('>I', 0x01)
        self._port.write(pkt)
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse length')
        
        val = self._port.read(4)
        value, = struct.unpack('>I', val)
        return value
        
        
        
    """ write a block of words """
    def writeBlock(self, adr, filename):
        
        odd = 0;
        if not os.path.isfile(filename):
            raise Exception('Can not open file: %s') % (filename)
        
        
        f = open(filename, 'rb')
        
        fileSize = self.getSize(filename) 
        
        print ('Bytes to send %d' % (fileSize))
        if fileSize == 0:
            raise Exception('File is empty')
        if fileSize % 2:
            # odd file size add one byte
            odd = 1
            print ('Odd filesize. Add dummy byte')
            
        
        command = struct.pack('B', self.MTK_COMMAND_WRITE16)
        self._port.write(command)
        if self._port.read(1) != command:
            raise Exception('Invalid resonse command')
        
        pkt = struct.pack('>I', adr)
        self._port.write(pkt)
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse address')
        
        pkt = struct.pack('>I', fileSize // 2)
        self._port.write(pkt)
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse length')
        # write block
        checksum = 0;
        for i in range(fileSize // self.WRITE_SIZE):
            var = f.read(self.WRITE_SIZE)
            out = bytes([c for t in zip(var[1::2], var[::2]) for c in t])
            self._port.write(out)
            datain = self._port.read(self.WRITE_SIZE)
            if out != datain :
                raise Exception('Write/ Read error')
            print ("Block  {0:2d} send 1024k".format(i))
          
        if fileSize % self.WRITE_SIZE:
            
            var = f.read()
            print ('Send last data %d' % len(var))
            out = bytes([c for t in zip(var[1::2], var[::2]) for c in t])
            self._port.write(out)
            datain = self._port.read(len(var))
            if out != datain :
                raise Exception('Write/ Read error')
            if odd == 1:
                # send dummy byte
                self._port.write(b'\x00')
                datain = self._port.read(1)
            
       
    def readBlock(self, adr, length, filename):
        print('Read block')
               
        f = open(filename, 'wb')
        
        pkt = struct.pack('>I', adr)
        
        command = struct.pack('B', self.MTK_COMMAND_READ16)
        self._port.write(command)
        if self._port.read(1) != command:
            raise Exception('Invalid resonse command')
        
        self._port.write(pkt)
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse address')
        
        pkt = struct.pack('>I', length)
        self._port.write(pkt)
        
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse length')
        
        var = self._port.read(length * 2)
        out = ''.join([c for t in zip(var[1::2], var[::2]) for c in t])
        f.write(out)
        f.close()
        
    
    def startProg(self, adr):
        
        print ('Start program. good luck....')
        command = struct.pack('B', self.MTK_COMMAND_START)
        self._port.write(command)
        if self._port.read(1) != command:
            raise Exception('Invalid resonse command start')
        pkt = struct.pack('>I', adr)
        self._port.write(pkt)
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse address')
        
    def calCheckSum(self, adr, length):
        
        command = struct.pack('B', self.MTK_C0MMAND_CHECKSUM)
        self._port.write(command)
        
        if self._port.read(1) != command:
            raise Exception('Invalid resonse command start')
        
        pkt = struct.pack('>I', adr)
        self._port.write(pkt)
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse address')
        
        pkt = struct.pack('>I', length)
        self._port.write(pkt)
        if self._port.read(4) != pkt:
            raise Exception('Invalid resonse length')
        val = self._port.read(2);
        ret = struct.unpack('>H', val)
        return ret
    
    """ Dump as hex """
    def dump2(self, src, length=8):
        result = []
        FILTER = ''.join([(len(repr(chr(x))) == 3) and chr(x) or '.' for x in range(256)])

        for i in xrange(0, len(src), length):
            s = src[i:i + length]
            hexa = ' '.join(["%02X" % ord(x) for x in s])
            printable = s.translate(FILTER)
            result.append("%04X   %-*s   %s\n" % (i, length * 3, hexa, printable))
        return ''.join(result)
 
    def getSize(self, filename):
        st = os.stat(filename)
        return st.st_size
    
    def getFileCrc(self, filename):
        if not os.path.isfile(filename):
            raise Exception('Filename is wrong')
    
        crcsum = 0x0000
        with open(filename, 'rb') as f:
            integer = f.read(2)  # In fact, you could read all in.
            while len(integer) >= 2:
                # if integer is not a string longer than 4, next line crash.
                s, = struct.unpack('<H', integer)  # The return value is a tuple with integers.
               
                crcsum = (crcsum & 0x0000FFFF) ^ s
                integer = f.read(2)
     
        
        print('Checksum of %s is 0x%x' % (filename, crcsum))
        return crcsum
        
    def readCommandFile(self, regfile):
        print ('Read register')
        
        spamreader = csv.reader(regfile)
        for row in spamreader:
            print (', '.join(row))
            if int(row[1], 16) == 0x16:
                val = self.read16(int(row[0], 16))
                print ('0x%04x' % val)
            else:
                val = self.read32(int(row[0], 16))
                print ('0x%08x' % val)
                    
    def sendCommandFile(self, regfile):
        print ('Send command file')
        
        spamreader = csv.reader(regfile)
        for row in spamreader:
            print (', '.join(row))
            if int(row[1], 16) > 0xFFFF:
                self.write32(int(row[0], 16), int(row[1], 16))
            else:
                self.write16(int(row[0], 16), int(row[1], 16))
            time.sleep(0.2)
    
    # Enable Autobaud and switch to 115200 Baud so we can upload faster
    #
    def autoBaud(self):
        # enable auto baud
        print ('Autobaud. Set baud to 115200')
        if self.ChipVersion == 0x6516:
            self.write16(0x80023038, 13)  # set clock to 26Mhz
            self.write16(0x80023020, 1)  # enable autobaud
        elif self.ChipVersion == 0x6223:
            self.write16(0x80130038, 13)  # set clock to 26Mhz
            self.write16(0x80130020, 1)  # enable autobaud
        else:
            raise Exception('New chip version')

        self._port.baudrate = 115200
        self._port.write(b"AT")
        self._port.read(2)
        self._port.write(b'\xFF')
        self._port.read(1)
        self._port.write(b'\xFE')
        self._port.read(1)
   
    # Get Chip Version 
    def getChipVersion(self):
        self.ChipVersion = self.read16(0x80001008)
        print ('Chip Version: %x' % self.ChipVersion)

    # Switch on baseband and disable watchdog.
    #
    def BasebandOn_WatchdogOff(self):
        print ('Baseband on - Watchdog off')
        if self.ChipVersion == 0x6516:
            self.write16(0x8002C068, 0x9136)
            self.write16(0x8002C074, 0x0001)  # write action
            self.write16(0x8002C000, 0x430E)  # Power up Baseband
            self.write16(0x8002C074, 0x0001)  # write action
            self.write16(0x80003000, 0x2200)  # Disable watchdog

        elif self.ChipVersion == 0x6223:
            self.write16(0x80210050, 0xA357)  # RTC_POWERKEY1
            self.write16(0x80210054, 0x67D2)  # RTC_POWERKEY2
            self.write16(0x80210000, 0x430E)  # Power up Baseband
            self.write16(0x80040000, 0x2200)  # watchdog off
        else:
            raise Exception('New chip version. Send a patch')
            
        
    

    
   
    # Try connecting repeatedly until successful, or giving up
    def connect(self):
        print ('Please press power and hold the button')
        print ('Try connecting. Sending beacon 0xA0....')
        self._port.timeout = 0.1
        self._port.flushInput()
        self._port.flushOutput()
        for i in range(20000):
            
            val = self.mtksendsync()
            if val == b'\x5f':
                self.mtksync()
                self._port.timeout = 1
                print ('Connect done')
                return
               
        raise Exception('Connect fail. Timeout')
      

def arg_auto_int(x):
    return int(x, 0)

def main():
    parser = argparse.ArgumentParser(description='MTKLoader Bootloader Utility', prog='mtktool')

    parser.add_argument(
            '--port', '-p',
            help='Serial port device',
            default='/dev/ttyUSB0')
    parser.add_argument(
            '--baud', '-b',
            help='Serial baudrate',
            default='19200')   
    
    parser.add_argument(
            '--speed', action="store_true",
            help='Change baudrate to 115200 after connect to device',
            default=False)   
    
    parser.add_argument(
            '--writeregfile', type=argparse.FileType('r'),
            help='File config file with write register data')
    parser.add_argument(
            '--readregfile', type=argparse.FileType('r'),
            help='File config file with read register data')
    parser.add_argument(
            '--no_connect',
            help='Skip connect routine')
    
    subparsers = parser.add_subparsers(
            dest='operation',
            help='Run MTKload {command} -h for additional help')

    parser_write_flash = subparsers.add_parser('load_prog', help='Write a binary blob to memory')
    parser_write_flash.add_argument('filename', help='Binary file to write', default='main.bin', nargs='?')
    parser_write_flash.add_argument('loadadr', type=arg_auto_int, default=0x40001400, help='Load address for file', nargs='?')
   
    
    parser_dump_mem = subparsers.add_parser('dump_mem', help='Dump memory to a file')
    parser_dump_mem.add_argument('filename', help='Binary dump file')
    parser_dump_mem.add_argument('startadr', type=arg_auto_int, help='Load address for file')
    parser_dump_mem.add_argument('length', type=arg_auto_int, help='Number of word to dump')
    

    args = parser.parse_args()

    # Create the MTKLoader connection object, if needed
    esp = None
    
    esp = MTKLoader(args.port, args.baud)

    try:
        esp.connect()
    except KeyboardInterrupt:
        return
   
    
    # sende register
    if args.writeregfile != None:
        esp.sendCommandFile(args.writeregfile)
 
    # sende register
    if args.readregfile != None:
        esp.readCommandFile(args.readregfile)     
    
    
    # detect chip    
    esp.getChipVersion()

    # switch baseband on   watchdog off 
    esp.BasebandOn_WatchdogOff()

    # change to a higher baudrate
    if args.speed == True:
        esp.autoBaud()

    if args.operation == 'load_prog':
        
       
        print ('Upload file %s to 0x%x' % (args.filename, args.loadadr))
       
        esp.writeBlock(args.loadadr, args.filename)
        
        fileSize = esp.getSize(args.filename) 
        
        checksum = esp.getFileCrc(args.filename)
        
        var = esp.calCheckSum(args.loadadr, fileSize // 2)
        
        print ('Checksum at device 0x%02x' % var[0])
        if checksum != var[0]:
            print ('Checksum error !!!?????')
        
        esp.startProg(args.loadadr)
       
               
    elif args.operation == 'dump_mem':
        print ('Dump memory start 0x%x length 0x%x to file %s' % (args.startadr, args.length, args.filename))
        esp.readBlock(args.startadr, args.length, args.filename)

    print ('Done')

if __name__ == '__main__':
    try:
        main()
    
    except Exception as ex:
        
        print(ex)
        traceback.print_exc()  
    
       
        
