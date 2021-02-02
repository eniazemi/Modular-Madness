# Modular Madness

This repositry contains a set of C++ files that implement a solution to
the programming exercise "Modular Madness", part of Ableton Programming Tasks.

## Run

To run the program, we suggest downloading the files and running them in a C++ text editor such as Visual Studio, which was used to create the program itself.

## Instructions
For **inserting modules**, type:
```cpp
module <name> <action>
```
The selected action can be:

***echo*** - the output string is the input string concatenated to itself;

***delay***- the output string is the previous input string. The initial output is “hello”;

***reverse***- the output string is the input string reversed;

***noop***- the input appears unchanged at the output.

For **connecting two modules**, type:
```cpp
connect <module_name1> <module_name2>
```

To **process the string**, type:
```cpp
process <//userinput//>
```

For **quitting**, type: 
```quit```

Type ```clear``` to **clear all the modules and start over!**

The number of output strings is limited to **sixteen times** the number of input strings in the corresponding process line.

P.S. The connect can only be made for **2 modules** at the same time.

Please write in **all lowercase!**

## Usage

Here is an example run test and its output:

```cpp
module alpha reverse
module beta echo
connect alpha beta
process hello

olleholleh
```
## To Do
The program currently works under the assumption that it will only be run with valid inputs. Handling errors which might arise from malformed input is still to be added.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.


