# 21sh

On to more serious things! With 21sh, you will write an implementation close to the loop “read, eval, print” of a shell. With the help of the Termcaps library, you will add a functional command line useful for the “read” part of your shell. Cursor movement, editing, history, multi-lines, etc. 21sh will be your first real interpreter. As such, this project will let you discover lexical, syntax and semantic analysis common to interpreters and compilers. With adapted data structure and processing, adding pipe (“|”) and redirect (“<”, “<<, “>>”, “>”) support will be easy!


Objectives
- Advanced line reading and edition with Termcaps
- Lexical analysis (“Lexing”)
- Syntax analysis (“Parsing”)
- Semantic analysis
- Abstract Syntax Tree generation (“AST”)
- Abstract Syntax Tree evaluation

Skills
- Imperative programming
- Rigor
- Unix

### Introduction
*"A shell program is an application that allows interacting with the computer. In a shell the user
can run programs and also redirect the input to come from a file and output to come from a
file. Shells also provide programming constructions such as if, for, while, functions, variables
etc. Additionally, shell programs offer features such as line editing, history, file completion,
wildcards, environment variable expansion, and programing constructions."*  
<sup>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\- Introduction to Systems Programming: a Hands-on Approach by Gustavo A. Junipero Rodriguez-Rivera and Justin Ennen</sup>

### Compilation
Clone repository into your current working directory and compile the program with the following commands:
```
$> git clone https://github.com/esalorin/21sh.git 21sh
$> cd 21sh  
$> make  
```
Now you should have binary file inside the repository which you can run with the following command:
```
$> ./21sh  
```

### Keybindings
| KEY  | FUNCTION |
| ------------- | ------------- |
| <kbd>right</kbd> | Move cursor right. |
| <kbd>left</kbd> | Move cursor left. |
| <kbd>ctrl+right</kbd> | Move cursor to the beginning of a word. |
| <kbd>ctrl+left</kbd> | Move cursor to the ending of a word. |
| <kbd>ctrl+up</kbd> | Move cursor to the upper line. |
| <kbd>ctrl+down</kbd> | Move cursor to the lower line. |
| <kbd>up</kbd> | Navigate to older command in history. |
| <kbd>down</kbd> | Navigate to newer command in history. |
| <kbd>home</kbd> | Move cursor to the beginning of current command. |
| <kbd>end</kbd> | Move cursor to the ending of current command. |
| <kbd>ctrl+k</kbd> | Cut the part of the current command *after* the cursor, and add it to the internal clipboard buffer. |
| <kbd>ctrl+u</kbd> | Cut the part of the current command *before* the cursor, and add it to the internal clipboard buffer. |
| <kbd>ctrl+p</kbd> | Paste contents of the internal clipboad to the current command. |
