Dim x


Function DemoFunc(Arg1, Arg2)
    ' Return the two arguments in a single string
    DemoFunc = "First: " + Arg1 + " second: " + Arg2
End Function

'Now call the function above
'myDemo = DemoFunc("Hello","World")
'wscript.echo myDemo

x = DemoFunc("hello", "wolrd")

print(x)
