The Unix systems don't provide an unique error handling: 
- of the system calls about 60% return -1 on an error;
- about 20% returning NULL, zero, SIG_ERR or somethiong else;
- about 20% don't report errors at all.
