# Advent of Code 2024

My quick-and-dirty solutions for [AoC 2024](https://adventofcode.com/2024/about). Each folder represents a day on the calendar.

## Running the Solutions

_Python_: I recommend creating and enabling a virtual environment in the root directory of this repository and running `pip install -r requirements.txt` to set up dependencies.

_C_: Solutions using C should only depend on the standard library, and support being compiled with your preferred compiler: `$CC file.c -o file.o`. I use the configured build task within VSCode or [vtr](https://github.com/NathanVaughn/vscode-task-runner).

### Extras

To automate things somewhat, I've also added a pre-commit script that will automatically update `requirements.txt` based on the packages I end up using throughout the event. See `_githooks/pre-commit.sh` for how that works.

## Dev Log

Personal thoughts and comments based on the outcome of my solution. Ordered in reverse chronological order!

### Day 4

A friend of mine committed to doing all the solutions in C... now I have no choice `:)`. I've previously tinkered with word search problems, but this was the first time I really put that search skill to the test. At first I wrote three different functions to search (horizontal, vertical, diagonal), but then I realized it might be easier to have a single function do every direction. That's ultimately what I landed on, albeit with a bit of tinkering and an unnecessarily long function call...

Part 2 was a little easier. Was essentially convolution but with text instead of an image. I just needed to figure out what all the enumerations of the `X-MAS` pattern was and... bam!


### Day 3

What a bad day to choose C as the solution language! This would likely have been made 10x easier if I had used a language with better regex support (like JS). Pretty happy with my seek-scan logic though, and given no libraries and exactly 50 lines of code, I think it turned out pretty reasonable.

As part of this solution, I'm adding a few vscode niceties to assist with quickly running C code.

### Day 2

This one was fun. I thought writing this out the part one code in 20 minutes was decent, but apparently people are solving in less than a minute - thought it may be AI but historically the times are just as fast. I think I've got a lot of room to grow... lol.

Once again, the code ended up being pretty brute-forced in the moment. Part 2 I feel needs some improvement, since I _really_ brute-forced the answer by checking all possible element removals. I did try and initially only remove the first element that I found was wrong, but that would only check one instance of an incorrect answer - perhaps checking neighboring elements _relative_ to the first failed element would have been a little more optimal. 

### Day 1

Pretty bog-standard sorting + search problems. Python and numpy make it easy, almost too easy... Took a brute force "just loop it" approach for part 1, and used the Python list built-in `.count` method to my advantage in part 2.

