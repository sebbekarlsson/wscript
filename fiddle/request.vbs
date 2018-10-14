Dim request


request = CreateObject("../wscript-requests/libwscriptrequests.so")
request.Open("GET", "https://www.example.org", 1)
request.Send()

print(request.responseText)
