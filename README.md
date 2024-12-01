# Advent of Code 2024

My quick-and-dirty solutions for [AoC 2024](https://adventofcode.com/2024/about). Each folder represents a day on the calendar.

To run any of the code, I recommend creating a virtual environment in the root directory of this repository and running `pip install -r requirements.txt`.

To automate things somewhat, I've also added a pre-commit script that will automatically update `requirements.txt` based on the packages I end up using throughout the event. See `_githooks/pre-commit.sh` for details.

## Day 1s

Pretty bog-standard sorting + search problems. Python and numpy make it easy, almost too easy... Took a brute force "just loop it" approach for part 1, and used the Python list built-in `.count` method to my advantage in part 2.
