//
//  R_SHRED.cpp
//  R_SHRED
//
//  Created by RocKK on 08/02/15.
//  Copyright (c) 2015 RocKK.
//  All rights reserved.
//
//  Redistribution and use in source and binary forms are permitted
//  provided that the above copyright notice and this paragraph are
//  duplicated in all such forms and that any documentation,
//  advertising materials, and other materials related to such
//  distribution and use acknowledge that the software was developed
//  by the RocKK.  The name of the
//  RocKK may not be used to endorse or promote products derived
//  from this software without specific prior written permission.
//  THIS SOFTWARE IS PROVIDED ''AS IS'' AND WITHOUT ANY EXPRESS OR
//  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
//  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;
 
void getInfoAboutFolder(char **inputFolder){
    struct stat fileStat;
    stat(inputFolder[1],&fileStat);
 
    printf("\nInformation for %s\n",inputFolder[1]);
    printf("---------------------------\n");
    printf("Size: \t\t%d bytes\n",fileStat.st_size);
    printf("Number of Links: \t%d\n",fileStat.st_nlink);
    printf("Inode: \t\t%d\n",fileStat.st_ino);
 
    printf("Permissions: \t");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");
 
    printf("It %s a symbolic link\n\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
}

int checkIfDirIsEmpty(string dir){
	int check;
	char is_empty[100];
	FILE * output;

	string popenCommand = "cd " + dir + "; ls | wc -l";
	output = popen(popenCommand.c_str(),"r"); 
	fgets (is_empty, 100, output); //write to the char
	pclose (output);

	check = atoi(is_empty);
	return check;
}

void startWipeProtocol(string dir){
	cout << "Wipe Protocol Initiated" << endl;
	if (checkIfDirIsEmpty(dir) != 0){
		string shred = "find " + dir + " -type f -print0 | xargs -0 shred -zuvn 1";
		std::system(shred.c_str()); //securely wipe files recursively
    	cout << "Shredding Files Sucessfuly Performed" << endl;
    	string deleteDirectories = "find " +  dir + "/* -empty -type d -delete 2>/dev/null";
    	std::system(deleteDirectories.c_str()); //delete empty directories
    	cout << "Empty Directories Deleted" << endl;
    	cout << "All Data Securely Wiped" << endl;
    }
    else
    	cout << "Directory is already empty" << endl;
} 

 
int main(int argc, char *argv[])
{ 
	getInfoAboutFolder(argv);
	startWipeProtocol(argv[1]);
    return 0;
}

//  11000010 00100000 01010010 01101111 01100011 01001011 01001011