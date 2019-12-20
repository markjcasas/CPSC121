# Organization Positions
Create a program that stores and manages information about the positions in an organization.

## Person
First, create a `Person` class that has name, address, and phone number data members.

Create a nondefault constructor that accepts the values that will be assigned to name (`std::string`), address (`std::string`), and phone number (`std::string`) as parameters to the corresponding data members.

Create a default constructor that sets name to `"Unidentified"`, address to `"Somewhere"`, and phone number to `1-800-000-0000`.

Provide accessors and mutators for all of the class' data members.

Create a `display` member function that displays information about the `Person` on the console. Take note that it does not take any parameters and does not return any value. For example, the default constructor might show the following information on screen:

```
Unidentified
Somewhere
1-800-000-0000
```

## Organization
Create an `Organization` class that has a name, president, vice president and treasurer as data members. The positions president, vice president, and treasurer are all `Person` objects.

Create a non-default constructor that accepts a value that will be assigned to the name (`std::string`) of the organization.

Create a default constructor that sets name to `"Unknown"`.

Create accessors and mutators for all data members (i.e., name, president, vice president and treasurer).

### get_position
In the `Organization` class, create a `get_position` member function that accepts a name (`std::string`) parameter. The member function will check whether the name provided is the name of the president, vice president or treasurer and return an `std::string` describing the position. That means, it will return `"president"`, `"vice president"` or `"treasurer"`. However, if the name is not any of the three positions, it should return `"not an officer"`.

## Other instructions
Complete the `main` function as described in the comments inside the file.

Place your classes in `organization.hpp`. Member functions that take more than five lines or use complex constructs should have their function prototype in `organization.hpp` and implementation in `organization.cpp`.

# Code evaluation
Open the terminal and navigate to the folder that contains this problem. Assuming you have pulled the code inside of `/home/student/final` and you are currently in `/home/student` you can issue the following commands

```
cd final
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 2, for example, you need to issue the following command.

```
cd prob02
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob02`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob03` for example.

```
cd ..
cd prob03
```

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in`main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp organization.cpp -o main

./main
```

# Submission
1. When everything runs correctly, let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add.

    ```
    git add main.cpp organization.hpp organization.cpp
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

1. When you finish the exam, go back to Titanium and click on the `Add submission` button in the lab exercise page. Provide a short message in the text area such as "finished lab exercise" and click on `Save changes`. Finally click on `Submit assignment` to inform your instructor that you are done.
