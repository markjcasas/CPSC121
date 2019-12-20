# TuffyTravel Milestone 8
This is milestone 8 of the [TuffyTravel Project](https://docs.google.com/document/d/1v1ZAH-vt8ih500WFyDb_j5PO2L3_XS4_3CswPRJ5qNE/edit?usp=sharing).

# Requirements
In this milestone, we will implement another derived class called `ConnectionRoute` that will work with your `RouteManager`.

## ConnectionRoute

Create a new class called `ConnectionRoute` that inherits from `Route`. In addition to information stored by the `Route` class, it also keeps track of a source and destination route. These are represented by two data members called `source_route_` and `destination_route_` that are both `std::string`. Take for example the case when a passenger needs to walk from a bus stop to the airport. A `ConnectionRoute` might represent this by having the name `Walk to LAX airport`, whose source route is `G Shuttle to LAX Terminals` and destination route is `Delta LAX-ATL`. Its departure time is 1523 and arrival time is 1524.

Create accessors and mutators for `source_route_` and `destination_route_`.

Create a nondefault constructor that has the same parameters as the `Route` class constructor, but it provides two additional parameters for the source and destination routes.

Create a default constructor that sets its name to `"Walk to bus"`, source route to `"Home"`, destination route to `"Bus stop"`, departure time to `800`, and arrival time to `805`.

Create a `display` member function that will override `Route`s implementation. It should display both source and destination routes on the screen. For example, calling `display` on a `ConnectionRoute` object might show:

```
Connection Route: Walk to LAX airport
Source: G Shuttle to LAX Terminals
Destination: Delta LAX-ATL
Departure time: 1523
Arrival time: 1524
```

Create a `save_string` member function that will override `Route`s implementation. It works the same way except that it uses a different name on the first line and provides the `source_route_` and `destination_route_`. For example, calling `save_string` on the same `ConnectionRoute` object above would return: `"[ConnectionRoute]\nWalk to LAX airport\nG Shuttle to LAX Terminals\nDelta LAX-ATL\n1523\n1524\n"`

### create_connection_route
Create a `create_connection_route` global function that asks the user to provide all necessary values to create a `ConnectionRoute` object. It asks for the name, source route, destination route, departure time, and arrival time. Here is an example of how it might ask input from the user.

<pre>
Please enter the name of the connection route: <b>Walk to LAX airport</b>
Please enter the source route: <b>G Shuttle to LAX Terminals</b>
Please enter the destination route: <b>Delta LAX-ATL</b>
Please enter the departure time of the connection route: <b>1523</b>
Please enter the arrival time of the connection route: <b>1524</b>
</pre>

The function should also return a pointer to a dynamically allocated `ConnectionRoute` object using the values provided by the user.

### load_routes
Update your `load_routes` function so that it can read information on `ConnectionRoute`s. It should correctly create the corresponding object pointers that will be added to the `Route` pointer array.

### display_routes and find_routes
The other functionalities in `RouteManager` such as displaying, and finding routes should still work as expected.

## Menu
Update the menu to so it provides the option to create a *connection route* when the user presses **T**. This option should call the `create_connection_route` function and use the `RouteManager` object's `add` member function to add it into its `Route` pointer array.

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
T - Create connection routes
D - Display routes
F - Find route
S - Save routes
L - Load routes
X - Exit
Action: <b>T</b>

Please enter the name of the connection route: <b>Walk to LAX airport</b>
Please enter the source route: <b>G Shuttle to LAX Terminals</b>
Please enter the destination route: <b>Delta LAX - additional</b>
Please enter the departure time of the connection route: <b>1523</b>
Please enter the arrival time of the connection route: <b>1524</b>

What do you want to do?
R - Create routes
C - Create checked routes
T - Create connection routes
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
T - Create connection routes
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
T - Create connection routes
D - Display routes
F - Find route
S - Save routes
L - Load routes
X - Exit
Action: <b>D</b>

Available Routes:

Connection Route: Walk to LAX airport
Source: G Shuttle to LAX Terminals
Destination: Delta LAX-ATL
Departure time: 1523
Arrival time: 1524

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
T - Create connection routes
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
T - Create connection routes
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
T - Create connection routes
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
T - Create connection routes
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
T - Create connection routes
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
T - Create connection routes
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
