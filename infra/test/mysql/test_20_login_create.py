import pytest
import os

user = "sigtrac"
pwd = "sigTR@C2016-"
host = "ec2-52-67-109-56.sa-east-1.compute.amazonaws.com"
 
def test_mysql_login(Command):
	assert Command("/usr/bin/mysql -u%s -p%s -h%s -e \"SHOW DATABASES;\" ",user,pwd,host).rc == 0

def test_mysql_create_databases(Command):
	assert Command("/usr/bin/mysql -u%s -p%s -h%s -e \"CREATE DATABASE test_database;\" ",user,pwd,host).rc == 0

def test_mysql_create_table(Command):
        assert Command("/usr/bin/mysql -u%s -p%s -h%s \"test_database\" -e \"CREATE TABLE test (id INT, value VARCHAR(20));\" ",user,pwd,host).rc == 0
