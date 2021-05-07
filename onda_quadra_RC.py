# libraries
import serial
from drawnow import drawnow
import matplotlib.pyplot as plt

# plot function
def makeplot():
    # plot voltage vs time
    plt.plot(x, vC, 'r--o')
    plt.plot(x, vIN, 'b')
    plt.grid('-')
    plt.xlabel("time (s)", fontsize=18)
    plt.ylabel("voltage (V)", fontsize=18)
    plt.xticks(fontsize=18)
    plt.yticks(fontsize=18)
    plt.tight_layout()

# read from arduino
arduino = serial.Serial('/dev/cu.usbmodem1431101', 9600)
# initialize measured data and figure
x = []
vC = []
vIN = []
plt.figure(figsize=(10, 8))
# start aquisition

print(' Time   |  Voltage')
go = True
while go:
    read = arduino.readline()
    time, voltageIN, voltageC = [float(k) for k in read.decode('ascii').split(";")]
    x.append(time * 1e-6)
    vC.append(voltageC)
    vIN.append(voltageIN)
    # make plot
    drawnow(makeplot)
    print('%05.3f %s %05.3f %s' % (round(time * 1e-6, 3), 's | ', round(voltageC, 3), 'V'))
    if (time * 1e-6) > 5:
        go = False

makeplot()
plt.show()
