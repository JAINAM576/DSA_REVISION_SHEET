# 📚 Trie Implementation 

## 🔧 Structure: `Node`

* Each `Node` contains:

  * An array of **26 pointers** (`links[26]`) for `'a'` to `'z'`.
  * A `flag` indicating **end of word** (true if word ends here).
* Helpful methods:

  * `isContainKey(char c)` → checks if the character exists.
  * `addKey(char ch, Node* refNode)` → adds new node link.
  * `nextNode(char c)` → moves to the next node.

---

## 🌳 Class: `Trie`

* Starts with a single root node.
* Contains 3 main functions:

  * `insert(word)`
  * `search(word)`
  * `startsWith(prefix)`

---

## ✍️ Insertion Logic

1. **Start at root**.
2. Loop over each character of the word:

   * If the current node doesn't have the character → create a new node using `addKey`.
   * Move to the next node using `nextNode`.
3. After loop ends → set `flag = true` to **mark end of word**.

---

## 🔍 Search Logic

1. **Start at root**.
2. Loop through each character:

   * If character doesn't exist → return `false`.
   * Move to the next node.
3. After loop, check if the current node's `flag` is `true`:

   * If yes → word exists in the Trie.
   * If no → it's just a **prefix**, not a full word → return `false`.

---

## 🔎 StartsWith Logic

1. Very similar to search.
2. Loop through each character:

   * If character is missing → return `false`.
   * Move to next node.
3. If loop completes → return `true`, because **prefix exists**, no need to check `flag`.

---

## 💡 Quick Summary Table

| Operation      | What it Does                                | When Does it Return True?              |
| -------------- | ------------------------------------------- | -------------------------------------- |
| `insert()`     | Adds a word into Trie                       | Always inserts by creating path        |
| `search()`     | Checks if complete word exists              | Only if `flag == true` at the end      |
| `startsWith()` | Checks if any word starts with given prefix | If full prefix path exists in the Trie |

---

✅ **Tip to Remember**:

> Think of Trie like a **tree of characters**:
> Each path is a word. `insert` grows the tree 🌱, `search` verifies the complete fruit 🍎, and `startsWith` just checks if the stem exists 🌿.

