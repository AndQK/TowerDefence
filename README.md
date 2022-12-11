# TowerDefence

## Running the project
1.	Clone the project onto your computer.
2.	Add folders to the project in directory .vscode:
    a.	C_cpp_properties.json
    b.	Launch.json
    c.	Settings.json
    d.	Tasks.json
    e.	These can be copied from any C++ module we have done in this course.
3.	Use your VS-code terminal and use command: sudo apt-get install libsfml-dev
4.	Press Cntrl+Shift+P and “CMake: Configure” the project.
5.	Press Cntrl+Shift+P and “CMake: Debug” the project. 
    a.	If this does not work, first try using the program by clicking “(gdb) Launch” in the Run and Debug window of VS Code
    b.	“Failed to open X11 display; make sure the DISPLAY environment variable is set correctly. Aborted”
    c.	 If you get this error message try:
        i.	Run PowerShell as administrator, use command: wsl --update
        ii.	Sudo apt-get update
        iii.	Sudo apt-get upgrade
        iv.	You will need to restart WSL for the update to take effect, use command: wsl --shutdown
        v.	Type command: wsl –list –verbose
        vi.	You should see the number 2 for you installed distro under the heading VERSION in the response.
        vii.	If everything is correct until this point use command: sudo apt update
        viii.	Now install gedit: sudo apt install gedit -y
    d.	“SFML Failed to load image, reason: Unable to open file.”
        i.	If you get this error message the problem might be that your computer cant find the images our program uses.
        ii.	You could try to change where the program calls the images and add “../” to the beginning of them. This way the program can find them easier.
