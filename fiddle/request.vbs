Dim request, x


request = CreateObject("../libwscriptrequests/libwscriptrequests.so")
print(request)
request.Open("GET", "http://example.org" ,1)
request.Send()

print(request.responsetext)
