import os
import sys
from pathlib import Path

_here = os.path.dirname(os.path.realpath(__file__))

MFILE_TEMPLATE = os.path.join(_here, "mfile.template")
LIBH_TEMPLATE = os.path.join(_here, "libh.template")

def setup_day(day):
    
    dirs = [
        f"days/day{day}",
        f"days/day{day}/inputs",
        f"days/day{day}/obj"
    ]
    
    for d in dirs:
        os.makedirs(d, exist_ok=True)

    paths = [
        f"days/day{day}/inputs/example1.txt",
        f"days/day{day}/inputs/day{day}.txt",
        f"days/day{day}/day{day}.cpp",
        f"days/day{day}/day{day}lib.cpp"
    ]
    for p in paths:
        Path(p).touch(exist_ok=True)
    
    with open(MFILE_TEMPLATE, 'rt') as f:
        mfile_doc = f.read().format(day=f"day{day}")
    with open(f"days/day{day}/Makefile", 'wt') as f:
        f.write(mfile_doc)

    with open(LIBH_TEMPLATE, 'rt') as f:
        libc_doc = f.read().format(macro_name=f"day{day}lib_h".upper())
    with open(f"days/day{day}/day{day}lib.h", 'wt') as f:
        f.write(libc_doc)

if __name__ == "__main__":

    if len(sys.argv) < 2:
        raise ValueError("Must provide a day number.")
        sys.exit()
    day = int(sys.argv[1])
    setup_day(day)