Function Fibonacci(n) 
    If n < 0 Then
        Fibonacci = 0
    ' First Fibonacci number is 0 
    ElseIf n == 1 Then 
        Fibonacci = 0
    ' Second Fibonacci number is 1 
    ElseIf n == 2 Then
        Fibonacci = 1
    Else
        Fibonacci = (Fibonacci(n-1) + Fibonacci(n-2))
    End If
End Function

' should be 39
print(Fibonacci(9))
