#!/usr/bin/python3
"""
0-count Module

Defines the function `count_words` to query the Reddit API, counting the
occurrences of specified keywords in the titles of hot posts within a subreddit.
Results are printed in descending frequency and alphabetically for ties.
"""

import requests


def count_words(subreddit, word_list, after=None, word_count={}):
    headers = {
        'User-Agent': 'python:holberton.count_words:v1.0 (by /u/holberton_school)'}
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    params = {'after': after, 'limit': 100}

    # Initialize the word_count dictionary on the first call
    if not word_count:
        word_count = {word.lower(): 0 for word in word_list}

    # Make the API request
    response = requests.get(
        url,
        headers=headers,
        params=params,
        allow_redirects=False)

    # Check for a valid response
    if response.status_code != 200:
        return

    # Parse response
    data = response.json().get('data')
    posts = data.get('children', [])
    after = data.get('after')

    # Count keywords in the titles of all hot articles
    for post in posts:
        title = post['data']['title'].lower().split()
        for word in word_count:
            word_count[word] += title.count(word)

    # Recursively call count_words if there's another page
    if after is not None:
        count_words(subreddit, word_list, after, word_count)
    else:
        # Sort and print the results
        sorted_words = sorted(word_count.items(),
                              key=lambda kv: (-kv[1], kv[0]))
        for word, count in sorted_words:
            if count > 0:
                print(f"{word}: {count}")
