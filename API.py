import sys
import BaseHTTPServer
from SimpleHTTPServer import SimpleHTTPRequestHandler
from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer
import pymongo
from pymongo import MongoClient
import datetime
import math, os
import boto
from filechunkio import FileChunkIO
from boto.s3.connection import S3Connection
from boto.s3.key import Key
from boto.s3.connection import Location
import base64

"""
    This API requirements
     - Python 2.7
     - boto (pip install boto)
     - MongoDB (pip install pymongo)
"""

def sendInfosS3(wFile):
    """
        Process the insertion of file in AWS S3
        @param wFile The image or audio of the victim
    """
    AWS_ACCESS_KEY_ID = 'AKIAJWP3VNEE5THCM3AA'
    AWS_SECRET_ACCESS_KEY = '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'
    BUCKET = 'sigtrac'
    conn = S3Connection(AWS_ACCESS_KEY_ID, AWS_SECRET_ACCESS_KEY)
    b = conn.get_bucket(BUCKET)
    source_path = wFile
    source_size = os.stat(source_path).st_size
    mp = b.initiate_multipart_upload(os.path.basename(source_path))
    chunk_size = 52428800
    chunk_count = int(math.ceil(source_size / float(chunk_size)))
    for i in range(chunk_count):
        offset = chunk_size * i
        bytes = min(chunk_size, source_size - offset)
        with FileChunkIO(source_path, 'r', offset=offset,bytes=bytes) as fp:
            mp.upload_part_from_file(fp, part_num=i + 1)
    mp.complete_upload()
    b = conn.get_bucket(BUCKET)
    k = Key(b)
    k.key = 'app'
    contents = k.get_contents_as_string()
    print '------------'
    print contents

    
def encodeBase64(wType,wData):
    #print 'encodeBase64'
    #print wData
    date = str(datetime.datetime.now()).replace(" ","-").replace(":","-").replace(".","-")
    if wType == 'image':
        name_file = "image_victim-"+date+".png"
    else:
        name_file = "audio_victim-"+date+".mp3"

    fh = open(name_file, "wb")
    fh.write(str(wData).decode('base64'))
    fh.close()

    return name_file
        
    
def infosSocorrista(wInfos):
    """
        Prepare the JSON for the insertion of data in MongoDB
        @param wInfos The victim Info
    """
    infos = wInfos.split("&")
    lat = infos[1].split("=")[1]
    lon = infos[2].split("=")[1]
    code = infos[3].split("=")[1]
    
    infos = {"codigo_socorrista": code,
             "lat": lat,
             "lon": lon,
             "data_last_position": datetime.datetime.now(),
             }
    print '---------------------'
    print 'Informações do Socorrista'
    print '-------------------------'
    print infos

    
    insert_position(infos)


def infosVictim(wInfos):
    """
        Prepare the JSON for the insertion of data in MongoDB
        @param wInfos The victim Info
    """
    infos = wInfos.split("&")

    #audio = encodeBase64('audio',infos[7].split("=")[1])
    #print 'audio'
    #print audio
    #audio = "http://s3.amazonaws.com/sigtrac/audio"
    #audio_s3 = sendInfosS3(audio)
    image = infos[6].split("=")[1]
    foto  = encodeBase64('image',image)
    #print 'foto'
    #print foto
    foto_s3 = sendInfosS3(foto)
    
    infos_victim = {"codigo_vitima": infos[1].split("=")[1],
                    "nome_vitma": infos[2].split("=")[1],
                    "numero_documento": infos[3].split("=")[1],
                    "lat": infos[4].split("=")[1],
                    "lon": infos[5].split("=")[1],
                    "foto": 'http://s3.amazonaws.com/sigtrac/'+foto,
                    "audio": "",
                    "data_hora": datetime.datetime.now(),
                    "socorrista": infos[8].split("=")[1],
                    "unidade_pa": infos[9].split("=")[1],
                    "detalhes_atendimento": infos[10].split("=")[1]
                    }
    print '---------------------'
    print 'Informações da Vitima'
    print '-------------------------'

    insert_victim(infos_victim)


def conectar():
    """
        Connection on mongodb
    """
    client = MongoClient('localhost', 27017)
    db = client.health_care
    collection = db.health_care_collection
    return db


def insert_victim(wDic):
    """
        Inserting the victim's information into the database
        @param wDic The victim Info
    """
    db = conectar()
    victim = db.victim
    victim_id = victim.insert(wDic)
    print 'victim_id'
    print victim_id
    return victim_id

def insert_position(wDic):
    """
        Insertion of the position
        @param wDic The position Info
    """
    db = conectar()
    position = db.position
    position_id = position.insert(wDic)
    print '---------------------'
    print 'Posição do Socorrista'
    print '---------------------'
    print 'position_id: '+str(position_id)
    return position_id

def processData(wData):
    """
        Information processing for insertion
        @param wDic The Application Info
    """
    data = wData.split("&")
    lat_lon = data[0].split("=")
    if lat_lon[1] == "true":
        infosSocorrista(wData)
    else:
        infosVictim(wData)
        

class webservice(BaseHTTPRequestHandler):
    def _set_headers(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()

    def do_GET(self):
        self._set_headers()
        self.wfile.write("GET")

    def do_HEAD(self):
        self._set_headers()
        
    """def do_POST(self):
        # Doesn't do anything with posted data
        self._set_headers()
        self.wfile.write("POST")"""

    def do_POST(self):
        # Doesn't do anything with posted data
        content_length = int(self.headers['Content-Length']) # <--- Gets the size of data
        post_data = self.rfile.read(content_length) # <--- Gets the data itself
        self._set_headers()
        self.wfile.write("<html><body><h1>POST-SAMARA!</h1></body></html>")
        #print post_data
        processData(post_data)
        
def run(server_class=HTTPServer, handler_class=webservice, port=8080):
    server_address = ('', port)
    httpd = server_class(server_address, handler_class)
    print 'Starting HTTP...'
    httpd.serve_forever()

if __name__ == "__main__":
    from sys import argv

    if len(argv) == 2:
        run(port=int(argv[1]))
    else:
        run()
