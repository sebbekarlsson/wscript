Dim x


x = 0

Function Recursion(Arg)
    If x < 3 * 100 Then
        x = x + 1
        print(x)
        Recursion(1, 2)
    End If
End Function

Recursion(1)
