Common Use Cases:
Cleanup: Deleting temporary files or closing resources before a script exits due to an error or user interruption. 
Graceful Termination: Performing necessary operations before exiting a script when a SIGINT or SIGTERM is received. 
Error Handling: Executing specific actions when a command fails and the ERR signal is triggered (when set -e is enabled). 
Custom Behavior: Defining unique responses to various signals to enhance script robustness and user experience. 

