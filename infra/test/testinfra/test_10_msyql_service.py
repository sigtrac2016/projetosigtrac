import pytest
import os

def test_mysql_running_and_enabled(Service):
    mysql = Service("mysql")
    assert mysql.is_running
    assert mysql.is_enabled

def test_mysql_listening(Socket):
    assert Socket("tcp://192.168.99.100:3306").is_listening
