Dim x


x = 0

Function Recursion()
    If x < 3 * 100 Then
        x = x + 1
        print(x)
        Recursion()
    End If
End Function

Recursion()
