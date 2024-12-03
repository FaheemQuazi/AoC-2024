# Advent of Code 2024

My quick-and-dirty solutions for [AoC 2024](https://adventofcode.com/2024/about). Each folder represents a day on the calendar.

For any Python code in this repo, I recommend creating and enabling a virtual environment in the root directory of this repository and running `pip install -r requirements.txt` to set up dependencies.

Any C code is written in standard C, and should support being compiled with your preferred compiler: `$CC file.c -o file.o`.

To automate things somewhat, I've also added a pre-commit script that will automatically update `requirements.txt` based on the packages I end up using throughout the event. See `_githooks/pre-commit.sh` for details.

## Day 1

Pretty bog-standard sorting + search problems. Python and numpy make it easy, almost too easy... Took a brute force "just loop it" approach for part 1, and used the Python list built-in `.count` method to my advantage in part 2.

## Day 2

This one was fun. I thought writing this out the part one code in 20 minutes was decent, but apparently people are solving in less than a minute - feels like AI but then historically the times are not much slower. Tt seems I'm just slow... lol. 

Once again, the code ended up being pretty brute-forced in the moment. Part 2 I feel needs some improvement, since I _really_ brute-forced the answer by checking all possible element removals. I did try and initially only remove the first element that I found was wrong, but that would only check one instance of an incorrect answer - perhaps checking neighboring elements _relative_ to the first failed element would have been a little more optimal. 

## Day 3

What a bad day to choose C as the solution language! This would likely have been made 10x easier if I had used a language with better regex support (like JS). Pretty happy with my seek-scan logic though, and given no libraries and exactly 50 lines of code, I think it turned out pretty reasonable.

As part of this solution, I'm adding a few vscode niceties to assist with quickly running C code.