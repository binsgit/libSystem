# libSystem
.NET clone in C++

## Description
This library is intended for improving my development efficiency, since dealing with libc and kernel internals every day is a boring&tough work.  
When I was teaching my sister C#, I surprisingly found that .NET APIs are so concise, elegant and in apple-pie order when comparing with C++ and C standard library functions. So I decided to implement them in C++. This way I can use these APIs without using the slower .NET runtime.  
This is not a "yet another .NET runtime". This is a pure C++ library with .NET API names and does (nearly) the same things as .NET APIs does.  

## APIs that are not in the original .NET framework
But I'm sure most people will find them useful ;-)  
epoll-related functions are not available under non-Linux environments.  

`System.Exception.PosixException`  
`System.Net.Sockets.Epoll`  
`System.Net.Sockets.EpollEvent`  
`System.Convert.ToHexString`  
`System.Convert.FromHexString`  