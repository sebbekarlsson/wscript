from __init__ import binexec


def test_0():
    assert binexec('0.vbs') == '1'


def test_1():
    assert binexec('1.vbs') == '100'


def test_2():
    assert binexec('2.vbs') is None


def test_3():
    assert binexec('3.vbs') == '2.56'


def test_4():
    assert binexec('4.vbs') == '40'


def test_5():
    assert binexec('5.vbs') == '10'


def test_6():
    assert binexec('6.vbs') == 'hello world'


def test_7():
    assert binexec('7.vbs') == 'hello 12'


def test_8():
    assert binexec('8.vbs') == '45.7'


def test_9():
    assert binexec('9.vbs') == 'hello 0.450000'


def test_10():
    assert binexec('10.vbs') == '1\n2\n3'


def test_11():
    assert binexec('11.vbs') == '1\n2\n3\n2\n1\n0'


def test_12():
    assert binexec('12.vbs') == '40'

def test_13():
    assert binexec('13.vbs') == 'hello\nworld\nstrawberries'
