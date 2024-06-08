import serial
f = open('data.csv','a')
arduino = serial.Serial('COM4', 9600)

f.write('VoltajeMQ135,VoltajeMQ4,SensibilidadMQ135,SensibilidadMQ4,ConcentracionMQ135,ConcentracionMQ4,Temperatura,Humedad\n')
while True:
    rawString = arduino.readline().decode("utf-8").replace('\r\n', '')
    f.write(rawString+'\n')
    print(rawString)

f.close()
arduino.close()