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
