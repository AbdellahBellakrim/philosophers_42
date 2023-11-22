# Philosopher Threads and Mutexes Project

## Introduction

Welcome to the Philosopher Threads and Mutexes Project! This project explores the implementation of a simulation where philosophers sit at a round table, eat spaghetti, and engage in various activities using threads and mutexes in the C programming language.

## Table of Contents

- [Introduction](#introduction)
- [Common Instructions](#common-instructions)
- [Overview](#overview)
- [Global Rules](#global-rules)
- [Mandatory Part](#mandatory-part)
- [Bonus Part](#bonus-part)

## Common Instructions

- The project is written in C.
- Adherence to the Norm is mandatory.
- Functions should not quit unexpectedly, and memory must be properly managed.
- Makefile should compile with specific flags and rules.
- Global variables are forbidden.
- Encouraged to create test programs for self-evaluation.
- Submission is via a Git repository.

## Overview

The project simulates philosophers sitting at a round table, alternating between eating, thinking, and sleeping. The goal is to implement a program that prevents philosophers from starving while avoiding data races and adhering to specified rules.

## Mandatory Part

- Program name: `philo`
- Arguments: `number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]`
- External functions: `memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock`
- Libft not authorized.

## Bonus Part

- Program name: `philo_bonus`
- Arguments and external functions same as the mandatory part.
- Additional external functions: `fork, kill, exit, waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink`
- Libft not authorized.
- Bonus part evaluated only if mandatory part is perfect.

## Difference Between Mandatory and Bonus Parts

### Mandatory Part

The mandatory part focuses on implementing the core functionality of the philosopher simulation using threads and mutexes. Key features of the mandatory part include:

- Each philosopher is implemented as a thread.
- Forks are placed between pairs of philosophers, and their states are protected by mutexes.
- The simulation stops if a philosopher dies or, if specified, when all philosophers have eaten a certain number of times.

### Bonus Part

The bonus part builds upon the mandatory part and introduces additional challenges and features. Noteworthy differences in the bonus part include:

- All forks are placed in the middle of the table and are represented by a semaphore.
- Philosophers are implemented as processes, and the main process does not act as a philosopher.
- Additional external functions such as `fork`, `kill`, `exit`, `waitpid`, `sem_open`, `sem_close`, `sem_post`, `sem_wait`, `sem_unlink` are utilized.
- The bonus part is only evaluated if the mandatory part is perfect, meaning it has been implemented without any malfunctions.

The bonus part aims to demonstrate a deeper understanding of concurrency and process management in a more complex scenario. It is an opportunity to showcase advanced skills beyond the mandatory requirements.



Feel free to explore the project, run test programs, and submit your work to the assigned Git repository. Happy coding!
