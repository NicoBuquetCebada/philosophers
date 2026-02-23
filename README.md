*This project has been created as part of the 42 curriculum by nbuquet-.*

# Philosophers

## Description

Philosophers is a concurrency project from the 42 curriculum based on the classical *Dining Philosophers Problem*. The goal of this project is to understand and implement multithreading concepts in C, focusing on thread creation, synchronization mechanisms, and race condition prevention.

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

### Classical References

* Edsger W. Dijkstra — The Dining Philosophers Problem (1965)
* POSIX Threads Programming (pthreads documentation)
* man pthread_create
* man pthread_mutex_init
* man gettimeofday

Additional conceptual references:

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

## Technical Decisions

* POSIX threads (`pthread`) were used for philosopher threads.
* Mutexes were used to protect shared resources (forks and logs).
* A monitoring mechanism ensures philosophers do not exceed `time_to_die`.
* Precise timing functions were implemented to improve sleep accuracy.
* No global variables were used, in accordance with project constraints.

---

This project was developed following the 42 Norm and subject requirements.
