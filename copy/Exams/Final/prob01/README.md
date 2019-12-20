# Course Registration

## Course
Implement the class named `Course` which has the private variables (data members) `int course_num_`, `std::string course_name_`, and `std::string department_`.

Please note that the `course_name_` and `department_` are of arbitrary length and can contain spaces (i.e. Computer Science). Include accessor and mutator functions for each variable (data member).

Create an overload constructor (nondefault constructor) that takes in three parameters to set the values for `course_num_`, `course_name_`, and `department_`. Create a default constructor that assigns `121` to `course_num_`, `"Object oriented programming"` to `course_name_` and `"Computer Science"` to `department_`.

Create a `display` member function that shows on screen information about the course. Below is an example of how it might look like:

```
Course number: 121
Course name: Object oriented programming
Department: Computer Science
```

Place your class in `course.hpp`. No need to create `course.cpp`.

## dynamic memory allocation
In the `main` function, you are asked to dynamically allocate an array of `Course` objects whose size depends on the user's input. It will also ask the user to provide values for each course, that you will use to set the values of the `Courses` inside your array. Finally, it will ask you to display information about each course added by the user to the screen.

More detailed instructions are found inside `main.cpp`.

# Code evaluation
Open the terminal and navigate to the folder that contains this problem. Assuming you have pulled the code inside of `/home/student/final` and you are currently in `/home/student` you can issue the following commands

```
cd final
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 1, for example, you need to issue the following command.

```
cd prob01
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob01`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob02` for example.

```
cd ..
cd prob02
```

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code in `main.cpp` into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp -o main

./main
```

# Submission
1. When everything runs correctly, let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add.

    ```
    git add main.cpp course.hpp
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
