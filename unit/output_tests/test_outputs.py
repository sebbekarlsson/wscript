from __init__ import binexec


def test_0():
    assert binexec('0.vbs') == '1'


def test_1():
    assert binexec('1.vbs') == '100'
