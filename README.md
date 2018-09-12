# ![image/vbs.png](image/vbs.png) Visual Basic Script Interpreter
> Run `*.vbs` scripts on your \*NIX machine, in a completely _libre_ way!

> This is a complete rewrite of `wscript.exe`, for \*NIX machines.  
> The goal is to have it behave exactly like the `.exe` version for Windows,  
> but in a libre and platform-independent way.

> The goal is not yet achieved, but feel free to contribute,  
> just make sure that any contribution & modification you do is completely
> libre.

### _Refreshing reminder of what vbs looks like:_
```vbs
Dim x

x = 2

If x > 0 Then
    Wscript.Echo "Hello World"
End If
```

## Usage
> To use this software:

    wscript.out <script>.vbs


## Compile
> To compile this software:

    make

> Then to make it accessible from anywhere, just run this command after
> you have compiled it:

    cp wscript.out /usr/local/bin/.

## Running the unit test
> To run the unit tests, do the following:

    make test
    ./test.out
