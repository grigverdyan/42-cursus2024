<a name="readme-top"></a>
<div align="center">


  <!-- Project Name -->
  <h1>Get NExtt Line</h1>

  <!-- Short Description -->
  <p align="center">
	  <b>42 Yerevan Get Next Line</b><br>
  </p>

  <h3>
      <a href="#-about-project">📜 About Project</a>
    <span> · </span>
      <a href="#-usage">👨‍💻 Usage</a>
  </h3>
</div>

---

## 📜 About Project

> _The aim of this project is to make you code a function that returns a line, read from a file descriptor._

	🚀 TLDR: This task is crucial to understand for a future programmer, since much of the 
		 time is based on manipulating files for data management and persistence.
		 This project consists of coding a function that returns one line at a time 
		 from a text file.
   
> [!NOTE]  
> Because of 42 School norm requirements:
> * Each function can't have more than 25 lines of code.
> * All variables are declared and aligned at the top of each function.
> * Project should be created just with allowed functions otherwise it's cheating.

## 👨‍💻 Usage
### Requirements

The function is written in C language and thus needs the **gcc compiler** and some standard **C libraries** to run.

### Instructions
**1. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```
and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```
