Dim mydict


mydict = CreateObject("Scripting.Dictionary")
mydict.Add("x", 123)

print(mydict.Exists("x"))
print(mydict.Exists("y"))
print(mydict.Exists("mydict"))
