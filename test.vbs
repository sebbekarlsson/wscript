Dim b

b = 0


Function foo(x, y)
    Dim b
    b = 0
    Function multiply()
        multiply = x * y
    End Function

    print("loop")
    Do While b < 10
        foo = multiply(x, y)
        b = b + 1
    Loop
    print("loop done")
End Function


print(foo(10, 5))
