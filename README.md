# Philosophers

![Project Logo](/path/to/logo.png)

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)

## Introduction
Welcome to the Philosophers project! This project aims to explore the concepts of concurrency and synchronization by simulating the classic dining philosophers problem.

## Challenges and Functionality

### Challenges
1. **Concurrency**: Managing concurrent access to shared resources is a key challenge. Each philosopher is represented by a separate thread, competing for access to forks (mutexes). Ensuring fair and synchronized access is crucial to prevent deadlocks and resource contention.

2. **Deadlock Prevention**: Preventing deadlock is essential. Deadlock occurs when each philosopher holds one fork and waits indefinitely for the other. A solution is needed to ensure all philosophers can eventually acquire necessary resources without getting stuck.

3. **Resource Allocation**: Managing the allocation of forks to philosophers is another challenge. The simulation should allow each philosopher to access two forks simultaneously without conflicts or inconsistencies.

### Functionality
1. **Simulation**: The Philosophers project simulates the dining philosophers problem using separate threads for each philosopher. Each thread represents an individual philosopher and executes behaviors like thinking, eating, or waiting for forks.

2. **Synchronization Techniques**: Various synchronization techniques are implemented to ensure proper resource sharing and prevent conflicts. For example, mutexes represent forks, allowing only one philosopher to hold a fork at a time, ensuring exclusive access.

3. **Visualization**: The simulation provides visualizations, allowing users to observe philosopher behavior and fork allocation. This aids understanding of concurrency and synchronization.

4. **Customization**: Users can customize the simulation by adjusting the number of philosophers (up to 200), time to die, time to eat, time to sleep, and the *minimum number of meals each philosopher should eat before the simulation stops.

	*The number of meals is a option, meaning that if no philosopher die the simulation will be endless.

## Features
- Simulates the dining philosophers problem
- Implements various synchronization techniques (e.g., mutex, semaphore)
- Provides visualizations of the simulation
- Allows customization of the number of philosophers and their behaviors

## Installation
To install and run the Philosophers project, follow these steps:

1. Clone the repository:
	```bash
	git clone https://github.com/ebmarque/Philosophers.git
	```

2. Navigate to the project directory:
	```bash
	cd Philosophers
	```

3. Build the project:
	```bash
	make
	```

4. Run the simulation:
	```bash
	./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
	```


## Usage
Here are some examples of how to use the Philosophers project:

- Run the simulation with 4 philosophers, each philosopher has a time to die of 410 milliseconds, eating for 210 milliseconds, and sleeping for 210 milliseconds:
	```bash
	./philo 4 410 210 210
	```

- Run the simulation with 5 philosophers, each philosopher has a time to die of 500 milliseconds, eating for 150 milliseconds, and sleeping for 150 milliseconds, with a minimum of 3 meals per philosopher:
	```bash
	./philo 5 500 150 150 3
	```

Please note that the program takes the following arguments:

- `number_of_philosophers`: The number of philosophers and also the number of forks.
- `time_to_die` (in milliseconds): If a philosopher doesn't start eating `time_to_die` milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
- `time_to_eat` (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
- `time_to_sleep` (in milliseconds): The time a philosopher will spend sleeping.
- `number_of_times_each_philosopher_must_eat` (optional argument): If all philosophers have eaten at least `number_of_times_each_philosopher_must_eat` times, the simulation will stop.

In the second example, the simulation will run until all philosophers have eaten at least 3 meals. If there is enough time and resources for each philosopher, and no minimum number of meals is specified, the simulation will be endless. However, if the last time a philosopher ate exceeds the time to die, the philosopher will die and the simulation will stop.

For more information on the available command-line arguments, refer to the project documentation.

## Contributing
Contributions to the Philosophers project are welcome! If you would like to contribute, please follow these guidelines:
- Fork the repository
- Create a new branch
- Make your changes
- Submit a pull request
