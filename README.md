# Dining Philosophers Problem

## Overview
This repository contains the implementation of the Dining Philosophers Problem, a classic synchronization problem in computer science. The problem involves a group of philosophers sitting at a dining table, each thinking and eating. The challenge is to design a solution that avoids deadlock and ensures that the philosophers can share resources (in this case, forks) without conflicts.

## Repository Structure

- **philo**: Implementation using mutex and threads.
- **philo_bonus**: Implementation using semaphores and processes.

## Dijkstra's Solution
The solution to the Dining Philosophers Problem in this repository is based on Dijkstra's algorithm. It employs mutual exclusion mechanisms to ensure that philosophers can pick up and release forks without conflicts, preventing deadlock.

## Program Usage
The program takes the following command-line arguments:

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>
```

- `number_of_philosophers`: The number of philosophers at the dining table.
- `time_to_die`: The maximum time a philosopher can live without eating.
- `time_to_eat`: The time it takes for a philosopher to finish eating.
- `time_to_sleep`: The time a philosopher spends sleeping.

## Repository Link
[42_philosophers](https://github.com/yacoub-harkati/42_philosophers)

## Building and Running
To build and run the program, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/yacoub-harkati/42_philosophers.git
   cd 42_philosophers
   ```

2. Navigate to the desired implementation (philo or philo_bonus):
   ```bash
   cd philo  # or cd philo_bonus
   ```

3. Build the executable:
   ```bash
   make
   ```

4. Run the program with the required command-line arguments, as explained above.

## Notes
- Philosophers will die if they do not start eating within the specified time limit.
- The repository provides two implementations: one using mutex and threads (`philo` folder) and another using semaphores and processes (`philo_bonus` folder).

Feel free to explore the code, experiment with different parameters, and contribute to further improvements or optimizations. If you encounter any issues or have suggestions, please open an issue on the GitHub repository.