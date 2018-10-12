from __init__ import binexec


def test_print_vbs():
    assert binexec('print.vbs') == 'hello'


def test_wscript_echo_vbs():
    assert binexec('WScript.Echo.vbs') == 'hello'


def test_dim_one_vbs():
    assert binexec('Dim_one.vbs') == '32'


def test_dim_multiple_vbs():
    assert binexec('Dim_multiple.vbs') == '32\n0\n12\nhello\nworld\n3'


def test_function_vbs():
    assert binexec('Function.vbs') == '16'


def test_loop_vbs():
    assert binexec('Loop.vbs') == '0\n1\n2\n3\n2\n1'


def test_boolean_expr_vbs():
    assert binexec('boolean_expr.vbs') == '0\n1\n1\n0\n1'


def test_if_vbs():
    assert binexec('If.vbs') == '2\n3\n4'


def test_else_vbs():
    assert binexec('Else.vbs') == 'fruit'


def test_concat_vbs():
    assert binexec('concat.vbs') == 'hello world\nhello world12\n57'


def test_dictionary_vbs():
    assert binexec('dictionary.vbs') == '120\nhello'


def test_add_two_floats_vbs():
    assert binexec('add_two_floats.vbs') == '4.4'


def test_recursion_vbs():
    assert binexec('recursion.vbs') == '0\n1\n2\n3\n4\n4'


def test_fibonacci_vbs():
    assert binexec('fibonacci.vbs') == '39'
