import pytest
import os

user = "sigtrack"
pwd = "sigTR@CK2016-"

 
def test_mysql_select(Command):
	assert Command("/usr/bin/mysql -u%s -p%s \"test_database\" -e \"select * from test\" ",user,pwd).rc == 0

def test_mysql_drop_table(Command):
	assert Command("/usr/bin/mysql -u%s -p%s \"test_database\"  -e \"drop table test;\" ",user,pwd).rc == 0

def test_mysql_drop_database(Command):
	assert Command("/usr/bin/mysql -u%s -p%s -e \"drop database test_database;\" ",user,pwd).rc == 0

