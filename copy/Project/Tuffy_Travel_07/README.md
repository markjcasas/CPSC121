# TuffyTravel Milestone 7

This is milestone 7 of the [TuffyTravel Project](https://docs.google.com/document/d/1v1ZAH-vt8ih500WFyDb_j5PO2L3_XS4_3CswPRJ5qNE/edit?usp=sharing).

# Requirements
In this milestone, we will implement polymorphism to allow your program to add, display, save, load, and find `Route` objects or any of its derived classes. Specifically, we will create a `CheckedRoute` class that inherits from `Route`.

## Route

We will make some modifications on the `Route` class. First, we will make the `display` member function `virtual` so it can be overridden by its derived classes. We will add a new `virtual` member function called `save_string`. It will be used for file saving, wherein it returns an `std::string` to contain the text `"[Route]"` on the first line followed by the name of the route, its departure time and arrival time. This is an example of how an `std::string` returned by the member function might look like: `"[Route]\n57x Brea Mall Xpress\n1623\n1637\n"`

## CheckedRoute

Create a new class called `CheckedRoute` that inherits from `Route`. In addition to information stored by the `Route` class, it also keeps track of the time the route takes off. This is going to be represented by a data member called `take_off_time_`. In airlines for example, passengers would need to arrive at least an hour before a domestic flight and three hours before an international flight. A possible `CheckedRoute` object might be a Delta flight from LAX - ATL whose departure time is 5:35am, take off time is 6:35am, and arrival time is 11:01am. This means passengers are required to arrive 1 hour before the flight taking off at 6:35am.

Create accessors and mutators for the `take_off_time_` data member of `CheckedRoute`.

Create a nondefault constructor that has the same parameters as the `Route` class constructor, but it provides an additional parameter for the take off time.

Create a default constructor that sets its name to `"Home"`, departure time to `2000`, take off time to `2010` and arrival time to `2200`.

Create a `display` member function that will override `Route`s implementation. It works the same way except that it also displays the `take_off_time_` on the screen. For example, calling display on a `CheckedRoute` object might show:

```
Checked Route: Delta LAX-ATL
Departure time: 535
Take off time: 635
Arrival time: 1101
```

Create a `save_string` member function that will override `Route`s implementation. It works the same way except that it uses a different name on the first line and provides the `take_off_time_`. For example, calling `save_string` on the same `CheckedRoute` object above would return: `"[CheckedRoute]\nDelta LAX-ATL\n535\n635\n1101\n"`

## Creating pointers to Route and CheckedRoute objects

### create_route
Modify your `create_route` global function so that it returns the address of a dynamically allocated `Route` object. Unlike the previous milestones that returns the object itself, this function creates the `Route` object in the heap and returns its address.

### create_checked_route
Create a `create_checked_route` global function that asks the user to provide all necessary values to create a `CheckedRoute` object. It asks for the name, departure time, take off time, and arrival time. Here is an example of how it might ask input from the user.

<pre>
Please enter the name of the checked route: <b>Delta LAX - additional</b>
Please enter the departure time of the checked route: <b>535</b>
Please enter the take off time of the checked route: <b>635</b>
Please enter the arrival time of the checked route: <b>1101</b>
</pre>

The function should also return a pointer to a dynamically allocated `CheckedRoute` object using the values provided by the user.

## RouteManager
Apply inheritance and polymorphism so that `Route` and `CheckedRoute` objects can be stored in the same array inside the `RouteManager`. This means that you will need to change your `Route` array inside the `RouteManager` into an array of *`Route` pointers*. You also need to modify your `add` member function so that it receives a pointer to a `Route` object. This will allow your program to get the address of a `Route` object or any of its derived classes and store it in the array inside `RouteManager`.

### destructor
Create a destructor for `RouteManager` that deletes every element that was added to the `Route` pointer array.

### save_routes
Modify your `save_routes` function so that it now uses the `save_string` member function of each element in the `Route` pointer array to get the string it will write into the file. Your code from Milestone 6 probably gets each `Route` object's name, departure time and arrival time using accessors. This will now be much shorter as we just call the `save_string` member function. Calling the `save_string` member function also results in providing additional information about what kind of object is stored. Here is an example of the file that might be produced when you call the `save_routes` member function:

```
3
[Route]
57x Brea Mall Xpress
1623
1637
[CheckedRoute]
Delta LAX-ATL
535
635
1101
[Route]
153 Brea Mall
1642
1703
```
### load_routes
Your `load_routes` function will also change so that it creates the appropriate objects before adding them to the `Route` pointer array. Take note that for each object's data stored in the file, the first line now contains either `"[Route]"` or `"[CheckedRoute]"`. You will use this to identify the type of object you will dynamically create in the heap whose address will be stored to your `Route` pointer array.

### display_routes and find_routes
The other functionalities in `RouteManager` such as displaying, and finding routes should still work as expected. However, you will need to modify them to work with your `Route` pointer array.

## Menu
Update the menu to so it provides the option to create a *checked route* when the user presses **C**. This option should call the `create_checked_route` function and use the `RouteManager` object's `add` member function to add it into its `Route` pointer array.

Update your member function calls in the menu to make sure they work with the redesigned `RouteManager`.

## Other instructions
As usual, the code should be organized so that class and function prototypes are placed in a header file (`route.hpp`) while their implementations are placed in a source file (`route.cpp`).

Any member functions that contain over five lines of code or use any complex constructs should have their function prototypes in `route.hpp` and their corresponding implementation in `route.cpp`. Finally, the *main* method should be in the driver file (`tuffytravel.cpp`).

Please see the sample output below to guide the design of your program.

# Sample output
<pre>
Welcome to TuffyTravel!

What do you want to do?
R - Create routes
C - Create checked routes
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
C - Create checked routes
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
C - Create checked routes
D - Display routes
F - Find route
S - Save routes
L - Load routes
X - Exit
Action: <b>C</b>

Please enter the name of the checked route: <b>Delta LAX-ATL</b>
Please enter the departure time of the checked route: <b>1648</b>
Please enter the take off time of the checked route: <b>1748</b>
Please enter the arrival time of the checked route: <b>2213</b>

What do you want to do?
R - Create routes
C - Create checked routes
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

Checked Route: Delta LAX-ATL
Departure time: 1648
Take off time: 1748
Arrival time: 2213

What do you want to do?
R - Create routes
C - Create checked routes
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
C - Create checked routes
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
C - Create checked routes
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
C - Create checked routes
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
C - Create checked routes
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
C - Create checked routes
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
