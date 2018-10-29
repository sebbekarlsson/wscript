Dim mydict

mydict = CreateObject("Scripting.Dictionary")
mydict.Add("x", 1)
mydict.Add("name", "John")

print(mydict.Exists("x"))
print(mydict.Exists("name"))

mydict.RemoveAll()

print(mydict.Exists("x"))
print(mydict.Exists("name"))
