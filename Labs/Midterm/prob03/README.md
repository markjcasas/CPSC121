# Student Info
The program in `main.cpp` should read the data inside `students.txt` and display it on screen. However, the programmer who built the code suddenly had to leave and it is up to you to complete their program. Find and fix the errors in `main.cpp`.

Take note of how the data is organized inside `students.txt`. It will always contain a name followed by a CWID. The name can contain an arbitrary number of strings. We will not know before-hand the number of students in the file, so your program should handle files with any number of students.

After making your modifications, the output should match the following format exactly, including spaces and newlines:

```
Name: John Doe
CWID: 8194487

Name: Jane Smith
CWID: 8173258

Name: Edith Summers Lee
CWID: 8165834

```
You only need to modify `main.cpp`.

# Code evaluation
Open the terminal and navigate to the folder that contains this problem. Assuming you have pulled the code inside of `/home/student/midterm` and you are currently in `/home/student` you can issue the following commands

```
cd midterm
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 3, for example, you need to issue the following command.

```
cd prob03
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob03`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob01` for example.

```
cd ..
cd prob01
```

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in`main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp -o main

./main
```

# Submission
1. When everything runs correctly, let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. 

    ```
    git add main.cpp
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

