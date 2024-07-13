#!/usr/bin/python3
"""
This script reads lines from standard input (stdin) and computes metrics based on HTTP status codes and file sizes.

Functions:
    parse_line(line): Parses a single line of input to extract and update the file size and status code count.
    print_stats(): Prints the current metrics including total file size and counts of each status code.

The script handles the following HTTP status codes:
    - 200
    - 301
    - 400
    - 401
    - 403
    - 404
    - 405
    - 500

The script prints the accumulated file size and the count of each status code every 10 lines and upon termination (including via a keyboard interrupt).

Usage:
    The script reads from stdin, so it can be used in a pipeline or with input redirection. For example:
    $ cat log.txt | ./script.py
"""

import sys

if __name__ == '__main__':
    status_code = {"200": 0,
                   "301": 0,
                   "400": 0,
                   "401": 0,
                   "403": 0,
                   "404": 0,
                   "405": 0,
                   "500": 0}
    count = 1
    file_size = 0

    def parse_line(line):
        """Parses a single line of input to extract the file size and status code.
        
        Args:
            line (str): A line of input from stdin.
            
        Returns:
            int: The file size from the line, or 0 if parsing fails.
        """
        try:
            parsed_line = line.split()
            st_code = parsed_line[-2]
            if st_code in status_code.keys():
                status_code[st_code] += 1
            print(parsed_line[-1])
            return int(parsed_line[-1])
        except Exception:
            return 0

    def print_stats():
        """Prints the accumulated metrics including file size and status code counts."""
        print(f"File size: {file_size}")
        for key in sorted(status_code.keys()):
            if status_code[key]:
                print(f"{key}: {status_code[key]}")

    try:
        for line in sys.stdin:
            file_size += parse_line(line)
            if count % 10 == 0:
                print_stats()
            count += 1
    except KeyboardInterrupt:
        print_stats()
        raise

    print_stats()
