Function Fibonacci(n) 
    If n <= 1 Then
        Fibonacci = n
    Else
        Fibonacci = (Fibonacci(n-1) + Fibonacci(n-2))
    End If
End Function

' should be 34
print(Fibonacci(9))
