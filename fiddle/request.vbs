Dim request


request = CreateObject("../libwscriptrequests/libwscriptrequests.so")
request.Open("GET", "https://www.example.org", 1)
request.Send()

print(request.responseText)
