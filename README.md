# Labyrinth robot project 

## Small protocol to command the arduino

The raspberry send an integer to the arduino to change the robot direction.
If no value provided, the arduino go forward.

| Int | Meaning                      |
| --- | ---------------------------- |
| -1  | Initialize the communication |
| 0   | Stop                         |
| 1   | Turn right                   |
| 2   | Go forward                   |
| 3   | Turn left                    |
| 4   | Go backward                  |
| 5   | Wait                         |


## Raspberry script
For the next commands, go to the **raspberry** directory.

### Install dependencies 

You first need to install dependencies as follow:
```
pip install -r requirements.txt
```

>Note: using a python virtual environement is a good method.

### Run 

Run the labyrinth script:
```
python raspberry_script.py
```

## Arduino script (with FSM)
For the next commands, go to the **arduino** directory.

### Install dependencies 

You first need to install the following dependencies in the arduino program :
- Adafruit Motor Shield V2 Library (version 1.0.10)
- TimerOne (by Jess Tane, Jérôme Despatis...)

## Second Arduino script

Due to Serial port problems, we had to make a second Arduino Script. This script is not optimized but works.
