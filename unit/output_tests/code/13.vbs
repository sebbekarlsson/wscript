Dim x, y, z, a, b, c

x = 0
y = 1
z = 2
a = 3
b = 4
c = 5

If x == -1 Then
    print("yo")
ElseIf x == 0 Then
    print("hello")
Else
    print("nono")
End If

If y == 1 Then
    print("world")
Else
    print("haha")
End If

If z > 100 Then
    print("pancakes")
ElseIf z > 10 Then
    print("cookies")
ElseIf z > 5 Then
    print("fruits")
Else
    If z <> 2 Then
        print("bananas")
    Else
        print("strawberries")
    End If
End If
