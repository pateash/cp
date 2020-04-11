# using ios::sync_with_stdio and cin.tie(0) or cin.tie(NULL)

sources
 * https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
 * https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
``` c++
ios_base::sync_with_stdio(false);
```
This disables the synchronization between the C and C++ standard streams. By default, all standard streams are synchronized, which in practice allows you to mix C- and C++-style I/O and get sensible and expected results. If you disable the synchronization, then C++ streams are allowed to have their own independent buffers, which makes mixing C- and C++-style I/O an adventure.

* Note - do not use this is you wish to use both C and C++ IO streams.

```c++
cin.tie(NULL);
```

This unties cin from cout. Tied streams ensure that one stream is flushed automatically before each I/O operation on the other stream.
eg. if we have command line application then we should allow user to enter answer (STDIN) only after question has been on console (STDOUT).

# Getting Input for full line

## using cin
```c++
    string s1;
    cin>> s1; // this will only get input up to space ( not full line ) that's why flush is not required
```

## using getline
```c++
    cin.ignore(); // if we have done some simple input before we have to do this before
    string s2;
    getline(cin,s2); 
```
