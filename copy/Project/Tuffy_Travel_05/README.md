# TuffyTravel Milestone 5

This is milestone 5 of the [TuffyTravel Project](https://docs.google.com/document/d/1v1ZAH-vt8ih500WFyDb_j5PO2L3_XS4_3CswPRJ5qNE/edit?usp=sharing).

# Requirements
Update your menu to add the save and load functionalities.

First, create a function called `get_filename` that does not accept any parameters. It will ask the user to provide the file name they wish to use for saving the routes. The function will return the filename that the user provided.

Second, create a function called `save_routes` that accepts three parameters. A `Route` array, the number of elements in that array, and the filename it will save to. The function should go through each element of the array and store information about the route into a file. The name of the save file is the filename passed as a parameter to the function.

The file should contain the number of `Routes` on the first line followed by the information from each route. For example, a `Route` array with three elements would save a file like the one below.

```
3
57x Brea Mall Xpress
1623
1637
153 Brea Mall
1642
1703
57x Brea Mall Xpress
1648
1702
```

Third, create a function called `load_routes` that accepts as a parameter the array that will store the information loaded, the number of elements in the array, and the filename. The function will load the file using the filename provided as a parameter. We assume that the format of the file is the same as what we used to save it (see example above).

If you recall, the first line of the file contains the number of `Route` objects stored in the fille. We should update the third parameter (number of elements in the array) so that it is equal to the number of `Route`s in the file. We willl need to make this parameter pass-by-reference to achieve this behavior.

After reading the first line, the function should proceed to load information for each `Route` object and store it in the array, where the first element from the file is stored in index 0, the second in index 1, and so forth.

Take note that if the file does not exist, the function should not change the array or number of elements. It should display an error message telling the user that the file does not exist as shown below.

```
File does not exist.
```

You can assume that if a file exists, the file format is correct and it will overwrite any data in the `Route` array.

Finally, modify your menu to add new options to save and load routes. When the user types in **S** the program should use the `get_filename` function to get the filename, then pass all necessary arguments to the `save_routes` function that will write the data to the file. Specifically, we pass the `Route` array declared in `main`, the number of elements currently contained in the array, and the filename that the user provided.

Similarly, when the user types in **L** the program should use the `get_filename` function to get the filename, then pass all necessary arguments to the `load_routes` function that will load the data. Specifically, we pass the `Route` array declared in `main` so that it will contain all `Routes` from the file, the number of elements in the array so that it changes based on how many `Routes` are present in the file, and the filename that the user provided.

All previous functionalities of the program should still work after adding both features.

The code should be organized so that class and function prototypes are placed in a header file (`route.hpp`) while their implementations are placed in a source file (`route.cpp`).

Any member functions that contain over five lines of code or use any complex constructs should have their function prototypes in `route.hpp` and their corresponding implementation in `route.cpp`. Finally, the *main* method should be in the driver file (`tuffytravel.cpp`).

Please see the sample output below to guide the design of your program.

# Sample output
<pre>
Welcome to TuffyTravel!

What do you want to do?
R - Create routes
D - Display routes
F - Find route
S - Save routes
L - Load routes
X - Exit
Action: <b>R</b>

Please enter the name of the route: <b>57x Brea Mall Xpress</b>
Please enter the departure time of the route: <b>1623</b>
Please enter the arrival time of the route: <b>1637</b>

What do you want to do?
R - Create routes
D - Display routes
F - Find route
S - Save routes
L - Load routes
X - Exit
Action: <b>R</b>

Please enter the name of the route: <b>153 Brea Mall</b>
Please enter the departure time of the route: <b>1642</b>
Please enter the arrival time of the route: <b>1703</b>

What do you want to do?
R - Create routes
D - Display routes
F - Find route
S - Save routes
L - Load routes
X - Exit
Action: <b>R</b>

Please enter the name of the route: <b>57x Brea Mall Xpress</b>
Please enter the departure time of the route: <b>1648</b>
Please enter the arrival time of the route: <b>1702</b>

What do you want to do?
R - Create routes
D - Display routes
F - Find route
S - Save routes
L - Load routes
X - Exit
Action: <b>D</b>

Available Routes:

Route: 57x Brea Mall Xpress
Departure time: 1623
Arrival time: 1637

Route: 153 Brea Mall
Departure time: 1642
Arrival time: 1703

Route: 57x Brea Mall Xpress
Departure time: 1648
Arrival time: 1702

What do you want to do?
R - Create routes
D - Display routes
F - Find route
S - Save routes
L - Load routes
X - Exit
Action: <b>F</b>

Please enter the time you plan to leave: <b>1630</b>
We suggest you take this route:

Route: 153 Brea Mall
Departure time: 1642
Arrival time: 1703

What do you want to do? 
R - Create routes
D - Display routes
F - Find route
S - Save routes
L - Load routes
X - Exit
Action: <b>S</b>

Please enter the filename: <b>routes.txt</b>
File saved!

What do you want to do? 
R - Create routes
D - Display routes
F - Find route
S - Save routes
L - Load routes
X - Exit
Action: <b>L</b>

Please enter the filename: <b>new_r.txt</b>
File does not exist.

What do you want to do? 
R - Create routes
D - Display routes
F - Find route
S - Save routes
L - Load routes
X - Exit
Action: <b>L</b>

Please enter the filename: <b>new_routes.txt</b>
File loaded!

What do you want to do? 
R - Create routes
D - Display routes
F - Find route
S - Save routes
L - Load routes
X - Exit
Action: <b>D</b>

Available Routes:

Route: 30 Cerritos Center
Departure time: 1412
Arrival time: 1507

What do you want to do? 
R - Create routes
D - Display routes
F - Find route
S - Save routes
L - Load routes
X - Exit
Action: <b>X</b>

Thank you for using TuffyTravel!
</pre>

# Submission checklist
1. Created classes.
1. Created function prototypes.
1. Created function implementation.
1. Called functions in the driver accordingly.
1. Followed the [proper file structure for using functions](https://github.com/ILXL-guides/function-file-organization)
1. Compiled and ran the driver (`tuffytravel`).
1. Manually checked for compilation and logical errors.
1. Designed and tested your own test cases.
1. Ensured no errors on the unit test (`make test`).
1. Ensured no errors on the style check (`make stylecheck`).
1. Ensured no errors on the format check (`make formatcheck`).
1. Completed reflection file ([reflection.md](reflection.md))

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/ms01-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd ms01-tuffy
```

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `tuffytravel.cpp` and into the executable file `tuffytravel`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 tuffytravel.cpp route.cpp -o tuffytravel
./tuffytravel
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

# Submission
1. When everything runs correctly,  let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. There are cases when you have multiple changed files, so you can just type . (period) to add all modified files.

    ```
    git add tuffytravel.cpp route.cpp route.hpp
    ```
1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit
    ```
1. In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github username.

    ```
    git config --global user.email "tuffy@csu.fullerton.edu"
    git config --global user.name "Tuffy Titan"
    ```
    When you're done, make sure you type `git commit` again.    
1. Git will ask you to describe what you have added to the staging area. By default, you will use a command-line based editor called *nano*. Go ahead and provide a description then press <kbd>Ctrl</kbd> + <kbd>x</kbd> to exit. Press <kbd>Y</kbd> to confirm that you want to make changes and then press <kbd>Enter</kbd>.
1. Lets push all changes to the Github repository using git's `push` command. Provide your Github username and password when you are asked.

    ```
    git push
    ```
1. When you finish the exercise, go back to Titanium and click on the `Add submission` button in the lab exercise page. Provide a short message in the text area such as "finished lab exercise" and click on `Save changes`. Finally click on `Submit assignment` to inform your instructor that you are done.
