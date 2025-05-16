import os
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
import time

class DirectoryCreationHandler(FileSystemEventHandler):
    def on_created(self, event):
        # Check if a new directory is created
        if event.is_directory:
            solution_path = os.path.join(event.src_path, "solution.cpp")
            if not os.path.exists(solution_path):
                with open(solution_path, 'w') as f:
                    pass  # create empty file
                print(f"[+] Created: {solution_path}")

if __name__ == "__main__":
    path_to_watch = os.getcwd()  # current directory
    print(f"Watching directory: {path_to_watch}")

    event_handler = DirectoryCreationHandler()
    observer = Observer()
    observer.schedule(event_handler, path=path_to_watch, recursive=True)
    observer.start()

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()
    observer.join()
