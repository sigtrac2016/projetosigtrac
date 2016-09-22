import pytest
import os

user = "sigtrac"
pwd  = "sigTR@C2016-"
host = "ec2-52-67-109-56.sa-east-1.compute.amazonaws.com"

 
def test_mysql_insert(Command):
	assert Command("/usr/bin/mysql -u%s -p%s -h%s \"test_database\" -e \"insert test values(1,\"Value\");\" ",user,pwd,host).rc == 0

def test_mysql_update(Command):
	assert Command("/usr/bin/mysql -u%s -p%s -h%s \"test_database\"  -e \"update test set id=2;\" ",user,pwd,host).rc == 0

def test_mysql_delete(Command):
        assert Command("/usr/bin/mysql -u%s -p%s -h%s \"test_database\" -e \"delete from test;\" ",user,pwd,host).rc == 0
