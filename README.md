# Labyrinth robot project 

## Table of contents

- [Labyrinth robot project](#labyrinth-robot-project)
  - [Table of contents](#table-of-contents)
  - [Small protocol to command the arduino](#small-protocol-to-command-the-arduino)
  - [Raspberry script](#raspberry-script)
    - [Install dependencies](#install-dependencies)
    - [Run](#run)
  - [Arduino script (with FSM)](#arduino-script-with-fsm)
    - [Install dependencies](#install-dependencies-1)
  - [Second Arduino script](#second-arduino-script)
  - [PCB](#PCB)


## Small protocol to command the arduino

The raspberry send an integer to the arduino to change the robot direction.

| Int | Meaning                      |
| --- | ---------------------------- |
| -1  | Initialize the communication |
| 0   | Stop                         |
| 1   | Turn right                   |
| 2   | Go forward                   |
| 3   | Turn left                    |
| 4   | Turn backward                |
| 5   | Wait                         |


## Raspberry script
For the next commands, go to the [raspberry] (./raspberry) directory.

### Install dependencies 

You first need to install dependencies as follow:
```
pip install -r requirements.txt
```

>Note: using a python virtual environement is a good method.

### Run 

Run the labyrinth script:
```
python main.py
```

## Arduino script (with FSM)
For the next commands, go to the [arduino](/arduino/v1/projetRobot) directory.

### Install dependencies 

You first need to install the following dependencies in the arduino program :
- Adafruit Motor Shield V2 Library (version 1.0.10)
- TimerOne (by Jess Tane, Jérôme Despatis...)

## Second Arduino script

Due to problems with the serial communication, we had to make a second Arduino Script : [Second Arduino script](/arduino/v2).
This script is not optimized but is working.

## PCB

The files used to make the PCB can be found in [PCB](/PCB) directory.
