<h1 align=center>
	<b>push_swap</b>
</h1>


<p align="center">
	This project aims to introduce students to sorting algorithms and computational complexity. The task involves sorting a given list of numbers using only two stacks and a limited number of movements.
</p>

---
<div align="center">
	<h2>Final Score</h2>
	<img src="./assets/final_score.png" alt="Final Score" width="250"/> <br>
	<h4>Completed + Bonus</h4>
	<img src="./assets/badge_push_swap.png" alt="Bonus" width="150"/>
</div>

## Table of Contents
1. [Project Overview](#project-overview)
2. [Rules](#rules)
3. [Usage](#usage)
4. [Algorithm](#algorithm)
5. [Implementation](#implementation)
6. [Bonus](#bonus)
7. [Additional Resources](#additional-resources)

---

## Project Overview

The Push swap project is a very simple and a highly straightforward algorithm project:
data must be sorted.
You have at your disposal a set of integer values, 2 stacks, and a set of instructions
to manipulate both stacks.
Your goal? Write a program in C called push_swap which calculates and displays
on the standard output the smallest program, made of Push swap language instructions,
that sorts the integers received as arguments.
Easy?
We’ll see...


-	### Mandatory Part
	1. Sorting the given list of numbers correctly.
	2. Achieving the sort with the least number of movements.

-	### Bonus
	1. Creating a checker program that takes the movements as input and verify if the movements correctly sort the given list.


---
## Rules

You have two stacks named `A` and `B`:
- `Stack A` contains a random number of unique negative and/or positive integers.
- `Stack B` is initially empty.

The goal is to sort `Stack A` in ascending order using the following operations:

- `sa` (swap a): Swap the top two elements of `Stack A`. Do nothing if there's only one or no elements.
- `sb` (swap b): Swap the top two elements of `Stack B`. Do nothing if there's only one or no elements.
- `ss`: Perform `sa` and `sb` simultaneously.
- `pa` (push a): Move the top element from `Stack B` to the top of `Stack A`. Do nothing if `Stack B` is empty.
- `pb` (push b): Move the top element from `Stack A` to the top of `Stack B`. Do nothing if `Stack A` is empty.
- `ra` (rotate a): Shift all elements of `Stack A` up by one. The top element becomes the last one.
- `rb` (rotate b): Shift all elements of `Stack B` up by one. The top element becomes the last one.
- `rr`: Perform `ra` and `rb` simultaneously.
- `rra` (reverse rotate a): Shift all elements of `Stack A` down by one. The last element becomes the first one.
- `rrb` (reverse rotate b): Shift all elements of `Stack B` down by one. The last element becomes the first one.
- `rrr`: Perform `rra` and `rrb` simultaneously.

---

## Usage

To run the program:
```sh
$ ./push_swap <list_of_integers>
```
The list can be passed as individual numbers or a single string of space-separated numbers:
```sh
$ ./push_swap 1 3 5 4 2 0 -4
```
or
```sh
$ ./push_swap "1 3 5 4 2 0 -4"
```

The program outputs the sequence of operations to sort the stack:
```sh
$ ./push_swap 0 4 2
pb
ra
pa
```

If there is an error (e.g., invalid input), it outputs:
```sh
$ ./push_swap 0 4 two
Error
```

If no parameters are passed, it does nothing and returns to the prompt
```sh
$ ./push_swap
$
```

## Implementation


### Step 1: Initialization

### Overview

The initialization process is responsible for converting the command-line arguments into a doubly-linked list (`stack_a`) of integers. This involves:

- **Parsing Input Arguments:** Handles both single string input (e.g., `./push_swap "3 2 1"`) and multiple parameters (e.g., `./push_swap "3" "2" "1"`).

- **Validating and Converting Tokens:** Each string token is validated and converted into an integer, ensuring no invalid numbers or overflow/underflow conditions.

- **Populating the List:** The integers are inserted into `stack_a`, with checks for errors such as duplicates and memory allocation failures.

This process ensures that the input is correctly transformed into a usable format for further operations.

### 1. Input Argument Handling

#### 1.1 Single Argument vs. Multiple Arguments

The program can be called with either one argument (which is a string containing several numbers) or with multiple arguments (each a separate number). The code handles this with the following snippet:

```c
if (argc == 2)
    *argv = split((*argv)[1], ' ');
else
    *argv = *argv + 1;
```

#### How `*argv = *argv + 1;` Works

When the program is called with multiple arguments, the array `argv` might look like this:

```
argv:
  Index 0: "./push_swap"   <-- Program name
  Index 1: "8"
  Index 2: "3"
  Index 3: "7"
  Index 4: "2"
```

Using the statement:
```c
*argv = *argv + 1;
```
shifts the pointer to skip the program name. After this adjustment, the effective `argv` becomes:

```
argv:
  Index 0: "8"
  Index 1: "3"
  Index 2: "7"
  Index 3: "2"
```

This way, the code can iterate directly over the numbers without having to worry about the program name.

#### Single Argument Case

For a call like:
```bash
./push_swap "8 3 7 2"
```
The original `argv` is:
```
argv:
  Index 0: "./push_swap"
  Index 1: "8 3 7 2"
```

Since `argc == 2`, the code executes:
```c
*argv = split((*argv)[1], ' ');
```
which transforms the second element into an array:
```
argv (after splitting):
  Index 0: "8"
  Index 1: "3"
  Index 2: "7"
  Index 3: "2"
```

---

### 2. Error Handling for Input

After adjusting or splitting the input, the code checks for a valid array:

```c
if (!*argv)
    *error = true;
```

**Explanation:**  
If the token array is NULL (i.e., if splitting fails), the error flag is set and initialization is aborted.


## 3. Conversion and List Population

### 3.1 Converting Strings to Integers with `ft_atoi`

The `ft_atoi` function converts a string to an integer while checking for errors. Here’s a simplified version with its error checks:

```c
static bool str_isdigit(const char *str, bool *error)
{
    int index = 0;
    if (str[index] == '-' || str[index] == '+')
        index++;
    while (str[index])
    {
        if (str[index] < '0' || str[index] > '9')
        {
            *error = true;
            return false;
        }
        index++;
    }
    if (index == 0 || (index == 1 && (str[0] == '-' || str[0] == '+')))
    {
        *error = true;
        return false;
    }
    return true;
}

int ft_atoi(const char *str, bool *error)
{
    int index = 0;
    long result = 0;
    int sign = 1;
    
    if (*error || !str_isdigit(str, error))
        return 0;
    while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
        index++;
    if (str[index] == '-' || str[index] == '+')
        if (str[index++] == '-')
            sign = -1;
    while (str[index] >= '0' && str[index] <= '9')
    {
        result = result * 10 + (str[index++] - '0');
        if (result * sign > INT_MAX || result * sign < INT_MIN)
        {
            *error = true;
            return 0;
        }
    }
    return result * sign;
}
```

**How It Checks for Errors:**

- **Non-Digit Characters:**  
  The helper function `str_isdigit` ensures that each character in the string is a digit (or a valid sign). If not, it sets `*error` to true.
  
- **Empty or Incomplete Input:**  
  If the string is empty or only contains a sign without digits, `*error` is also set.
  
- **Overflow/Underflow:**  
  While converting the string to an integer, if the value exceeds `INT_MAX` or falls below `INT_MIN`, `*error` is set.

### 3.2 Inserting Integers into the List with `push_back`

After conversion, the integer is added to `stack_a` using `push_back`:

```c
bool push_back(t_stack **stack, int value)
{
    t_stack *last = *stack;
    t_stack *new;

    // Check for duplicate at the head of the list.
    if (last && last->value == value)
        return true;
    while (last && last->next)
    {
        // Check for duplicates in the rest of the list.
        if (value == last->value || last->next->value == value)
            return true;
        last = last->next;
    }
    new = create_node(value);
    if (!new)
        return true; // Memory allocation failure.
    if (!last)
        *stack = new;
    else
    {
        last->next = new;
        new->prev = last;
    }
    return false;
}
```

**How It Checks for Errors:**

- **Duplicate Detection:**  
  It iterates through the list and checks if the value already exists. If a duplicate is found, the function returns `true` (indicating an error).

- **Memory Allocation:**  
  If `create_node` fails (returns `NULL`), it signals an error by returning `true`.


## 4. Complete Initialization Process

The following function ties all these parts together:

```c
static void initialization(t_data *data, int argc, char ***argv, bool *error)
{
    int index = 0;
    int current_value;

    *error = false;

    // Handle input: split if one argument, or adjust pointer for multiple arguments.
    if (argc == 2)
        *argv = split((*argv)[1], ' ');
    else
        *argv = *argv + 1;

    // Check if the resulting array is valid.
    if (!*argv)
    {
        *error = true;
        return;
    }

    // Process each token: convert to integer and add to the list.
    while (*argv && (*argv)[index] && !*error)
    {
        current_value = ft_atoi((*argv)[index], error);
        if (*error || push_back(&data->stack_a, current_value))
            *error = true;
        data->size_of_a++;
        index++;
    }
}
```

### Building the List with Example

**Example Command:**

```bash
./push_swap "8 3 7 2"
```

**Step 1: Splitting the String**

```
Initial string: "8 3 7 2"
After split:
   +-----+-----+-----+-----+
   | "8" | "3" | "7" | "2" |
   +-----+-----+-----+-----+
```

**Step 2: Converting and Inserting into the List**

For each token:
- `"8"` is converted to `8` via `ft_atoi`.
- `push_back` adds `8` to the list.
- The process repeats for `"3"`, `"7"`, and `"2"`.

**Visual Representation of `stack_a`:**

```
stack_a:
   +-----+     +-----+     +-----+     +-----+
   |  8  | <-> |  3  | <-> |  7  | <-> |  2  |
   +-----+     +-----+     +-----+     +-----+
```

Each node is a structure containing:
- The integer value.
- Pointers to the previous and next nodes.


## 5. Final Outcome and Error Handling

After initialization:

- **Success:**  
  If there are no errors (i.e., valid integers, no duplicates), `stack_a` is fully populated and `data->size_of_a` reflects the number of nodes.

- **Error:**  
  If any conversion or insertion error occurs, the error flag is set. This leads to proper cleanup and an error message during program termination.

### Main Function Flow

```c
int main(int argc, char **argv)
{
    bool error;
    t_data data = {0};

    if (argc < 2)
        return (0);
    initialization(&data, argc, &argv, &error);
    if (!error && data.size_of_a > 1)
    {
        if (data.checker)
            checker(&data);
        else
            sort(&data);
    }
    return (end_process(&data, argc, argv, error));
}
```

**Explanation:**
- The main function calls `initialization()` to process the input.
- It then checks for errors before proceeding to sorting or checking.
- Finally, `end_process()` cleans up any allocated resources and returns an appropriate exit code.

---

## Additional Resources

- [Laís Arena's tester](https://github.com/laisarena/push_swap_tester)
- [Ilya Kashnitskiy's graphical interface](https://github.com/elijahkash/push_swap_gui)
- [Paula Hemsi's push_swap simulator](https://phemsi-a.itch.io/push-swap)
- [Emmanuel Ruaud's push_swap visualizer](https://github.com/o-reo/push_swap_visualizer)

---
