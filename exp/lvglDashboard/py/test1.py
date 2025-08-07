import serial
import sys
import json

if len(sys.argv) != 2:
    print("Error Usage: test1.py USBDev")
    sys.exit(1)
    
    
state = {
    "BAT1CPU":False,
    "BAT2CPU":False,
    "BAT1DRIVE":False,
    "BAT2DRIVE":False,
    "BAT1CHARGE":True,
    "BAT2CHARGE":False,
    "BAT1VOLT": 0.0,
    "BAT2VOLT":13.5,
    "BAT1PER": 0.0,
    "BAT2PER": 83.0,
    "CHARGEVOLT": 0.0,
    "CHARGETIME": 0,
    "CHARGEREMAIN": 0,
    "CHARGEAVL": False
    }

def updateState():
    if state["BAT1PER"] < 1.0:
        state["CHARGEAVL"]= True
        state["BAT1CPU"] =False
        state["BAT1DRIVE"]=False
        state["BAT1CHARGE"] = True
        state["CHARGEREMAIN"]= 120
        state["BAT2CPU"] =True
        state["BAT2DRIVE"]=True
        state["BAT2CHARGE"] = False
        state["BAT2PER"] = 100.0
        state["BAT2VOLT"] = (4.5/100.0 * state["BAT2PER"]) + 10.0
    if  state["BAT1CHARGE"]:
        state["BAT1PER"] = state["BAT1PER"] + 5.0
        state["CHARGEREMAIN"] = state["CHARGEREMAIN"] - 5
        state["CHARGEVOLT"] = (4.5/100.0 * state["BAT1PER"]) + 10.0
        state["BAT2PER"] = state["BAT2PER"] - 5.0
        state["BAT2VOLT"] = (4.5/100.0 * state["BAT2PER"]) + 10.0
    else:
        state["BAT1PER"] = state["BAT1PER"] - 5.0
        state["BAT1VOLT"] = (4.5/100.0 * state["BAT1PER"]) + 10.0
        state["BAT2PER"] = state["BAT2PER"] + 5.0
        state["BAT2VOLT"] = (4.5/100.0 * state["BAT2PER"]) + 10.0
        state["CHARGEVOLT"] = (4.5/100.0 * state["BAT2PER"]) + 10.0
        state["CHARGEREMAIN"] = state["CHARGEREMAIN"] - 5
        
    if state["BAT1PER"] >= 100.0:
        state["BAT1PER"] = 100.0
        state["CHARGEAVL"]= False
        state["BAT1CPU"] =True
        state["BAT1DRIVE"]=True
        state["BAT1CHARGE"] = False
        state["BAT2CPU"] =False
        state["BAT2DRIVE"]=False
        state["BAT2CHARGE"] = True
        state["CHARGEREMAIN"]= 120
        
    state["BAT1VOLT"] = (4.5/100.0 * state["BAT1PER"]) + 10.0
        
    
with serial.Serial(sys.argv[1], 115200, timeout=1) as ser:
    count = 0
    while count < 5000:
        for i in range(5):
            line = ser.readline()   # read a '\n' terminated line
            print(line)
        
        s = json.dumps({"state": state})
        #print(s)
        b = bytearray()
        b.extend(map(ord, s + "\n"))
        ser.write(b)
        
        updateState();
        count = count + 1