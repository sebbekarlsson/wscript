Dim x


x = 0

Function DemoFunc(Arg1, Arg2)
    ' Return the two arguments in a single string
    'DemoFunc = "First: " + Arg1 + " second: " + Arg2
    If x < 300 Then
        x = x + 1
        print(x)
        DemoFunc(1, 2)
    End If
End Function

'Now call the function above
'myDemo = DemoFunc("Hello","World")
'wscript.echo myDemo

DemoFunc(1, 2)
'print(x)
