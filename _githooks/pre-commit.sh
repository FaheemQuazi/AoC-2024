#!/bin/sh

source .venv/bin/activate
pip3 freeze > requirements.txt
git add requirements.txt
deactivate
