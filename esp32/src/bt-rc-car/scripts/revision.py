import subprocess
from pathlib import Path

def get_commit_hash():
    return subprocess.check_output(["git", "log",  "-1", "--format=%h"]).strip().decode("UTF-8")

def get_revision_str():
    with Path("revision.txt").open() as revFile:
        return revFile.read().strip()

def create_revision_str():
    revision = get_revision_str()
    commit_hash = get_commit_hash()
    return f"{revision}-{commit_hash}"
