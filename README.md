# CustomLVL

This project makes it easy to munge custom lvl files with any name. It does not require a full SWBF2 mod project and makes projects smaller.
Gametoast thread: http://gametoast.com/viewtopic.php?f=64&t=30995

![alt text](https://github.com/[username]/[reponame]/blob/[branch]/image.jpg?raw=true)

### How to install
- copy data_XXX to your BF2_modtools directory
- change XXX to your desired project ID

### How to use
- put any req file you want to munge in your data_XXX\CustomLVL folder. You can take the files from the Example folder to test it.
- run data_XXX\_build\CustomLVL.exe
- choose the req files you want to munge from the list. Multiple selection is possible.
- press munge.

### Features
- you needn't restart CustomLVL every time you add new req files in your folder. Just klick refresh to update the list. (if you forgot the munge.bat you can use this button, too)
- i don't think there is much to say about the select all/unselect all button.
- you can automatically copy the files to their destination. Create a name.req.customlvl file and write the path in that file. You can use multiple paths. %username% will be replaced with the Windows username.
- clean all will delete the folders data_XXX\_BUILD\CustomLVL\MUNGE, data_XXX\_LVL_PLATTFORM (in general PC)\CustomLVL and all files from the .req.customlvl files that are checked(!) in the list.

### Supported Files
The data_XXX\_build\CustomLVL\munge.bat file can handle the following files. To support more types, just edit the munge bat to your wishes.
- data_XXX\CustomLVL\movies\*.mcfg
- data_XXX\CustomLVL\localize\*.cfg
- data_XXX\CustomLVL\effects\*.fx
- data_XXX\CustomLVL\scripts\*.lua
- data_XXX\CustomLVL\*\*.tga
- data_XXX\CustomLVL\*\*.msh
- data_XXX\CustomLVL\fonts\*.fff
- data_XXX\CustomLVL\req\*.req


### Credits
Anakin
