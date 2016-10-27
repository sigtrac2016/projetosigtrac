#/bin/python

import random as r
import os
import time

#Respiratory rate
respRateMean = 30
respRateStd = 7

#Heart rate
heartRateMean = 122
heartRateStd = 21

#Temperature
tempMean = 37.3
tempStd = 0.77

#Oxygen Sat
oxyMean = 98.6
oxyStd = 1.6

peopleMap = {1 : "Joao da Silva", 2 : "Carlos Costa", 3: "Sophia Cunha",
 			 4: "Jorge Amado", 5: "Leslie Lamport", 6: "Matheus Filho"}

print ("Creating Kafka messages...")

while (True):
	id =r.randint(1, 6)
	name = peopleMap[id]

	respR = r.gauss(respRateMean, 3*respRateStd)
	heartR = r.gauss(heartRateMean, 3*heartRateStd)
	temp = r.gauss(tempMean, 3*tempStd)
	oxy = r.gauss(oxyMean, oxyStd)

	command = ",".join([str(id), name, str(respR), str(heartR), str(temp), str(oxy)])

	print (command)
	os.system("echo " + command + " | ~/Apps/kafka/bin/kafka-console-producer.sh --broker-list localhost:9092 --topic test")

	time.sleep(2)