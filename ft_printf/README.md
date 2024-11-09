<a name="readme-top"></a>
<div align="center">

  <!-- Project Name -->
  <h1>Ft_Printf</h1>

  <!-- Short Description -->
  <p align="center">
	  <b>42 Yerevan Printf</b><br>
  </p>

  <h3>
      <a href="#-about-project">📜 About Project</a>
    <span> · </span>
      <a href="#-supported-specifiers">📑 Supported Specifiers</a>
    <span> · </span>
      <a href="#-usage">👨‍💻 Usage</a>
  </h3>
</div>

---

## 📜 About Project

> _This project is pretty straight-forward. You will implement your own printf. You will mainly learn how to use variadic arguments._

For detailed information, refer to the [**subject of this project**](en.subject.pdf).

	🚀 TLDR: This project consists of coding a library that contains a simplified version 
 		 of the printf function.

> [!NOTE]  
> Because of 42 School norm requirements:
> * Each function can't have more than 25 lines of code.
> * All variables are declared and aligned at the top of each function.
> * Project should be created just with allowed functions otherwise it's cheating.

## 📑 Supported Specifiers

These specifiers are supported by my printf implementation.

| Specifier  | Short Description                                         |
|:----------:|:---------------------------------------------------------:|
| %c         | Print a single character.                                 |
| %s         | Print a string of characters.                             |
| %p         | The void * pointer argument is printed in hexadecimal.    |
| %d         | Print a decimal (base 10) number.                         |
| %i         | Print an integer in base 10.                              |
| %u         | Print an unsigned decimal (base 10) number.               |
| %x         | Print a number in hexadecimal (base 16), with lowercase.  |
| %X         | Print a number in hexadecimal (base 16), with uppercase.  |
| %%         | Print a percent sign.                                     |

## 👨‍💻 Usage
### Requirements

The library is written in C language and thus needs the **gcc compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the library**

To compile the library, run:

```shell
$ cd path_to/printf && make
```

**2. Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "ft_printf.h"
```
and, when compiling your code, add the required flags:

```shell
-lftprintf -L path_to/libftprintf.a -I path_to/ft_printf.h
```
