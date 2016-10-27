
"""
 Usage: streaming.py <broker_list> <topic>
 
 To run this on your local machine, you need to setup Kafka and create a producer first, see
 http://kafka.apache.org/documentation.html#quickstart

 and then run the example
    `$ bin/spark-submit --jars \
      external/kafka-assembly/target/scala-*/spark-streaming-kafka-assembly-*.jar \
      examples/src/main/python/streaming/direct_kafka_wordcount.py \
      localhost:9092 test`
"""
from __future__ import print_function

import sys
import os
import random as r

from pyspark import SparkContext
from pyspark.streaming import StreamingContext
from pyspark.streaming.kafka import KafkaUtils

from sklearn.externals import joblib
import numpy as np
import pyrebase


#Firebase app config
config = {
   "apiKey": "AIzaSyDWDKZiSTARk_gbCzcKsqiktgKCZe90e24",
   "authDomain": "sigtrac-ml.firebaseapp.com",
   "databaseURL": "https://sigtrac-ml.firebaseio.com",
   "storageBucket": "sigtrac-ml.appspot.com",
   "messagingSenderId": "392417460659"
 };


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: streaming.py <broker_list> <topic>", file=sys.stderr)
        exit(-1)

    #Start firebase
    firebase = pyrebase.initialize_app(config)
    db = firebase.database()

    sc = SparkContext(appName="PythonStreamingDirectKafka")

    #Batchs of 2 seconds each
    ssc = StreamingContext(sc, 1)

    brokers, topic = sys.argv[1:]

    #Load trained model
    currDir = os.path.dirname(os.path.realpath(__file__))
    print (currDir)
    model = joblib.load(currDir + '/MTS classifier/models/svmClassifier-scaled.pkl') 

    kvs = KafkaUtils.createDirectStream(ssc, [topic], {"metadata.broker.list": brokers})

    lines = kvs.map(lambda x: x[1])

    def pacientProcessor(line):
        tokens = line.split(",")
        id = tokens[0]
        name = tokens[1]

        x = np.array([float(t) for t in tokens[2:]])
        #predict using trained classifer
        predicted = int(model.predict(x)[0]) + r.randint(-3, 1)

        return ','.join([tokens[0], tokens[1], str(predicted)])

    def sendToFirebase(rdd):
        def send(line):
            tokens = line.split(",")
            id = tokens[0]
            name = tokens[1]
            predicted = tokens[2]

            #Send to firebase
            db.child("status").set(predicted)
            db.child("user_id").set(id)
            db.child("user_name").set(name)

        rdd.foreach(send)

    processed_pacient_lines = lines.map(pacientProcessor)

    #processed_pacient_lines.cache()
    processed_pacient_lines.foreachRDD(sendToFirebase)
    processed_pacient_lines.pprint()

    ssc.start()
    ssc.awaitTermination()
