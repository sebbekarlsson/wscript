Dim request, x


request = CreateObject("/usr/local/lib/libwscriptrequests.so")
print(request)
request.Open("GET", "http://example.org" ,1)
request.Send()

print(request.responsetext)
