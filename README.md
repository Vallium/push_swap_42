push_swap
============
[![Build Status](https://travis-ci.org/Vallium/push_swap_42.svg)](https://travis-ci.org/Vallium/push_swap_42)

Man
--------
*Synopsis :*
* ./push_swap [-achv]... [numbers]...

*Options :*
* achv

*Description :*

`./ft_ls -a`
* Print final details.

`./ft_ls -c`
* Set colors on.

`./ft_ls -h`
* Print help.

`./ft_ls -v`
* Verbose.

Game rules
----------
- The game consists of 2 stacks named A and B.

- Initially B is empty and contains a number of positive or negative numbers (No duplicates).

- The goal is to sort A in crescent order.

- To do this, one has only the following:

`SA`
* Swap A - swaps the two first elements on top of the stack A. (Does not matter if there are only one or none).

`SB`
* Swap B - swaps the two first elements on top of the stack B. (Does not matter if there are only one or none).

`SS`
* SA and SB simultaneously.

`PA`
* Push A - take the first element at the top of B and puts it on A. (Does not matter if B is empty).

`PB`
* Push B - take the first element at the top of A and puts it on B. (Does not matter if A is empty).

`RA`
* Rotate A - shifts one position all the elements of the pile. (Upwards, the first item becomes the last).

`RB`
* Rotate B - shifts one position all the elements of the pile. (Upwards, the first item becomes the last).

`RR`
* RA and RB simultaneously.

`RRA`
* Reverse Rotate A (Down, the last element becomes the first).

`RRB`
* Reverse Rotate B (Down, the last element becomes the first).

`RRR`
* RRA and RRB simultaneously.