import pytest
import os

user = "sigtrack"
pwd = "sigTR@CK2016-"

 
def test_mysql_insert(Command):
	assert Command("/usr/bin/mysql -u%s -p%s \"test_database\" -e \"insert test values(1,\"Value\");\" ",user,pwd).rc == 0

def test_mysql_update(Command):
	assert Command("/usr/bin/mysql -u%s -p%s \"test_database\"  -e \"update test set id=2;\" ",user,pwd).rc == 0

def test_mysql_delete(Command):
        assert Command("/usr/bin/mysql -u%s -p%s \"test_database\" -e \"delete from test;\" ",user,pwd).rc == 0
