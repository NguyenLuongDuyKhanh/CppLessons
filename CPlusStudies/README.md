Using && (double ampersand) to run commands simultaneously
In case if you want that the second job/command needs to wait for the first job/command to finish, use the && between the commands. So in that way if any error occurs while the sentence is being executed it will stop.

```
    command1 && command2
    command1; command2
```

The ; token just separates commands, so it will run the second command regardless of whether or not the first one succeeds.