Function Main()
    Dim x
    x = 0
    Function Recursion(x)
        If x < 3 Then
            x = x + 1
            print(x)
            Recursion(x)
        End If
    End Function
    Recursion(x)
End Function


Main(x)
