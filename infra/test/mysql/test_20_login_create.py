import pytest
import os

user = "sigtrack"
pwd = "sigTR@CK2016-"

 
def test_mysql_login(Command):
	assert Command("/usr/bin/mysql -u%s -p%s -e \"SHOW DATABASES;\" ",user,pwd).rc == 0

def test_mysql_create_databases(Command):
	assert Command("/usr/bin/mysql -u%s -p%s -e \"CREATE DATABASE test_database;\" ",user,pwd).rc == 0

def test_mysql_create_table(Command):
        assert Command("/usr/bin/mysql -u%s -p%s \"test_database\" -e \"CREATE TABLE test (id INT, value VARCHAR(20));\" ",user,pwd).rc == 0
