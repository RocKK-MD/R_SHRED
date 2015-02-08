R_SHRED
=================

R_SHRED is a small c++ project for secure deleting also known as wiping or shredding files/directories/drives.
This is an example how shred may be implemented in a project *nix based or Mac OS X Operating Systems.

SHRED is a Unix command that can be used to securely delete files and devices so that they cannot be recovered aftewards. It is a part of GNU Core Utilities. For efficiency, erasing a file usually only erases the file system entry and keeps the content of the file intact. This frequently allows the file to be recovered using commonly available software. Even if the file is overwritten, residual magnetic fields may allow data recovery using specialist hardware equipment. To prevent this, shred overwrites the file multiple times using patterns chosen to maximize destruction of the residual data.

SHRED can be invoked either on ordinary files or on devices (such as hard disk partitions), which are represented as files in Unix. By default, the command overwrites the file three times with multiple patterns, but the number is user configurable. It has an option to do an additional final overwrite with zeroes, which may help to hide the fact that it was used.

By default, shred also shreds file slack (unused space in file allocations). For example, a 5 KB file on a file system with 4 KB clusters actually requires 8 KB of storage. Shred has an option to overwrite only the file itself, as well as an option to delete the file after it has completed operation.

Usage
-------------
```BASH
rockk@RocKK:~$ g++ R_SHRED.cpp 
rockk@RocKK:~$ ./a.out ~/Work

Information for /home/rockk/Work
---------------------------
Size: 		4096 bytes
Number of Links: 	2
Inode: 		6035784
Permissions: 	drwxr-xr-x

It is not a symbolic link

Wipe Protocol Initiated
shred: /home/rockk/Work/file.cpp: pass 1/2 (random)...
shred: /home/rockk/Work/file.cpp: pass 2/2 (000000)...
shred: /home/rockk/Work/file.cpp: removing
shred: /home/rockk/Work/file.cpp: renamed to /home/rockk/Work/00000000
shred: /home/rockk/Work/00000000: renamed to /home/rockk/Work/0000000
shred: /home/rockk/Work/0000000: renamed to /home/rockk/Work/000000
shred: /home/rockk/Work/000000: renamed to /home/rockk/Work/00000
shred: /home/rockk/Work/00000: renamed to /home/rockk/Work/0000
shred: /home/rockk/Work/0000: renamed to /home/rockk/Work/000
shred: /home/rockk/Work/000: renamed to /home/rockk/Work/00
shred: /home/rockk/Work/00: renamed to /home/rockk/Work/0
shred: /home/rockk/Work/file.cpp: removed
Shredding Files Sucessfuly Performed
Empty Directories Deleted
All Data Securely Wiped
rockk@RocKK:~$
```

License
--------

This code is under the BSD license.