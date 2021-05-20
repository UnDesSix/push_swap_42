# Makefile
Makefile a the root allowed you to compile the libft, the chercker and the push_swap.

So you can run:
```bash
make libft
make checker
make push_swap
```
Or simply:
```bash
make
```

## What's push_swap?
This project involves sorting data on a stack, with a limited set of instructions,
and the smallest number of moves. To make this happen, you will have to manipulate
various sorting algorithms and choose the most appropriate solution(s) for
optimized data sorting.

## What's checker?
The checker will get as an argument the stack a formatted as a list of integers.
The checker will then wait and read instructions on the standard input, each
instruction will be followed by ’\n’. Once all the instructions have been read
checker will execute them on the stack received as an argument.


*THE PART BELOW IS NOT THE RESULT OF MY WORK
It comes from tharchen's github\n*
# A tester for Push_swap@42 - To see what's going on
This tester shows the performance of your push_swap program.

* [What's push_swap tester?](#whats-push_swap_tester)
* [How do I run this tester?](#how-do-I-run-this-tester)
* [Contribution](#contribution)


```

## How do I run this tester?

```bash
bash push_swap_tester/tester.sh [path-to-push-swap-dir] [stack-size 0R range] [nb_of_tests]
```
### for example:
the following command will perform 100 testss with a stack of 100 integers
```bash
bash push_swap_tester/tester.sh ../push_swap 100 100
```

the following command will perform 100 tests with a stack of 100 integers, then 100 tests with a stack of 101 integers and then 100 tests with a stack of 102 integers
```bash
bash push_swap_tester/tester.sh ../push_swap 100-102 100
```

