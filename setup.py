import os

topics = [
    "Arrays and Hashing",
    "Binary Search",
    "Linked List",
    "Recursion and Backtracking",
    "Stacks/Queues",
    "Heaps",
    "Trees (BT + BST)",
    "Graphs",
    "Dynamic Programming",
    "Tries",
    "String"
]

for topic in topics:
    safe_name = topic.replace(" ", "_").replace("/", "_").replace("(", "").replace(")", "").replace("+", "plus")
    os.makedirs(safe_name, exist_ok=True)

print("Folders created successfully.")
