Dim requests


requests = CreateObject("/usr/local/lib/libwscriptrequests.so")
requests.Open("GET", "http://example.org", 1)
requests.Send()

print(requests.responsetext)
