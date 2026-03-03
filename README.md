*This project has been created as part of the 42 curriculum by nbuquet-.*

# Philosophers

## Description

Philosophers is a project from the 42 curriculum based on the classical *Dining Philosophers Problem*. The goal of this project is to understand and implement multithreading concepts in C, focusing on thread creation, synchronization mechanisms, and race condition prevention.

In this simulation, a number of philosophers sit around a table. Each philosopher alternates between eating, sleeping, and thinking. To eat, a philosopher must hold two forks (shared resources). The challenge is to coordinate access to these shared resources using mutexes while ensuring:

* No philosopher dies from starvation.
* No data races occur.
* No undefined behavior happens.
* Output logs remain synchronized and correctly formatted.
* The simulation stops under the required conditions.

This project emphasizes proper thread management, precise timing control, and safe synchronization using POSIX threads (pthreads).

---

## Instructions

### Compilation

Use the provided Makefile:

```bash
make
```

The project is compiled using:

* `cc`
* `-Wall -Wextra -Werror`

To clean object files:

```bash
make clean
```

To remove object files and executable:

```bash
make fclean
```

To recompile:

```bash
make re
```

---

### Execution

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

#### Arguments

* `number_of_philosophers`: Number of philosophers (and forks).
* `time_to_die`: Time in milliseconds before a philosopher dies if they do not eat.
* `time_to_eat`: Time in milliseconds a philosopher spends eating.
* `time_to_sleep`: Time in milliseconds a philosopher spends sleeping.
* `number_of_times_each_philosopher_must_eat` (optional): Simulation stops if all philosophers eat at least this number of times.

#### Example

```bash
./philo 5 800 200 200 7
```

---

## Resources

### References

* [Edsger W. Dijkstra — The Dining Philosophers Problem (Wikipedia)](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
* [man7 pthreads documentation](https://man7.org/linux/man-pages/man7/pthreads.7.html)
* [Understanding Threads in C (Medium)](https://medium.com/@akshatarhabib/understanding-threads-in-c-c9feb5e9372a)

Conceptual references:

* Concurrency and Multithreading fundamentals
* Race Conditions and Mutual Exclusion
* Deadlock prevention strategies

---

### Use of Artificial Intelligence

Artificial Intelligence tools were used in this project for:

* Conceptual clarification of threading and synchronization mechanisms.
* Reviewing race condition scenarios.
* Understanding deadlock prevention strategies.
* Drafting and structuring documentation.

All generated content was reviewed, tested, and fully understood before being integrated into the project. No code was copied without comprehension. The implementation reflects personal understanding of multithreading concepts and synchronization techniques.

---

This project was developed following the 42 Norm and subject requirements.
