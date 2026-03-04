#!/usr/bin/env python3
# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileNotice: Part of the FreeCAD project.

################################################################################
#                                                                              #
#   FreeCAD is free software: you can redistribute it and/or modify            #
#   it under the terms of the GNU Lesser General Public License as             #
#   published by the Free Software Foundation, either version 2.1              #
#   of the License, or (at your option) any later version.                     #
#                                                                              #
#   FreeCAD is distributed in the hope that it will be useful,                 #
#   but WITHOUT ANY WARRANTY; without even the implied warranty                #
#   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                    #
#   See the GNU Lesser General Public License for more details.                #
#                                                                              #
#   You should have received a copy of the GNU Lesser General Public           #
#   License along with FreeCAD. If not, see https://www.gnu.org/licenses       #
#                                                                              #
################################################################################

import argparse
import sys
import os
import re
import logging
from typing import Tuple
from utils import (
    run_command,
    init_environment,
    append_file,
    emit_problem_matchers,
    write_file,
    add_common_arguments,
)

DEFAULT_LINE_LENGTH_LIMIT = 100


def parse_black_output(output: str) -> Tuple[int, int]:
    """
    Parse Black output to determine how many files would be reformatted and how many would fail.

    Returns:
        A tuple (black_reformats, black_fails).
    """
    black_reformats = 0
    black_fails = 0

    # Look for a pattern like: "X files would be reformatted"
    reformats_matches = re.findall(r"(\d+)(?=\s+fil.+ would be reformatted)", output)
    if reformats_matches:
        black_reformats = int(reformats_matches[0])

    # Look for a pattern like: "Y files would fail to reformat"
    fails_matches = re.findall(r"(\d+)(?=\s+fil.+ would fail to reformat)", output)
    if fails_matches:
        black_fails = int(fails_matches[0])

    return black_reformats, black_fails


def generate_markdown_report(black_reformats: int, black_fails: int, log_file: str) -> str:
    """Generate a Markdown report section based on Black results and log file."""
    report_lines = []
    if black_reformats > 0 or black_fails > 0:
        report_lines.append(
            f"<details><summary>:pencil2: Black would reformat {black_reformats} file(s)"
            f" and {black_fails} file(s) would fail to reformat</summary>"
        )
    else:
        report_lines.append(
            "<details><summary>:heavy_check_mark: Black would reformat no file</summary>"
        )
    report_lines.append("")
    report_lines.append("````")
    with open(log_file, "r", encoding="utf-8") as f:
        report_lines.append(f.read())
    report_lines.append("````")
    report_lines.append("</details>")
    report_lines.append("")
    return "\n".join(report_lines)


def main():
    parser = argparse.ArgumentParser(
        description="Run Black in check mode on Python files and append a Markdown report."
    )
    add_common_arguments(parser)
    args = parser.parse_args()
    init_environment(args)

    logging.info("Installing black (if needed)...")
    run_command(["pipx", "install", "-q", "black"], check=True)

    cmd = [
        "black",
        "--line-length",
        str(DEFAULT_LINE_LENGTH_LIMIT),
        "--check",
    ] + args.files.split()
    stdout, stderr, exit_code = run_command(cmd, check=False)
    output = stdout + "\n" + stderr

    log_file = os.path.join(args.log_dir, "black.log")
    write_file(log_file, output)
    emit_problem_matchers(log_file, "blackWarning.json", "black-warning")

    black_reformats, black_fails = parse_black_output(output)
    logging.info(
        "Found %s files would be reformatted and %s files would fail to reformat",
        black_reformats,
        black_fails,
    )

    report = generate_markdown_report(black_reformats, black_fails, log_file)
    append_file(args.report_file, report)

    sys.exit(0 if exit_code == 0 else 1)


if __name__ == "__main__":
    main()
