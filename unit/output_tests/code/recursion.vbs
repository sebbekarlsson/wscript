Function recursion(x)
    print(x)
    If x < 4 Then
        recursion = recursion(x + 1)
    Else
        recursion = x
    End If
End Function


print(recursion(0))
