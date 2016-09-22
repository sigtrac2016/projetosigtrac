import pytest
import os

user = "sigtrac"
pwd  = "sigTR@C2016-"
host = "ec2-52-67-109-56.sa-east-1.compute.amazonaws.com"
 
def test_mysql_select(Command):
	assert Command("/usr/bin/mysql -u%s -p%s -h%s \"test_database\" -e \"select * from test\" ",user,pwd,host).rc == 0

def test_mysql_drop_table(Command):
	assert Command("/usr/bin/mysql -u%s -p%s -h%s \"test_database\"  -e \"drop table test;\" ",user,pwd,host).rc == 0

def test_mysql_drop_database(Command):
	assert Command("/usr/bin/mysql -u%s -p%s -h%s -e \"drop database test_database;\" ",user,pwd,host).rc == 0

