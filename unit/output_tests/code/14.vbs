Function foo(x, y)
    Function mu(x, y)
        mu = x * y
    End Function
    foo = mu(x + 8, y + 8)
End Function

print(foo(10, 10))
