# FileOrganizer

This program is to clean up a Folder/Directory.

I built this application as I was tired of looking through a cluttered directories, spending lots of time looking for files. Let's face it, who normally cleans and organizes their folders :P.  

This application is an upgrade from my previous version of the "file-sorter" written in Python. I decided to move away from Python and write this iteration in C++ because I wanted to relearn C++ and thought this would be a good starting point.  

## What this app does
It will no longer dynamically get the username of the current logged in user and clean their downloads folder. Instead it will now clean whatever folder the program is executed from. The name of the executable is skipped in the process of moving files so that it is easy to locate should the user want to organize another directory.  

Several new folders will be created in this process:  
- Images
- Video
- Documents
- Archieve

(The number of folders above has been reduced for better organizational management)

These folders will be created based on the extensions of the files in the current directory being organized, so not all of the above folders will be created all the time. The files will then be moved into their respective folders.
