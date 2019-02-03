# competetive coding notes

## memset
memset(pointer,value,size) do not work always for setting values,

- for integer arrays it can only set **values= 0 or -1** , so 1 will not work
- for float arrays it could set only **value=0.0**
- for strings or char[], it can set anything character.

**this is because memset is designed to initialise strings, can use std::fill(start,end,value) instead in other cases**

