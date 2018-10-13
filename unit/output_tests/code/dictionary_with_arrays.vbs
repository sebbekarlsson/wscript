Dim myobj, person


person = CreateObject("Scripting.Dictionary")
person.Add("firstname", "john")
person.Add("lastname", "doe")
person.Add("favouritenumbers", Array(16, 8, 21, 28, 42))

myobj = CreateObject("Scripting.Dictionary")
myobj.Add("person", person)


Dim favnumbers, i, sep, arrsize
favnumbers = ""
sep = ","
i = 0
arrsize = UBound(person.favouritenumbers)
Do While i < arrsize
    If i >= (arrsize-1) Then
        sep = ""
    End If
    favnumbers = favnumbers + person.favouritenumbers(i) + sep
    i = i + 1
Loop


print(favnumbers)
