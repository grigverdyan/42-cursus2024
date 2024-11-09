<a name="readme-top"></a>
<div align="center">

  <!-- Project Name -->
  <h1>Push-Swap</h1>

  <!-- Short Description -->
  <p align="center">
	  <b>42 Yerevan Push-Swap</b><br>
  </p>

  <h3>
      <a href="#-about-project">📜 About Project</a>
    <span> · </span>
      <a href="#-operations-list">📑 Operations List</a>
    <span> · </span>
	  <a href="#-algorithm">🧮 Algorithm</a>
    <span> · </span>
	  <a href="#-bonus-part">🌟 Bonus Part</a>
    <span> · </span>
      <a href="#-usage">👨‍💻 Usage</a>
  </h3>
</div>

---

## 📜 About Project

* This project will make you sort data on a stack, with a limited set of operations, using the lowest possible number of actions.

* The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted.  
You have at your disposal a set of int values, 2 stacks and a set of operations to manipulate both stacks.  

* The goal is to write a program in C called push_swap which calculates and displays on the standard output the operations, that sort the integers received as arguments.

* The learning objectives of this project are rigor, use of C and use of basic algorithms. Especially looking at the complexity of these basic algorithms.

* You are allowed to use the following functions: malloc, free, exit, write, read.

For detailed information, refer to the [**subject of this project**](en.subject.pdf).

	🚀 TLDR: Given a set of integers, sort it using a predefined set of operations using 
 		 two stacks. The operations list is defined below. This program outputs 
	         push_swap operations that sorts the input integers.

> [!NOTE]  
> Because of 42 School norm requirements:
> * Each function can't have more then 25 lines of code.
> * All variables are declared and aligned at the top of each function.
> * Project should be created just with allowed functions otherwise it's cheating.

## 📑 Operations List

The program is only allowed to work with two stacks: stack A and stack B. \
All the numbers are initially added to stack A, and stack B is empty.

The possible operations are:

| Code  | Operations                          | Action                                                 |
|:-----:|:-----------------------------------:|:------------------------------------------------------:|
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

## 🧮 Algorithm

I use `Butterfly` algorithm for sorting. Here is a short description:

* First, need to generate a chunk number.
* After I iterate through stack A look for a number, whose index is smaller than the counter (numbers count in stack B).
* If I find that number, I do `pb` and `rb`.
* If no, I check if the number is smaller than counter + chunk, and do only `pb`.
* Repeat these operations until stack A becomes empty.
* In stack B we will have numbers in order like 90-degree rotated butterfly 🦋.
* After that, I will iterate through stack B and push the maximum index in stack A (i.e. `pa`) until stack B becomes empty.
* After these operations, stack A becomes sorted.

The chunk number must be different depending on the numbers count. \
So need to experiment with chunk number to achieve the best operations count. \
For more information about the algorithm see <a href="https://www.youtube.com/watch?v=GA9aKzl86nA&ab_channel=Edu_events_mow"><b>this video</b></a>. \
Also, you can visualize algorithm work by this <a href="https://push-swap-visualizer.vercel.app/"><b>visualizer</b></a>.

## 🌟 Bonus Part
* The Bonus exercise was to write a program called 'checker' that can read the operations from stdin and perform them on a stack of numbers.
* Checker will display 'OK' when the given operations will sort the numbers in ascending order. Otherwise it displays 'KO'.
* In case of an error (f.ex. operations doesn't exist) it displays 'Error'.

## 👨‍💻 Usage
### Requirements

The program is written in C language and thus needs the **gcc compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile the program, run:

```shell
$ cd path_to/push_swap && make
```

To compile the checker, run:

```shell
$ cd path_to/push_swap && make bonus
```

**2. How to run the program**

Run the executable together with the set of numbers separated by a space:
```shell
./push_swap 5 7 10 4 6 8 9 2 1 3
```

To run the checker on push_swap, use the pipe:
```shell
ARG="5 7 10 4 6 8 9 2 1 3"; ./push_swap $ARG | ./checker $ARG
```

Use `clean` to delete all object files, `fclean` to remove executable and all object files, and `re` to recompile the program:
```shell
make clean / make fclean / make re
```
