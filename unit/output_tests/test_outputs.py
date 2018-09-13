from __init__ import binexec


def test_0():
    assert binexec('0.vbs') == '1'


def test_1():
    assert binexec('1.vbs') == '100'


def test_2():
    assert binexec('2.vbs') is None


def test_3():
    '''this test should be changed later when we have added floats'''
    assert binexec('3.vbs') == '2'


def test_4():
    assert binexec('4.vbs') == '40'


def test_5():
    assert binexec('5.vbs') == '10'
