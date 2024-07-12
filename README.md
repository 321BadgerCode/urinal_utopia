# Urinal Utopia

## Description

This program takes in input of 0's (empty urinals) and 1's (occupied urinals) and calculates the ideal urinal to go to.

## Criteria

- Pick the closest urinal to the door that is not currently occupied and has the least number of neighbors that are currently occupied.
- Urinals by the wall with an empty neighbor are preferred over a spot with 2 empty neighbors.
- A wall spot with an occupied neighbor is preferred over a spot with 1 empty neighbor.

## Usage

```sh
g++ ./main.cpp && ./a.out <urinals> # or ./a.exe <urinals> for Windows
```
