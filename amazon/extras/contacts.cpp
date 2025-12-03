// https://www.hackerrank.com/challenges/contacts/problem

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

class TrieNode {
public:
  int count = 0;
  std::unordered_map<char, TrieNode*> children;
  TrieNode() {}
};

class Trie {
public:
  TrieNode* root;

  Trie() {
    root = new TrieNode(); // dummy root for other children to attach to
  }

  void add(std::string word) {
    TrieNode* node = root;
    for (const char& letter : word) {
      if (!node->children.count(letter)) {
        node->children[letter] = new TrieNode();
      }
      node = node->children[letter];
      node->count++;
    }
  }

  int findChildren(std::string word) {
    TrieNode* node = root;
    for (const char& letter : word) {
      if (!node->children.count(letter))
        return 0;
      node = node->children[letter];
    }

    return node->count;
  }
};

std::vector<int> contacts(std::vector<std::vector<std::string>> queries) {
  Trie* trie = new Trie();
  std::vector<int> matches;

  for (const auto& op : queries) {
    if (op[0] == "add") {
      trie->add(op[1]);
    } else {
      matches.push_back(trie->findChildren(op[1]));
    }
  }

  return matches;
}